#ifndef SHAPES_H
#define SHAPES_H



#include "utils.h"
#include <vector>

class Vec;

class Box {
	int centre, w, h;
};


class Polygon {

public:
	std::vector<Vec> vertices; //points making up the polygon
	std::vector<Vec> edges; //lines between vertices
	std::vector<Vec> axises; //left normalized normals for the edges of the Polygon

	Polygon(std::vector<Vec>& input);
	Polygon(Vec input);
	~Polygon();

	void  operator+(const Vec& other);

	friend std::ostream& operator<< (std::ostream& out, const Polygon& p);

	void add_edges();
	void add_axises();
	void complete();

	void move(Vec v);
	
	void print_vertices();
	void print_edges();
	void print_axises();



};

#endif // !SHAPES_H


