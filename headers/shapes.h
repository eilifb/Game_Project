///TODO: Rename from shapes to hitbox? Might be more descriptive.

#ifndef SHAPES_H
#define SHAPES_H


#include <vector>
#include <ostream>

class Vec;


/// <summary>
/// Class containing data for a box shape
/// </summary>
class Box {
	int centre, w, h;
};

/// <summary>
/// Class containing data for a convex shape, e.g. location in 2D space
/// </summary>
class Polygon {

public:

	/// <summary>
	/// A list holding the vertices/points making up the polygon
	/// </summary>
	/// <a href="https://devdocs.io/cpp/container/vector">std::vector</a>
	/// <a href="https://devdocs.io/cpp/container/vector">std::vector2</a>	
	std::vector<Vec> vertices;

	/// <summary>
	/// A list holding the edges/lines between the vertices.
	/// </summary>
	/// <a href="https://devdocs.io/cpp/container/vector">std::vector</a>
	std::vector<Vec> edges;

	/// <summary>
	/// A list of the left normals (i.e. <c> Normal of Vec(2,3) = Vec(-3,2) </c>) of the edges. The normals are normalized.
	/// </summary>
	/// <a href="https://devdocs.io/cpp/container/vector">std::vector</a>
	std::vector<Vec> axises;

	/// <summary>
	/// Constructs a polygon with edges and axises from a list of vertices.
	/// </summary>
	/// <param name="vertices"><a href="https://devdocs.io/cpp/container/vector">std::vector</a></param>
	Polygon(std::vector<Vec> vertices);

	/// <summary>
	/// Construts a polygon from a Vec.
	/// </summary>
	/// <param name="input"></param>
	Polygon(Vec input);

	///<summary>Default deconstructor. Currently not implemented./</summary>
	~Polygon();

	/// <summary>
	/// Appends a vertex to the end of vertices. \warning Does not update the list of edges or axises by itself
	/// </summary>
	/// <example>
	/// Take a triangle p( (1, 2), (2, 2), (2,1))
	/// <code> 
	/// p + Vec (1,1);
	/// p.complete();
	/// </code>
	/// Gives us a square p( (1, 2), (2, 2), (2,1), (1,1) )
	void  operator+(const Vec& other);

	/// <summary>
	/// Returns a stream representation(?) of a polygon.
	/// </summary>
	/// <example> <c> std::cout << p << std::endl; </c> </example>
	friend std::ostream& operator<< (std::ostream& out, const Polygon& p);

	/// <summary>
	/// Goes through all of the vertices and creates a edge between the vertex and the next in the list.
	/// </summary>
	void add_edges();

	/// <summary>
	/// Goes through all the edges and creates a normalized normal of the edges. The normals are left normalized.
	/// </summary>
	/// <example> <c> v(x,y) gives normal n(-y/sqrt(x^2+y^2),x/sqrt(x^2+y^2)) </c> </example> 
	void add_axises();

	/// <summary>
	/// Calls add_edges() and add_axises()
	/// </summary>
	void complete();
	
	/// <summary>
	/// Moves the polygon in a direction specified by a Vec
	/// </summary>
	/// <param name="v"> direction the polygon will be moved </param>
	/// <description> Loops through the list of verticies and performs an addition between the verticie and the Vec v.</description>
	/// <example> <code>
	/// Polygon p(Vec(1, 1));
	/// p + Vec(2, 2);
	/// p + Vec(2, 1);
	/// p.move(15,15);
	/// std::cout << p << std::endl; </code>
	/// This will print a polygon positioned at <c> p( (16, 16), (17,17), (17,16)) </c> </example>
	void move(Vec v);
	
	/// <summary>
	/// Prints vertices via iostream to stdout
	/// </summary>
	void print_vertices();
	/// <summary>
	/// Prints edges via iostream to stdout
	/// </summary>
	void print_edges();
	/// <summary>
	/// Prints axises via iostream to stdout
	/// </summary>
	void print_axises();



};

#endif // !SHAPES_H


