#pragma once
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Point3f
{
private:
	GLfloat _x;
	GLfloat _y;
	GLfloat _z;

public:
	// Accessors
	GLfloat getX() const;
	GLfloat getY() const;
	GLfloat getZ() const;

	// Mutators
	void setX(GLfloat x);
	void setY(GLfloat y);
	void setZ(GLfloat z);
	
	
	//Constructor
	Point3f();
	Point3f(GLfloat x, GLfloat y, GLfloat z);
	
	//Copy Constructor
	Point3f(const Point3f &a) : _x(a.getX()), _y(a.getY()), _z(a.getZ()){}
	
	
	//return reference to the lvalue
	Point3f &operator =(const Point3f &a);
	
	//Check for equality from other value of Class
	bool operator ==(const Point3f &a) const;
	bool operator !=(const Point3f &a) const;
	
	//Set the vector to zero
	
	void zero();
	
	
	// Unary minus returns the negative of the vector 
	
	Point3f operator -() const { return Point3f(-_x,-_y,-_z);}
	
	//Operator Overload for calucation vector3f
	
	Point3f operator + (const Point3f &a) const
	{
		return Point3f( _x + a.getX(), _y + a.getY(), _z + a.getZ() );
	}
	
	Point3f operator - (const Point3f &a) const
	{
		return Point3f( _x - a.getX(), _y - a.getY(), _z - a.getZ() );
	}
	
	// Multipilication and division by scalar
	Point3f operator * (GLfloat a) const
	{
		return Point3f( _x * a, _y * a, _z * a );
	}

	//Divide by GLfloat for Point3f 
	Point3f operator / (GLfloat a) const
	{
		GLfloat oneOverA = 1.0f/a;
		
		return Point3f( _x * oneOverA, _y * oneOverA, _z * oneOverA);
	}
	
	Point3f &operator +=(const Point3f &a);
	Point3f &operator -=(const Point3f &a);
	Point3f &operator *=(GLfloat a); 
	Point3f &operator /=(GLfloat a);
	//Print value
	void getPoint3fprint();
};
