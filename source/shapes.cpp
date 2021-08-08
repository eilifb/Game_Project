#include "shapes.h"

Polygon::Polygon(std::vector<Vec>& input) : vertices(input){}

Polygon::Polygon(Vec input)
{
}

Polygon::~Polygon()
{
}

std::vector<Vec> Polygon::get_vertices(){
	return this->vertices;
}

std::vector<Vec> Polygon::get_edges(){
	return this->edges;
}

std::vector<Vec> Polygon::get_normals(){
	return this->normals;
}

void Polygon::add_edges(){
	for (int i = 0; i < vertices.size() - 1; i++) {
		edges.push_back(vertices.at(i + 1) - vertices.at(i));
	}
	edges.push_back(vertices.front() - vertices.back());
}	

void Polygon::add_normals(){
	for (int i = 0; i < vertices.size(); i++) {

	}
}
