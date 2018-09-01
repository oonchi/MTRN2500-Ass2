#include "iostream"
#include "RectangularPrism.h"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#else
#include <GL/gl.h>
#endif
RectangularPrism::RectangularPrism() {
	std::cout << "rectanglularPrism being made" << std::endl;

}


RectangularPrism::RectangularPrism(double x, double y, double z, double x_length, double y_length, double z_length) {
	//use these points as centre
	this->x = x;
	this->y = y;
	this->z = z;
	//use these as lengths
	this->x_length = x_length;
	this->y_length = y_length;
	this->z_length = z_length;
	rotation = 0;
}

RectangularPrism::RectangularPrism(double x, double y, double z, double x_length, double y_length, double z_length, double rotation) {
	//use these points as centre
	this->x = x;
	this->y = y;
	this->z = z;
	//use these as lengths
	this->x_length = x_length;
	this->y_length = y_length;
	this->z_length = z_length;
	//set the rotation angle about the origin on horizontal plane
	this->rotation = rotation;
}

void RectangularPrism::draw() {
	
	//rotate the x-axis we are drawing on
	glRotated(rotation, x, y, z);
	//GL_QUADS makes it so every pair of vertices are joined into a rectangle.
	glBegin(GL_QUADS);	
	//being drawing the lines 
	//front face
	glVertex3f(x - x_length / 2, y - y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y - y_length / 2, z + z_length / 2); 
	glVertex3f(x + x_length / 2, y + y_length / 2, z + z_length / 2);
	glVertex3f(x - x_length / 2, y + y_length / 2, z + z_length / 2);
	//backface
	glVertex3f(x - x_length / 2, y - y_length / 2, z - z_length / 2);
	glVertex3f(x + x_length / 2, y - y_length / 2, z - z_length / 2);
	glVertex3f(x + x_length / 2, y + y_length / 2, z - z_length / 2);
	glVertex3f(x - x_length / 2, y + y_length / 2, z - z_length / 2);
	//side faces
	glVertex3f(x - x_length / 2, y - y_length / 2, z - z_length / 2);
	glVertex3f(x - x_length / 2, y - y_length / 2, z + z_length / 2);
	glVertex3f(x - x_length / 2, y + y_length / 2, z + z_length / 2);
	glVertex3f(x - x_length / 2, y + y_length / 2, z - z_length / 2);

	glVertex3f(x + x_length / 2, y - y_length / 2, z - z_length / 2);
	glVertex3f(x + x_length / 2, y - y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y + y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y + y_length / 2, z - z_length / 2);

	//bottom face
	glVertex3f(x - x_length / 2, y - y_length / 2, z - z_length / 2);
	glVertex3f(x - x_length / 2, y - y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y - y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y - y_length / 2, z - z_length / 2);

	//top face
	glVertex3f(x - x_length / 2, y + y_length / 2, z - z_length / 2);
	glVertex3f(x - x_length / 2, y + y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y + y_length / 2, z + z_length / 2);
	glVertex3f(x + x_length / 2, y + y_length / 2, z - z_length / 2);

	glEnd();

	//undo the rotation on the axis we are drawing on
	glRotated(-1*rotation, x, y, z);

}