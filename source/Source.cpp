#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "utils.h"

int main(int argc, char* argv[]) {
	printf("setting up\n");
	Vec a,b;
	a.x = 3;
	a.y = 4;
	b.x = 3;
	b.y = 1;

	a = a + b;
	a = -a;
	std::cout << "vector: " << a;
	return 0;
}