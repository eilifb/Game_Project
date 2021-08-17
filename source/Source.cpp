#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <SDL.h>
#include <chrono>
#include <vector>
#include "shapes.h"
#include "collision.h"
#include "test_suite.h"
#include "utils.h"

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

	Vec a(10, 10);
	a.len();
	a.len();
	
	test::test_collision();
	test::test_collision_time();
	//std::cout << -0.2f << " : " << std::hexfloat << -0.2f << std::endl;
	double n = -0x1.9999800000000p-3;



	return 0;
}