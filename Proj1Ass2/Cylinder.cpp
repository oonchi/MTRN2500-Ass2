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

//Constructor function
Cylinder::Cylinder()
{
	std::cout << "Cylinder being made" << std::endl;
}


//Constructor function for wheels
Cylinder::Cylinder(double x, double y, double z, double radius, double height, double rotation, bool isRolling, bool isSteering) {
	this->isRolling = 1;
	this->isSteering = 1;
	this->x = x;
	this->y = y;
	this->z = z;
	this->radius = radius;
	this->height = height;
	this->rotation = rotation;

}

void Cylinder::draw() {
		
	glPushMatrix();
	//move to specified point
	positionInGL();
	
	glPushMatrix();
	//translate to centre of circle
	glTranslated(0, radius, -height / 2 );
	//rotation of wheel along the z-plane
	glRotated(zRotation, 0, 0, 1);
	
	//cylinder body
	GLUquadric *cyl = gluNewQuadric();
	//number of sides to represent the cylinder
	GLint slices = 5;
	GLint stacks = 5;
	gluCylinder(cyl,radius, radius, height, slices, stacks);
	
	//front disk
	GLUquadric *disk1 = gluNewQuadric();
	gluDisk(disk1, 0, radius, slices, stacks);
	glPopMatrix();

	//back disk needs to be drawn at a different position
	glPushMatrix();
	//translate to the centre of the cylinder
	glTranslated(0, radius, height / 2);
	//rotation of wheel
	glRotated(zRotation, 0, 0, 1);
	GLUquadric *disk2 = gluNewQuadric();
	gluDisk(disk2, 0, radius, slices, stacks);
	glPopMatrix();
	
	//return back to original position before function was called
	glPopMatrix();

}

//sets the zRotation variable
void Cylinder::setZRotation(double zRotation) {
	this->zRotation = zRotation;
}

//gets the rotation on the zplane
double Cylinder::getZRotation() {
	return this->zRotation;
}

//gets the radius
double Cylinder::getRadius() {
	return this->radius;
}

//checks if the cylinder is meant to roll
bool Cylinder::getIsRolling() {
	return this->isRolling;
}

//checks if the cylinder is meant to steer
bool Cylinder::getIsSteering() {
	return this->isSteering;
}