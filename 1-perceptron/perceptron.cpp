#include "../lib/catch.hpp"
#include "../lib/inject.hpp"
#include <iostream>

unsigned int Factorial(unsigned int number) {
	return number <= 1 ? number : Factorial(number - 1)*number;
}

class A {
public:
	INJECTABLE(A) {	}
};

class B {
public:

	// Services

	A* a;

	INJECTABLE(B) {
		a = INJECT(A);
	}
};

TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);

	B::Inject();

	B* b2 = MOCK_INJECT(B, {
		MOCK(A, A)
	});
}