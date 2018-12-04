#include "Vector3.h"



Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vector3::Vector3(float _x)
{
	this->x = _x;
	this->y = _x;
	this->z = _x;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3 & other)
{
	Vector3 ret;

	ret.x = x + other.x;
	ret.y = y + other.y;
	ret.z = z + other.z;

	return ret;
}

Vector3 Vector3::operator-(const Vector3 & other)
{
	Vector3 ret;

	ret.x = x - other.x;
	ret.y = y - other.y;
	ret.z = z - other.z;

	return ret;
}

Vector3 Vector3::operator*(const Vector3 & other)
{
	Vector3 ret;

	ret.x = x * other.x;
	ret.y = y * other.y;
	ret.z = z * other.z;

	return ret;
}

Vector3 Vector3::operator*(float _x)
{
	Vector3 ret;

	ret.x = x + _x;
	ret.y = y + _x;
	ret.z = z + _x;

	return ret;
}

bool Vector3::operator==(const Vector3 & other)
{
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

bool Vector3::operator!=(const Vector3 & other)
{
	return !operator==(other);
}

Vector3::~Vector3()
{
}
