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
	Vec mtv(DBL_MAX,DBL_MAX);
	Vec mtv_check(0,0);
	/*for(Vec axis : a.axises) {
		p1 = this->project(a, axis);
		p2 = this->project(b, axis);
		
		if ((p1.y < p2.x) || (p2.y < p1.x)) {
			std::cout << "no overlap! " << std::endl;
			break;
		}

		mtv_check = axis*(p1.y - p2.x);
		println("axis " << axis << " gave p1: " << p1 << " and p2: " << p2 << " with overlap " << mtv_check << ", len " << mtv_check.len());

		if (mtv_check.len() < mtv.len()) {
			mtv = mtv_check;
		}
	}*/
	println("done with first loop")
	for (Vec axis : b.axises) {
		p1 = this->project(a, axis);
		p2 = this->project(b, axis);
		if ((p1.y < p2.x) || !(p2.y < p1.x)) {
			std::cout << "no overlap! " << std::endl;
			//break;
		}

		mtv_check = axis * (p2.len() - p1.len());
		println("\naxis " << axis << " gave p1: " << p1.len() << " and p2: " << p2.len() << " with overlap " << mtv_check << ", len " << mtv_check.len());

		if (mtv_check.len() < mtv.len()) {
			mtv = mtv_check;
		}
		break;
	}	
	
	//println("The polygons overlap. MTV is " << mtv << " with a length of " << mtv.len())
	return;
}

Vec Collision::project(Polygon p, Vec axis) {
	/* see vector_projection_math.png for a more readable notation.
	* The projecton of vector a onto vector b is defined as ((a.b)/b.b))*b where . denotes the dot product of a and b.
	* This can also be written as (a.b')*b' where ' denotes the normalization of b (a vector with the length of 1 in the direction of b).
	* I chose to normalize (turn a vector into a unit vector) the Polygon.axises we are projecting onto we can use simpler computation
	* (a.b')*b = ((ax*bx + ay*by)*bx,(ax*bx + ay*by)*by) 
	*/

	//TODO: check if this math can be optimized. E.g do the normalization of axis here, or even compute the normal/axis directly here.
	//Vec proj = axis*axis.dot(p.vertices.at(0));
	Vec proj_start(DBL_MAX, DBL_MAX);
	Vec proj_end(0, 0);
	Vec temp;
	

	/** vector_projection_representation.png for a visual example of the two calls done in the first loop in Collision::check_collision
	* We are projecting the entire polygon onto the axis. In other words we have to check every vertice to find the "extreme points"
	* of the polygon when its projected onto the axis.
	*/
	Vec max(0,0);
	Vec min(0,0);

	for (int i = 0; i < p.vertices.size(); i++) {
		temp = axis*axis.dot(p.vertices.at(i));
		if (temp.len() < proj_start.len()) {
			proj_start = temp;
			min = p.vertices.at(i);
		}
		if (temp.len() > proj_end.len()) {
			proj_end = temp;
			max = p.vertices.at(i);
		}
		//println("point " << p.vertices.at(i) << " gave projection " << temp << " with length " << temp.len());
	}
	Vec res = proj_end - proj_start;
	return proj_end - proj_start;
}
	
