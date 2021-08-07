#ifndef UTILS_H
#define UTILS_H

#include <ostream>

/// <summary>
/// A basic vector class.
/// </summary>
class Vec {
public:
	int x, y;

	/// <summary>
	/// Creates a vector (0,0)
	/// </summary>
	Vec(): x(0),y(0) {}

	/// <summary>
	/// Creates a vector with 
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	Vec(int x, int y) : x(x),y(y){}

	Vec& operator+(const Vec& other) {
		Vec ret(this->x + other.x, this->y + other.y);
		return ret;
	}

	Vec& operator-(const Vec& other) {
		Vec ret(this->x - other.x, this->y - other.y);
		return ret;
	}

	Vec& operator-() {
		Vec ret(-this->x, -this->y);
		return ret;
	}

	friend std::ostream& operator<< (std::ostream& strm, const Vec& input) {
		return strm << "V(" << input.x << ", " << input.y << ")";
	}
};





#endif