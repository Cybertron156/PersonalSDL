#include "Math.h"
#include "Vector2D.h"
Vector2D::Vector2D() : x_(0), y_(0)
{}
Vector2D::Vector2D(double x, double y) : x_(x), y_(y)
{}
Vector2D::Vector2D(float rotation) : x_(cos(rotation)), y_(sin(rotation))
{}
Vector2D::Vector2D(Vector2D& v) : x_(v.x_), y_(v.y_)
{}
Vector2D::~Vector2D()
{}
Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	x_ -= rhs.x_;
	y_ -= rhs.y_;
	return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& rhs)
{
	x_ *= rhs.x_;
	y_ *= rhs.y_;
	return *this;
}
Vector2D& Vector2D::operator*=(double rhs)
{
	x_ *= rhs;
	y_ *= rhs;
	return *this;
}
double Vector2D::Magnitude()
{
	return sqrt((x_ * x_) + (y_ * y_));
}