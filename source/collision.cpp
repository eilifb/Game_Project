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
	/* (see vector_projection_math for a more readable notation.
	* The projecton of vector a onto vector b is defined as ((a.b)/b.b))*b where . denotes the dot product of a and b.
	* This can also be written as (a.b')*b' where ' denotes the normalization of b (a vector with the length of 1 in the direction of b).
	* I chose to normalize (turn a vector into a unit vector) the Polygon.axises we are projecting onto we can use simpler computation
	* (a.b')*b = ((ax*bx + ay*by)*bx,(ax*bx + ay*by)*by) 
	*/
	Vec proj = axis*axis.dot(p.vertices.at(0));
	Vec temp;
	
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