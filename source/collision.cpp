#include "collision.h"
#include "shapes.h"
#include <iostream>

void Collision::check_collision(Polygon a, Polygon b){
	//std::vector<std::vector<double>> dotsA; // dots[normal][edge]
	//std::vector<std::vector<double>> dotsB;
	Vec p1;
	Vec p2;
	double overlap = DBL_MAX;
	double overlap_check = 0;
	Vec mtv();
	for(Vec axis : a.axises) {
		p1 = this->project(a, axis);
		p2 = this->project(b, axis);
		if ((p1.y < p2.x) || (p2.y < p1.x)) {
			std::cout << "no overlap! " << std::endl;
			return;
		}
		overlap_check = 
	}
	for (Vec axis : b.axises) {
		p1 = this->project(a, axis);
		p2 = this->project(b, axis);
		if ((p1.y < p2.x) || (p2.y < p1.x)) {
			std::cout << "no overlap! " << std::endl;
			return;
		}
	}	
	
	std::cout << "overlaps!\n";
	return;
}

Vec Collision::project(Polygon p, Vec axis) {
	double min = axis.dot(p.vertices.at(0));
	double max = min;
	
	for (int i = 1; i < p.vertices.size(); i++) {
		double temp = axis.dot(p.vertices.at(i));

		if (temp < min) {
			min = temp;
		}
		else if (temp > max) {
			max = temp;
		}
	}
	

	//std::cout << "projection of polygon on " << axis << " gave min: " << min << ", max: " << max << std::endl;
	return Vec(min,max);
}