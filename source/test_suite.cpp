#include "test_suite.h"
#include "collision.h"
#include "shapes.h"
#include <iostream>

bool test::test_collision() {
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

	Polygon triangle_1 = (Vec(6, 10));
	triangle_1 + Vec(7, 11);
	triangle_1 + Vec(7, 10);
	triangle_1.complete();

	Polygon triangle_2(Vec(11, 6));
	triangle_2 + Vec(12, 6);
	triangle_2 + Vec(11, 6);
	triangle_2.complete();

	Polygon triangle_3(Vec(8, 1));
	triangle_3 + Vec(9, 2);
	triangle_3 + Vec(9, 1);
	triangle_3.complete();

	Polygon triangle_4(Vec(1, 4));
	triangle_4 + Vec(2, 5);
	triangle_4 + Vec(2, 4);
	triangle_4.complete();


	if (col.check_collision(box1, colliding_box_1) != Vec(0, 2)) {
		std::cout << "Collision test between " << box1 << " and " << colliding_box_1 << " failed. MTV should have been " << Vec(0, 2) << ", but is " << col.check_collision(box1, colliding_box_1) << std::endl;
		return false;
	}
	if (col.check_collision(box1, colliding_triangle_1) != Vec(-2, 0)) {
		std::cout	<< "Collision test between " << box1 << " and " 
					<< colliding_triangle_1 << " failed. MTV should have been " 
					<< Vec(-2, 0) << ", but is " << col.check_collision(box1, colliding_triangle_1) << std::endl;
		return false;
	}
	if (col.check_collision(box1, colliding_triangle_2) != Vec(0,0) ){
		return false;
	}
	
	if (col.check_collision(box1, triangle_1) != Vec(0,0)) {
		return false;
	}
	if (col.check_collision(box1, triangle_2) != Vec(0, 0)) {
		return false;
	}
	if (col.check_collision(box1, triangle_3) != Vec(0, 0)) {
		return false;
	}
	if (col.check_collision(box1, triangle_4) != Vec(0, 0)) {
		return false;
	}

	return true;
}