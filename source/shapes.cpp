#include "shapes.h"
#include <iostream>

Polygon::Polygon(std::vector<Vec>& input) : vertices(input){
	this->vertices = input;
	this->add_edges();
	this->add_axises();
}

Polygon::Polygon(Vec input){
	this->vertices.push_back(input);
}

Polygon::~Polygon(){
}


void Polygon::add_edges(){
	for (int i = 0; i < vertices.size() - 1; i++) {
		edges.push_back(vertices.at(i + 1) - vertices.at(i));
	}
	edges.push_back(vertices.front() - vertices.back());
}

void Polygon::print_vertices(){
	std::cout << "printing vertices: ";
	for (Vec v : this->vertices) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}

void Polygon::print_edges(){
	std::cout << "printing edges: ";
	for (Vec v : this->edges) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}

void Polygon::print_axises(){
	std::cout << "printing axises: ";
	for (Vec v : this->axises) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}


void Polygon::add_axises(){
	for (Vec v : edges) {
		if (v.len() == 0) {
			std::cout << "vector length 0, something must have gone wrong" << std::endl;
		}
		axises.push_back(v.normal() * 1/v.len());
	}
}

void  Polygon::operator+(const Vec& other) {
	this->vertices.push_back(other);
}




std::ostream& operator<<(std::ostream& out, const Polygon& p){
	out << "( ";
	for (Vec v : p.axises) {
		out << v << ", ";
	}
	out << " )";
	return out;
}
