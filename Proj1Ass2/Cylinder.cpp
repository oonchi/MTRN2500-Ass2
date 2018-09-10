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
	this->rotateZ = 0;
	this->x2 = 0;
	this->y2 = 0;
	this->z2 = 0;
}


Cylinder::Cylinder(double x, double y, double z, double radius, double height, double rotation) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->radius = radius;
	this->height = height;
	this->rotation = rotation;
	this->rotateZ = 0;

}

void Cylinder::draw() {

	
	glPushMatrix();
	//move to centre point
	glTranslated(x, y , z );

	//rotate whole shpae 
	glRotated(-rotation, 0, 1, 0);
	
	glPushMatrix();
	glTranslated(0,+radius  , - height /2 );
	//glRotated(-rotation, 0, 1, 0);
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
	//rotates about the centre of the cylinder
	glTranslated(0, +radius,  + height / 2);
	//glRotated(-rotation, 0, 1, 0);
	GLUquadric *disk2 = gluNewQuadric();
	gluDisk(disk2, 0, radius, slices, stacks);
	glPopMatrix();
	
	glPopMatrix();


}

double Cylinder::getRadius() {
	return this->radius;
}