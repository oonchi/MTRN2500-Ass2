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

	glPushMatrix();

	//inherited function
	positionInGL();

	//GL_QUADS groups four vertices into a single quadrilateral
	glBegin(GL_QUADS);
	//front face
	glVertex3f( + a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  + depth / 2);

	//back face
	glVertex3f( + a_length / 2, 0,  - depth / 2);
	glVertex3f( - a_length / 2, 0,  - depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  - depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  - depth / 2);

	//positive xaxis side face
	glVertex3f( + a_length / 2, 0,  - depth / 2);
	glVertex3f( + a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  - depth / 2);

	//negative xaxis side face
	glVertex3f( - a_length / 2, 0,  - depth / 2);
	glVertex3f( - a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  - depth / 2);

	//top face
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  + depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles), height,  - depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  - depth / 2);
	glVertex3f( - a_length / 2 + b_length * cos(rangles) + b_length, height,  + depth / 2);

	//bottom face
	glVertex3f( + a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2, 0,  + depth / 2);
	glVertex3f( - a_length / 2, 0,  - depth / 2);
	glVertex3f( + a_length / 2, 0,  - depth / 2);

	glEnd();

	glPopMatrix();

}