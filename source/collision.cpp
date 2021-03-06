#include "collision.h"
#include "utils.h"
#include "shapes.h"
#include <iostream>



Vec Collision::check_collision(Polygon a, Polygon b){
	Vec mtv(FLT_MAX,FLT_MAX);
	Vec mtv_check(0,0);
	
	for (Vec axis : a.axises) {

		float a_max = 0;
		float a_min = FLT_MAX;
		float b_max = 0;
		float b_min = FLT_MAX;

		float test;
		//In this loop we project the first polygon on one of the axises from polygon b. The goal is to find
		//the extreme points of the polygon when its projected down to the axis.
		for (Vec v : a.vertices) {
			test = axis.dot(v);

			if (test > a_max) {
				a_max = test;
			}
			if (test < a_min) {
				a_min = test;
			}
		}
		for (Vec v : b.vertices) {
			test = axis.dot(v);
			if (test > b_max) {
				b_max = test;
			}
			if (test < b_min) {
				b_min = test;
			}
		}
		if (b_min > a_max) {
			return Vec(0,0);
		}
		if (b_max < a_min) {
			return Vec(0,0);
		}

		if (b_min > a_min && b_min < a_max) {
			mtv_check = axis * (a_max - b_min);
		}

		if (b_max > a_min && b_max < a_max) {
			mtv_check = axis * (a_min - b_max);
		}

		if (mtv_check.len() < mtv.len()) {
			mtv = mtv_check;
		}
	}

	for (Vec axis : b.axises) {

		float a_max = 0;
		float a_min = FLT_MAX;
		float b_max = 0;
		float b_min = FLT_MAX;

		float test;
		//In this loop we project the first polygon on one of the axises from polygon b. The goal is to find
		//the extreme points of the polygon when its projected down to the axis.
		for (Vec v : a.vertices) {
			test = axis.dot(v);
			if (test > a_max) {
				a_max = test;
			}
			if (test < a_min) {
				a_min = test;
			}
		}
		for (Vec v : b.vertices) {
			test = axis.dot(v);
			if (test > b_max) {
				b_max = test;
			}
			if (test < b_min) {
				b_min = test;
			}
		}
		if (b_min > a_max) {
			return Vec(0,0);
		}
		if (b_max < a_min) {
			return Vec(0,0);
		}

		if (b_min > a_min && b_min < a_max) {
			mtv_check = axis*(a_max - b_min);
		}

		if (b_max > a_min && b_max < a_max) {
			mtv_check = axis * (a_min - b_max);
		}


		if (mtv_check.len() < mtv.len()) {
			mtv = mtv_check;
		}
	}

	return mtv;
}
	
