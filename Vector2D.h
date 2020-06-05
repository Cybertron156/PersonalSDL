#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(double x, double y);
	Vector2D(float rotation);
	Vector2D(Vector2D& v);
	~Vector2D();
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D& operator-=(const Vector2D& rhs);
	Vector2D& operator*=(const Vector2D& rhs);
	Vector2D& operator*=(double rhs);
	double Magnitude();
	double x_, y_;
};