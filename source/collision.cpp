#include "collision.h"
#include "shapes.h"
#include <iostream>

void Collision::check_collision(Polygon a, Polygon b){
	//std::vector<std::vector<double>> dotsA; // dots[normal][edge]
	//std::vector<std::vector<double>> dotsB;

	
	
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

	return Vec(min,max);
}