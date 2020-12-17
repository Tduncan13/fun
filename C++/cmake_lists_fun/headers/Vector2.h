#pragma once

struct Vector2 {
	float x, y;
public:
	Vector2(float _x, float _y);
	Vector2 Add(const Vector2& other) const; 
	Vector2 operator+(const Vector2& other) const; 
	Vector2 Multiply(const Vector2& other) const; 
	Vector2 operator*(const Vector2& other) const;
	};
