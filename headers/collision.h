#ifndef COLLISION_H
#define COLLISION_H

class Vec;
class Polygon;


/// <summary>
/// class handling collision checking.
/// TODO: consider changing this to a namespace. No real reason to exist as a class.
/// </summary>
class Collision {
public:
	/// <summary>
	/// Checks if a Polygon is colliding with another Polygon.
	/// </summary>
	/// <param name="a">First Polygon</param>
	/// <param name="b">Second Polygon <see cref="Vec"/></param>
	/// <returns>A Vec that describes how far away Polygon b needs to be moved to seperate the polygons.</returns>
	Vec check_collision(Polygon a, Polygon b);
};



#endif // !COLLISION_H
