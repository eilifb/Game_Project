#ifndef COLLISION_H
#define COLLISION_H

class Vec;
class Polygon;

class Collision {
public:
	Vec check_collision(Polygon a, Polygon b);
};



#endif // !COLLISION_H
