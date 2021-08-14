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

	Polygon box1(Vec(5, 8));
	box1 + Vec(10, 8);
	box1 + Vec(10, 4);
	box1 + Vec(5, 4);
	box1.add_edges();
	box1.add_axises();

	Polygon colliding_box_1(Vec(3, 9));
	colliding_box_1 + Vec(8, 9);
	colliding_box_1 + Vec(8, 6);
	colliding_box_1 + Vec(3, 6);
	colliding_box_1.add_edges();
	colliding_box_1.add_axises();

	Polygon colliding_triangle_1(Vec(3.6, 4.9));
	colliding_triangle_1 + Vec(5.2, 4.6);
	colliding_triangle_1 + Vec(3.6, 4.4);
	colliding_triangle_1.add_edges();
	colliding_triangle_1.add_axises();

	Polygon colliding_triangle_2(Vec(8, 3));
	colliding_triangle_2 + Vec(9, 5);
	colliding_triangle_2 + Vec(9, 3);
	colliding_triangle_2.add_edges();
	colliding_triangle_2.add_axises();

	Polygon tri1 = (Vec(6, 10));
	tri1 + Vec(7, 11);
	tri1 + Vec(7, 10);
	tri1.complete();

	Polygon tri2(Vec(11, 6));
	tri2 + Vec(12, 6);
	tri2 + Vec(11, 6);
	tri2.complete();

	Polygon tri3(Vec(8, 1));
	tri3 + Vec(9, 2);
	tri3 + Vec(9, 1);
	tri3.complete();

	Polygon tri4(Vec(1, 4));
	tri4 + Vec(2, 5);
	tri4 + Vec(2, 4);
	tri4.complete();


	//col.check_collision(box1, box3);
	col.check_collision(box1, colliding_box_1);
	col.check_collision(box1, colliding_triangle_1);
	col.check_collision(box1, colliding_triangle_2);

	col.check_collision(box1, tri1);
	col.check_collision(box1, tri2);
	col.check_collision(box1, tri3);
	col.check_collision(box1, tri4);




	return 0;
}