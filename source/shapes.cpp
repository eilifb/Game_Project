#include "shapes.h"
#include "utils.h"
#include <iostream>

Polygon::Polygon(std::vector<Vec> input) : vertices(input){
	add_edges();
	add_axises();
}

Polygon::Polygon(Vec input){
	vertices.push_back(input);
}

Polygon::~Polygon(){}


void Polygon::add_edges(){
	for (int i = 0; i < vertices.size() - 1; i++) {
		edges.push_back(vertices.at(i + 1) - vertices.at(i));
	}
	edges.push_back(vertices.front() - vertices.back());
}

void Polygon::print_vertices(){
	std::cout << "printing vertices: ";
	for (Vec v : vertices) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}

void Polygon::print_edges(){
	std::cout << "printing edges: ";
	for (Vec v : edges) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}

void Polygon::print_axises(){
	std::cout << "printing axises: ";
	for (Vec v : axises) {
		std::cout << v << ", ";
	}
	std::cout << std::endl;
}


void Polygon::add_axises(){
	for (Vec v : edges) {
		if (v.len() == 0) {
			std::cerr << "vector length 0 when trying to compute axis in polygon, something must have gone wrong" << std::endl;
			print_vertices();
		}
		axises.push_back(v.normal() * 1/v.len());
	}
}

void Polygon::complete() {
	add_edges();
	add_axises();
}

void Polygon::move(Vec v) {
	for (int i = 0; i < vertices.size(); i++) {
		vertices.at(i) = vertices.at(i) + v;
		edges.at(i) = edges.at(i) + v;
	}
}

void  Polygon::operator+(const Vec& other) {
	vertices.push_back(other);
}


std::ostream& operator<<(std::ostream& out, const Polygon& p){
	out << "( ";
	for (Vec v : p.vertices) {
		out << v << ", ";
	}
	out << " )";
	return out;
}
