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
	/*
	glPushMatrix();
	glTranslated(20, 50, 20);
	glColor3f(1, 0, 1);
	RectangularPrism box1 = RectangularPrism(0,0,0,10,10,10);
	box1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 10, 0);
	glColor3f(0, 1, 1);
	TrapezoidalPrism trap1 = TrapezoidalPrism(0, 0, 0, 10, 50, 10, 10, 30);
	trap1.draw();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5, 0.5, 1);
	TriangularPrism tri1 = TriangularPrism(0, 0, 0, 5, 10, 3, 60);
	tri1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 30, 0);
	glColor3f(0.25, 1, 0);
	Cylinder cyl1 = Cylinder(0, 0, 0, 2, 5, 30);
	cyl1.draw();
	glPopMatrix();
	*/
	
	// move to the vehicle's local frame of reference
	
	glPushMatrix();
	positionInGL();

	//my trailer car
	RectangularPrism body = RectangularPrism(0, 0, 0, 4, 1, 3);
	glColor3f(0, 0.5, 1);
	body.draw();
	
	//fender, cow smashing thingo
	glTranslated(3, 0, 0);
	TriangularPrism madaesthetics = TriangularPrism(0, 0, 0, 3, 2, 1, 90);
	glColor3f(1, 0, 0);
	madaesthetics.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, 1, 0);
	glColor3f(1, 1, 1);
	TrapezoidalPrism windowthingo = TrapezoidalPrism(0, 0, 0, 3, 2, 1, 1, 90);
	windowthingo.draw();
	glPopMatrix();
	
	//wheels
//	double x, double y, double z, double radius, double height
	glPushMatrix();
	glTranslated(1, -0.5, 1.5);
	Cylinder C1 = Cylinder(0, 0, 0, 0.5, 0.5);
	glColor3f(0.5, 0, 0.5);
	C1.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(1, -0.5, -1.5);
	Cylinder C2 = Cylinder(0, 0, 0, 0.5, 0.5);
	C2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, -0.5, 1.5);
	Cylinder C3 = Cylinder(0, 0, 0, 0.5, 0.5);
	C3.draw();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-1, -0.5, -1.5);
	Cylinder C4 = Cylinder(0, 0, 0, 0.5, 0.5);
	C4.draw();
	glPopMatrix();

	// all the local drawing code
	// move back to global frame of reference
	glPopMatrix();
}
