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


int main(int argc, char* argv[]) {
	printf("setting up\n");
	
	test::test_collision();
	test::test_collision_time();


	std::cout << "Exiting..." << std::endl;
	return 0;
}