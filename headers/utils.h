#ifndef UTILS_H
#define UTILS_H

#define println(x) std::cout << x << std::endl;
#define valuex(x) ", " << #x << ": " << x



#include <ostream>

/// <summary>
/// A basic 2d vector class.
/// </summary>
class Vec {
public:
	/// <summary>
	/// the first and second number contained in the vector. Used by the other classes
	/// to represent a point in 2D space, a line, a vector or just two numbers.
	/// </summary>
	float x, y;

	/// <summary>
	/// Creates a vector (0,0)
	/// </summary>
	Vec(): x(0),y(0) {}

	/// <summary>
	/// Creates a vector with the given values.
	/// </summary>
	Vec(float x, float y) : x(x),y(y){}

	/// <summary>
	/// <example> <c> Vec(1,5) + Vec(2,12) returns Vec(3,17) </c> </example>
	/// </summary>
	Vec operator+(const Vec& other) {
		return Vec(this->x + other.x, this->y + other.y);
	}

	/// <summary>
	/// <example> <c> Vec(1,12) - Vec(2,5) returns Vec(-1,7) </c> </example>
	/// </summary>
	Vec operator-(const Vec& other) {
		return Vec(this->x - other.x, this->y - other.y);
	}

	/// <summary>
	/// <example> <c> -Vec(1,5) returns Vec(-1,-5) </c> </example>
	/// </summary>
	Vec operator-() {
		return Vec(-this->x,-this->y);
	}

	/// <summary>
	/// <example> <c> Vec(6,10) / Vec(2,10) returns Vec(3,1) </c> </example>
	/// </summary>
	Vec operator/ (float other) {
		return Vec(this->x / other, this->y / other);
	}

	/// <summary>
	/// <example> <c> Vec(1,5) * Vec(2,1.5) = Vec(2,7.5) </c> </example>
	/// </summary>
	Vec operator*(float other) {
		return Vec(this->x * other, this->y * other);
	}

	/// <summary>
	/// Checks if the members contained match in value.
	/// </summary>
	/// <returns> <c>true</c> if <c>this->x == other.x && this->y == other.y , false</c> if otherwise.</returns>
	bool operator==(const Vec& other) {
		if (this->x == other.x && this->y == other.y) {
			return true;
		}
		return false;
	}

	/// <summary>
	/// Checks if the members contained do not match in value.
	/// </summary>
	/// <returns> <c>false</c> if <c>this->x == other.x && this->y == other.y , true</c> if otherwise.</returns>
	bool operator!=(const Vec& other) {
		if (this->x == other.x && this->y == other.y) {
			return false;
		}
		return true;
	}

	/// <summary>
	/// Computes the vector dot product of this vector and another vector.
	/// </summary>
	/// <a href="https://en.wikipedia.org/wiki/Euclidean_vector#Dot_product">dot product</a>
	/// <param name="other">the second vector</param>
	/// <returns>the dot product as a float</returns>
	/// <example> <c> Vec(1,3).dot(Vec(2,2) returns 8 </c> </example>
	float dot(Vec& other) {
		return (this->x * other.x) + (this->y * other.y);
	}

	/// <summary>
	/// Computes the left normal of this vector (<c> Vec(x,y) returns Vec(-y,x)</c>
	/// </summary>
	/// <returns>A left normal in the form of Vec</returns>
	Vec normal() {
		return Vec(-this->y, this->x);
	}

	/// <summary>
	/// Computes the Vecs length when it is used to represent a vector.
	/// </summary>
	/// <a href="https://en.wikipedia.org/wiki/Euclidean_vector#Length">vector length</a>
	/// <returns>the length as a float</returns>
	float len() {
		return std::sqrt((x * x) + (y * y));
	}

	/// <summary>
	/// Computes the unit vector of the vector.
	/// </summary>
	/// <a href="https://en.wikipedia.org/wiki/Unit_vector">unit vector</a>
	/// <returns> the unit vector as a Vec</returns>
	Vec unit() {
		float len = this->len();
		return Vec(x / len, y / len);
	}

	/// <summary>
	/// Returns a stream representation(?) of a Vec.
	/// </summary>
	/// <example> <c> std::cout << p << std::endl; </c> </example>
	friend std::ostream& operator<< (std::ostream& strm, const Vec& input) {
		return strm << "(" << input.x << "," << input.y << ")";
	}
};





#endif