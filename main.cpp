#include <iostream>

#define CATCH_CONFIG_RUNNER
#include "./lib/catch.hpp"

int main(int argc, const char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	system("pause");
	return result;
}