#define CATCH_CONFIG_RUNNER
#include "./lib/catch.hpp"
#include <iostream>

int main(int argc, const char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	system("pause");
	return result;
}