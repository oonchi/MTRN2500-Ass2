#include "Cylinder.h"
#include "iostream"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.H>
#else
#include <GL/gl.h>
#endif


Cylinder::Cylinder()
{
	std::cout << "Cylinder being made" << std::endl;
}
Cylinder::Cylinder(double x, double y, double z, double radius, double height) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->radius = radius;
	this->height = height;
	this->rotation = 0;
}
Cylinder::Cylinder(double x, double y, double z, double radius, double height, double rotation) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->radius = radius;
	this->height = height;
	this->rotation = rotation;
}

void Cylinder::draw() {
	glPushMatrix();
	glRotated(rotation, 1, 1, 0);
	
	glPushMatrix();
	glTranslated(x, y +radius  , z- height /2 );
	
	//cylinder body
	GLUquadric *cyl = gluNewQuadric();
	GLint slices = 50;
	GLint stacks = 50;
	gluCylinder(cyl,radius, radius, height, slices, stacks);
	
	//front disk
	GLUquadric *disk1 = gluNewQuadric();
	gluDisk(disk1, 0, radius, slices, stacks);
	glPopMatrix();

	//back disk
	glPushMatrix();
	glTranslated(x, y +radius, z + height / 2);
	
	GLUquadric *disk2 = gluNewQuadric();
	gluDisk(disk2, 0, radius, slices, stacks);
	glPopMatrix();

	glPopMatrix();

}