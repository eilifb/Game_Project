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
	std::vector<double> time_vec;
	//test::test_collision();
	for (int i = 0; i < 10; i++) {
		time_vec.push_back(test::test_collision_time());
	}

	double tot = 0;
	for (double avg : time_vec) {
		tot += avg;
	}
	tot = tot / time_vec.size();
	println("avg exec time was: " << tot);
	//std::cout << -0.2f << " : " << std::hexfloat << -0.2f << std::endl;
	double n = -0x1.9999800000000p-3;



	return 0;
}