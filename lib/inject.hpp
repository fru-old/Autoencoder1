#pragma once

#include <iostream>

class InjectionContext {
public:
	void* (*MockType)(const std::type_info& info);
	
	template<class Name> 
	static Name* BuildType(InjectionContext* context = 0) {
		std::cout << typeid(Name).name();
		Name* mock = 0;
		if (context != 0 && (*context).MockType != 0) {
			mock = (Name*)(*context).MockType(typeid(Name));
			if(mock != 0)std::cout << "!";
		}
		return mock != 0 ? mock : new Name(context);
	}

	static InjectionContext* Initialze(void* (*mock)(const std::type_info& info)) {
		InjectionContext* context = new InjectionContext();
		(*context).MockType = mock;
		return context;
	}
};

#define INJECTABLE(Name)\
	static Name* Inject(InjectionContext* currentInjectionContext = 0) {\
		return InjectionContext::BuildType<Name>(currentInjectionContext);\
	}\
	Name(InjectionContext* currentInjectionContext = 0)

#define INJECT(Name) Name::Inject(currentInjectionContext)

#define MOCK(Old, New) if(info == typeid(Old)) return new New();

#define MOCK_INJECT(Name, Body)  Name::Inject(InjectionContext::Initialze(\
	[](const std::type_info& info) -> void* { Body; return 0; }\
));