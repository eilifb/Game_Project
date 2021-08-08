#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "shapes.h"
#include "collision.h"

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

	Collision col;

	Polygon box1(Vec(3, 8));
	box1 + Vec(7, 8);
	box1 + Vec(7, 5);
	box1 + Vec(3, 5);

	box1.add_edges();
	box1.add_axises();

	Polygon box2(Vec(9, 8));
	box2 + Vec(10, 8);
	box2 + Vec(10, 5);
	box2 + Vec(9, 5);

	box2.add_edges();
	box2.add_axises();

	Polygon box3(Vec(6, 9));
	box3 + Vec(8, 9);
	box3 + Vec(8, 7);
	box3 + Vec(6, 7);

	box3.add_edges();
	box3.add_axises();


	std::cout << box1 << std::endl;

	col.check_collision(box1, box2);
	col.check_collision(box1, box2);


	return 0;
}