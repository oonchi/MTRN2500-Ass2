#include "TrapezoidalPrism.h"
#include "iostream"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#else
#include <GL/gl.h>
#endif


TrapezoidalPrism::TrapezoidalPrism()
{
	std::cout << "triangularPrism being made" << std::endl;
}
TrapezoidalPrism::TrapezoidalPrism(double x, double y, double z, double depth, double a_length, double b_length, double height, double theta) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->depth = depth;
	this->a_length = a_length;
	this->b_length = b_length;
	this->height = height;
	this->theta = theta;
	this->rotation = 0;
}
TrapezoidalPrism::TrapezoidalPrism(double x, double y, double z, double depth, double a_length, double b_length, double height, double theta, double rotation) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->depth = depth;
	this->a_length = a_length;
	this->b_length = b_length;
	this->height = height;
	this->theta = theta;
	this->rotation = rotation;
}

void TrapezoidalPrism::draw() {
	//convert theta to radians
	double pi = atan(1) * 4;
	double rangles = theta * pi / 180;

	//move to the centre point of the object
	glTranslated(x, y, z);
	//rotate the x-axis we are drawing on
	glRotated(rotation, 0, 1, 0);

	//GL_QUADS groups four vertices into a single quadrilateral
	glBegin(GL_QUADS);
	//front face
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z + depth / 2);

	//back face
	glVertex3f(x + a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z - depth / 2);

	//positive xaxis side face
	glVertex3f(x + a_length / 2, 0, z - depth / 2);
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z - depth / 2);

	//negative xaxis side face
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z - depth / 2);

	//top face
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z + depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles), height, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z - depth / 2);
	glVertex3f(x - a_length / 2 + b_length * cos(rangles) + b_length, height, z + depth / 2);

	//bottom face
	glVertex3f(x + a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2, 0, z + depth / 2);
	glVertex3f(x - a_length / 2, 0, z - depth / 2);
	glVertex3f(x + a_length / 2, 0, z - depth / 2);

	glEnd();

	//unRotate the view back to what it was
	glRotated(-1 * rotation, 0, 1, 0);
	//glTranslate moves the world origin back
	glTranslated(-1 * x, -1 * y, -1 * z);

}