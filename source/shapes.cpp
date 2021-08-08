#include "shapes.h"

Polygon::Polygon(std::vector<Vec>& input) : vertices(input){
	this->vertices = input;
	this->add_edges();
	this->add_axises();
}

Polygon::Polygon(Vec input){
	this->vertices.push_back(input);
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

std::vector<Vec> Polygon::get_axises(){
	return this->axises;
}

void Polygon::add_edges(){
	for (int i = 0; i < vertices.size() - 1; i++) {
		edges.push_back(vertices.at(i + 1) - vertices.at(i));
	}
	edges.push_back(vertices.front() - vertices.back());
}	

void Polygon::add_axises(){
	for (Vec v : edges) {
		axises.push_back(v.normal());
	}
}

void  Polygon::operator+(const Vec& other) {
	this->vertices.push_back(other);
}

std::ostream& operator<<(std::ostream& out, const Polygon& p){
	out << "( ";
	for (Vec v : p.vertices) {
		out << v << ", ";
	}
	out << " )";
	return out;
}
