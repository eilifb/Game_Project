#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "shapes.h"
#include "collision.h"

void test_vector() {
	Vec a, b;
	a.x = 3;
	a.y = 4;
	b.x = 3;
	b.y = 1;

	a = a + b;
	a = -a;
	std::cout << "vector: " << a;
}


int main(int argc, char* argv[]) {
	printf("setting up\n");

	Collision col;

	Polygon box1(Vec(3, 8));
	box1 + Vec(7, 8);
	box1 + Vec(7, 5);
	box1 + Vec(3, 5);

	box1.add_edges();
	box1.add_axises();

	Polygon box2(Vec(9, 8));
	box2 + Vec(10, 8);
	box2 + Vec(10, 5);
	box2 + Vec(9, 5);

	box2.add_edges();
	box2.add_axises();

	Polygon box3(Vec(6, 9));
	box3 + Vec(8, 9);
	box3 + Vec(8, 7);
	box3 + Vec(6, 7);

	box3.add_edges();
	box3.add_axises();

	Polygon tri1(Vec(5, 4));
	tri1 + Vec(8, 6);
	tri1 + Vec(8, 4);
	
	tri1.add_edges();
	tri1.add_axises();


	//col.check_collision(box1, box3);
	col.check_collision(box1, tri1);

	Polygon bb(Vec(0, 0));
	bb + Vec(5, 0);
	bb.add_edges();
	bb.add_axises();

	Vec v1(5, 0);
	v1 = v1 * (1 / v1.len());
	/*box1.print_vertices();
	box1.print_edges();
	box1.print_axises();*/

	Vec a(-0.5547, 0.8320);
	Vec b(5, 4);
	Vec c(8, 4);
	Vec d(8, 6);

	Vec res1 = a * a.dot(b);
	Vec res2 = a * a.dot(c);
	//println("\n\n\n" << res1 << ", " << res2);
	return 0;
}