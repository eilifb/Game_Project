#include "test_suite.h"
#include "utils.h"
#include "shapes.h"
#include "collision.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <vector>


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

	Polygon triangle_1(Vec(6, 10));
	triangle_1 + Vec(7, 11);
	triangle_1 + Vec(7, 10);
	triangle_1.complete();

	Polygon triangle_2(Vec(11, 6));
	triangle_2 + Vec(12, 6);
	triangle_2 + Vec(11, 5);
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

	if (col.check_collision(box1, colliding_triangle_1) != Vec(-0x1.9999800000000p-3, -0)) {
		std::cout	<< "Collision test between " << box1 << " and "
					<< colliding_triangle_1 << " failed. MTV should have been " 
					<< Vec(-0.2, -0) << ", but is " << col.check_collision(box1, colliding_triangle_1) << std::endl;
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

	triangle_1.move(Vec(12, 14));

	Polygon k(Vec(0, 0));

	return true;
}

double test::test_collision_time(){

	Collision col;
	std::vector<Vec> start;
	std::vector<Polygon> polv;



	start.push_back(Vec(10, 10));
	start.push_back(Vec(20, 10));
	start.push_back(Vec(20, 20));
	start.push_back(Vec(10, 20));
	Polygon p1(start);
	polv.push_back(p1);
	

	for (int i = 0; i < 1000; i++) {
		for (int i = 0; i < start.size(); i++) {
			start.at(i) = start.at(i) + Vec(0, 5);
		}
		polv.push_back(Polygon(start));
	}

	auto t1 = std::chrono::high_resolution_clock::now();
	for (Polygon pol1 : polv) {
		for (Polygon pol2 : polv) {
			col.check_collision(pol1, pol2);
		}
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::chrono::duration<double, std::milli> ms_double = t2 - t1;

	std::cout << "execution time was " << ms_double.count() << "ms" << std::endl;
	return ms_double.count();

}
