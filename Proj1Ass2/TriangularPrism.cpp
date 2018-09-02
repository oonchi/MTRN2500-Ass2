#include "TriangularPrism.h"
#include "iostream"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#else
#include <GL/gl.h>
#endif


TriangularPrism::TriangularPrism()
{
	std::cout << "triangularPrism being made" << std::endl;
}
TriangularPrism::TriangularPrism(double x, double y, double z, double depth, double a_length, double b_length, double theta) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->depth = depth;
	this->a_length = a_length;
	this->b_length = b_length;
	this->theta = theta;
	this->rotation = 0;
}
TriangularPrism::TriangularPrism(double x, double y, double z, double depth, double a_length, double b_length, double theta, double rotation) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->depth = depth;
	this->a_length = a_length;
	this->b_length = b_length;
	this->theta = theta;
	this->rotation = rotation;
}

void TriangularPrism::draw() {
	//convert theta to radians
	double pi = atan(1) * 4;
	double rangles = theta * pi / 180;
	
	//move to the centre point of the object
	glTranslated(x, y, z);
	//rotate the x-axis we are drawing on
	glRotated(rotation, 1, 0, 0);

	//GL_TRIANGLES groups three vertices into a single triangle
	glBegin(GL_TRIANGLES);
	
	//front face
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z + depth / 2);
	//back face
	glVertex3f(x + a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z - depth / 2);
	glEnd();

	//draw the lines that connect the two triangular faces
	glBegin(GL_QUADS);
	//bottom quad
	//corners where theta isn't calculated
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x + a_length / 2, 0, z - depth / 2);
	//corners where theta is calculated
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);

	//second face
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x + a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z + depth / 2);

	//third face
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), b_length * sin(rangles), z - depth / 2);
	glEnd();

	//unRotate the view back to what it was
	glRotated(-1 * rotation, 1, 0, 0);
	//glTranslate moves the world origin back
	glTranslated(-1 * x, -1 * y, -1 * z);
}