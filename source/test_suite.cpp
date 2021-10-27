#include "test_suite.h"
#include "utils.h"
#include "shapes.h"
#include "collision.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

test::Timer::Timer(double* input){
	start_point = std::chrono::high_resolution_clock::now();
	time_pointer = input;
}

test::Timer::Timer() {
	start_point = std::chrono::high_resolution_clock::now();
}

test::Timer::~Timer(){
	stop();
}

void test::Timer::reset() {
	start_point = std::chrono::high_resolution_clock::now();
}

double test::Timer::stop(){
	auto end_point = std::chrono::high_resolution_clock::now();

	auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point).time_since_epoch().count();
	auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();

	long long duration = end - start;
	double result = (double)duration;
	*time_pointer = result;
	return result;
}

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

	Polygon colliding_triangle_1(Vec(3.6f, 4.9f));
	colliding_triangle_1 + Vec(5.2f, 4.6f);
	colliding_triangle_1 + Vec(3.6f, 4.4f);
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
					<< Vec(-0.2f, -0.0f) << ", but is " << col.check_collision(box1, colliding_triangle_1) << std::endl;
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

	

	double time_taken;
	std::vector<double> time_vec;
	for (int i = 0; i < 10; i++) {

		{test::Timer time_collision_time(&time_taken);
			for (Polygon pol1 : polv) {
				for (Polygon pol2 : polv) {
					col.check_collision(pol1, pol2);
				}
			}
		}
		std::cout << "execution time was " << time_taken*0.001 << "ms" << std::endl;

		time_vec.push_back(time_taken * 0.001);
	}

	double tot = 0;
	for (double avg : time_vec) {
		tot += avg;
	}
	tot = tot / time_vec.size();
	println("avg exec time was: " << tot << "ms");

	return tot;

}


