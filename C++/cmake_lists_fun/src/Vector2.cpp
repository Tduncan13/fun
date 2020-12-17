#include "Vector2.h"

Vector2::Vector2(float _x, float _y){
	x = _x;
	y = _y;
}; 

Vector2	Vector2::Add(const Vector2& other) const { 
	return Vector2(x + other.x, y + other.y);
}

Vector2	Vector2::operator+(const Vector2& other) const {
		return Add(other);
}

Vector2	Vector2::Multiply(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
}

Vector2	Vector2::operator*(const Vector2& other) const {
		return Multiply(other);
}
