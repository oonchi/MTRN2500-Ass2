#include <iostream>
#include "MyVehicle.h"
#include "iostream"
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "RectangularPrism.h"
#include "TriangularPrism.h"
#include "TrapezoidalPrism.h"
#include "Cylinder.h"

MyVehicle::MyVehicle()
{
	std::cout << "drawing my custom vehicle" << std::endl;
}

void MyVehicle::draw()
{
	// move to the vehicle's local frame of reference
	glPushMatrix();
	positionInGL();

	//my trailer car
	RectangularPrism body = RectangularPrism(0, 0, 0, 50, 20, 30);
	body.draw();

	//fender, cow smashing thingo
	TriangularPrism madaesthetics = TriangularPrism(25, 5, 0, 30, 6,8, 90);
	madaesthetics.draw();

	TrapezoidalPrism windowthingo = TrapezoidalPrism(10, 20, 0, 30, 30, 20, 10, 90);
	windowthingo.draw();

	//wheels
//	double x, double y, double z, double radius, double height
	Cylinder C1 = Cylinder(15, -10, 20, 10, 10);
	C1.draw();

	Cylinder C2 = Cylinder(15, -10, -20, 10, 10);
	C2.draw();

	Cylinder C3 = Cylinder(-15, -10, 20, 10, 10);
	C3.draw();

	Cylinder C4 = Cylinder(-15, -10, -20, 10, 10);
	C4.draw();

	// all the local drawing code
	// move back to global frame of reference
	glPopMatrix();
}
