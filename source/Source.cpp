#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "shapes.h"
#include "collision.h"
#include "test_suite.h"

void test_vector() {
	Vec a, b;
	a.x = 3;
	a.y = 4;
	b.x = 3;
	b.y = 1;

	a = a + b;
	a = -a;
	std::cout << "vector: " << a;
}


int main(int argc, char* argv[]) {
	printf("setting up\n");

	test::test_collision();




	return 0;
}