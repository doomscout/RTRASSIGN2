
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define GL_GLEXT_PROTOTYPES
#include "shaders.h"
#include "Point3f.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>

// Accessors

GLfloat Point3f::getX() const
{
	return _x;
}

GLfloat Point3f::getY() const
{
	return _y;
}

GLfloat Point3f::getZ() const
{
	return _z;
}

// Mutators

void Point3f::setX(GLfloat x)
{
	_x = x;
}

void Point3f::setY(GLfloat y)
{
	_y = y;
}

void Point3f::setZ(GLfloat z)
{
	_z = z;
}

//Constructor

Point3f::Point3f()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Point3f::Point3f(GLfloat x, GLfloat y, GLfloat z)
{
	_x = x;
	_y = y;
	_z = z;
}

//return reference to the lvalue
Point3f& Point3f::operator =(const Point3f &a)
{		_x = a.getX();
		_y = a.getY();
		_z = a.getZ();
		return *this;
}	

//Check for equality/not equality from other value of Class

bool Point3f::operator ==(const Point3f &a) const
{
	return _x == a.getX() && _y == a.getY() && _z == a.getZ();
}

bool Point3f::operator !=(const Point3f &a) const
{
	return _x != a.getX() || _y != a.getY() || _z != a.getZ();
}

//Set the vector to zero
void Point3f::zero()
{
	_x = _y = _z = 0;
}

Point3f &Point3f::operator +=(const Point3f &a)
{
		_x += a.getX();
		_y += a.getY();
		_z += a.getZ();
		return *this;
}

Point3f &Point3f::operator -=(const Point3f &a)
{
		_x -= a.getX();
		_y -= a.getY();
		_z -= a.getZ();
		return *this;
}

Point3f &Point3f::operator *=(GLfloat a)
{
	_x *=a;
	_y *=a;
	_z *=a;
	return *this;
}


Point3f &Point3f::operator /=(GLfloat a)
{
	_x /=a;
	_y /=a;
	_z /=a;
	return *this;
}

//Print value

void Point3f::getPoint3fprint()
{
	std::cout << "x: " << _x << " y: " << _y << " z: " << _z << std::endl;
}
