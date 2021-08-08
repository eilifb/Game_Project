#ifndef COLLISION_H
#define COLLISION_H

class Vec;
class Polygon;

class Collision {
public:
	void check_collision(Polygon a, Polygon b);
	Vec project(Polygon p, Vec axis);
};



#endif // !COLLISION_H
