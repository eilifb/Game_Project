#include "collision.h"
#include "shapes.h"
#include <iostream>

void Collision::check_collision(Polygon a, Polygon b){
	//std::vector<std::vector<double>> dotsA; // dots[normal][edge]
	//std::vector<std::vector<double>> dotsB;

	for (int i = 0; i < a.normals.size(); i++) {
		Vec p1 = this->project(a, a.normals.at(i));
		Vec p2 = this->project(b, a.normals.at(i));

		if (!(p1.x < p2.y && p1.x > p2.x)) {
			std::cout << "!(p1.x" << p1.x << " < p2.y" << p2.y << " && " << p1.x << "> " << p2.x << ")\n";
			std::cout << "cannot overlap.\n";
			return;
		}
		if (!(p2.x < p1.y && p2.x > p1.x)) {
			std::cout << "!(" << p2.x << " < " << p1.y << " && " << p2.x << "> " << p1.x << ")\n";
			std::cout << "cannot overlap.\n";
			return;
		}
	}

	for (int i = 0; i < b.normals.size(); i++) {
		Vec p1 = this->project(a, a.normals.at(i));
		Vec p2 = this->project(b, a.normals.at(i));

		if (!(p1.x < p2.y && p1.x > p2.x)) {
			std::cout << "!(" << p1.x << " < " << p2.y << " && " << p1.x << "> " << p2.x << ")\n";
			std::cout << "cannot overlap.\n";
			return;
		}
		if (!(p2.x < p1.y && p2.x > p1.x)) {
			std::cout << "!(" << p2.x << " < " << p1.y << " && " << p2.x << "> " << p1.x << ")\n";
			std::cout << "cannot overlap.\n";
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

	return Vec(min,max);
}