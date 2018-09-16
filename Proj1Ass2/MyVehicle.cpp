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
#include <vector>

#define Pi 3.14159265
MyVehicle::MyVehicle()
{
	this->dt = 0;
	this->distTravelled = 0;
	std::cout << "drawing my custom vehicle" << std::endl;
	// move to the vehicle's local frame of reference
	
	glPushMatrix();
	positionInGL();

	//my trailer car
	RectangularPrism *body = new RectangularPrism(0, 0, 0, 4, 1, 3);
	body->setColor(0, 0.6, 0);

	//fender, cow smashing thingo
	TriangularPrism *madaesthetics = new TriangularPrism(3, 0, 0, 3, 2, 1, 90);
	madaesthetics->setColor(1, 0.6, 0);
	glPopMatrix();

	glPushMatrix();
	TrapezoidalPrism *windowthingo = new TrapezoidalPrism(1, 1, 0, 3, 2, 1, 1, 90);
	windowthingo->setColor(1, 1, 1);
	glPopMatrix();

	//wheels
	//	double x, double y, double z, double radius, double height
	glPushMatrix();
	Cylinder *C1 = new Cylinder(1, -0.5, 1.5, 0.5, 0.5, 0, 1, 1);
	C1->setColor(1.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
	Cylinder *C2 = new  Cylinder(1, -0.5, -1.5, 0.5, 0.5, 0, 1, 1);
	C2->setColor(1.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
	Cylinder *C3 = new Cylinder(-1, -0.5, 1.5, 0.5, 0.5, 0, 1, 1);
	C3->setColor(0.0, 0.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	Cylinder *C4 = new Cylinder(-1, -0.5, -1.5, 0.5, 0.5,0, 1, 1);
	C4->setColor(0.0, 0.0, 1.0);
	glPopMatrix();

	// all the local drawing code
	// move back to global frame of reference
	glPopMatrix();

	//std::vector<Shape *> ShapeList;
	ShapeList.push_back(body);
	ShapeList.push_back(madaesthetics);
	ShapeList.push_back(windowthingo);
	ShapeList.push_back(C1);
	ShapeList.push_back(C2);
	ShapeList.push_back(C3);
	ShapeList.push_back(C4);
	createVectorVM();
}

MyVehicle::MyVehicle(VehicleModel vm)
{
	this->dt = 0;
	for (std::vector<ShapeInit>::iterator it = vm.shapes.begin(); it != vm.shapes.end(); ++it) {
		if ((*it).type == UNKNOWN_SHAPE) {
			std::cout << "UNKNOWN SHAPE, cannot handle" << std::endl;
		}
		else if ((*it).type == RECTANGULAR_PRISM) {
			RectangularPrism *rec = new RectangularPrism( (*it).xyz[0], (*it).xyz[1], (*it).xyz[2], (*it).params.rect.xlen, (*it).params.rect.ylen, (*it).params.rect.zlen,  (*it).rotation);
			rec->setColor((*it).rgb[0], (*it).rgb[1], (*it).rgb[2]);
			ShapeList.push_back(rec);
		}
		else if ((*it).type == TRIANGULAR_PRISM) {
			TriangularPrism *tri = new TriangularPrism((*it).xyz[0], (*it).xyz[1], (*it).xyz[2], (*it).params.tri.depth, (*it).params.tri.alen, (*it).params.tri.blen, (*it).params.tri.angle, (*it).rotation);
			tri->setColor((*it).rgb[0], (*it).rgb[1], (*it).rgb[2]);
			ShapeList.push_back(tri);
		}
		else if ((*it).type == TRAPEZOIDAL_PRISM) {
			double angle = atan((*it).params.trap.height / (*it).params.trap.aoff) * 180 / Pi;
			TrapezoidalPrism *trap = new TrapezoidalPrism((*it).xyz[0], (*it).xyz[1], (*it).xyz[2], (*it).params.trap.depth, (*it).params.trap.alen, (*it).params.trap.blen, (*it).params.trap.height, angle, (*it).rotation);
			trap->setColor((*it).rgb[0], (*it).rgb[1], (*it).rgb[2]);
			ShapeList.push_back(trap);
		}
		else if ((*it).type == CYLINDER) {	
			Cylinder *cyl = new Cylinder((*it).xyz[0], (*it).xyz[1], (*it).xyz[2], (*it).params.cyl.radius, (*it).params.cyl.depth, (*it).rotation, (*it).params.cyl.isRolling, (*it).params.cyl.isSteering);
			cyl->setColor((*it).rgb[0], (*it).rgb[1], (*it).rgb[2]);
			ShapeList.push_back(cyl);
		}
	}
}


void MyVehicle::createVectorVM() {

	ShapeInit body;
	body.type = RECTANGULAR_PRISM;
	body.params.rect.xlen = 4;
	body.params.rect.ylen = 1;
	body.params.rect.zlen = 3;
	body.xyz[0] = 0;
	body.xyz[1] = 0;
	body.xyz[2] = 0;
	body.rotation = 0;
	body.rgb[0] = 0;
	body.rgb[1] = 0.6;
	body.rgb[0] = 0;

	ShapeInit madaesthetics;
	body.type = TRIANGULAR_PRISM;
	body.params.tri.alen = 2;
	body.params.tri.blen = 1;
	body.params.tri.angle = 90;
	body.params.tri.depth = 3;
	body.xyz[0] = 3;
	body.xyz[1] = 0;
	body.xyz[2] = 0;
	body.rotation = 0;
	body.rgb[0] = 1;
	body.rgb[1] = 0.6;
	body.rgb[0] = 0;

	ShapeInit windowthingo;
	body.type = TRAPEZOIDAL_PRISM;
	body.params.trap.alen = 2;
	body.params.trap.blen = 1;
	body.params.trap.height = 1;
	body.params.trap.aoff = 0; //this offset might be wrong
	body.params.trap.depth = 3;
	body.xyz[0] = 1;
	body.xyz[1] = 1;
	body.xyz[2] = 0;
	body.rotation = 0;
	body.rgb[0] = 1;
	body.rgb[1] = 0.6;
	body.rgb[0] = 0;

	ShapeInit C1;
	body.type = CYLINDER;
	body.params.cyl.radius = 0.5;
	body.params.cyl.depth = 0.5;
	body.params.cyl.isRolling = 1;
	body.params.cyl.isSteering = 1;
	body.xyz[0] = 1;
	body.xyz[1] = -0.5;
	body.xyz[2] = 1.5;
	body.rotation = getSteering();
	body.rgb[0] = 1;
	body.rgb[1] = 0;
	body.rgb[0] = 0;

	ShapeInit C2;
	body.type = CYLINDER;
	body.params.cyl.radius = 0.5;
	body.params.cyl.depth = 0.5;
	body.params.cyl.isRolling = 1;
	body.params.cyl.isSteering = 1;
	body.xyz[0] = 1;
	body.xyz[1] = -0.5;
	body.xyz[2] = -1.5;
	body.rotation = getSteering();
	body.rgb[0] = 1;
	body.rgb[1] = 0;
	body.rgb[0] = 0;

	ShapeInit C3;
	body.type = CYLINDER;
	body.params.cyl.radius = 0.5;
	body.params.cyl.depth = 0.5;
	body.params.cyl.isRolling = 1;
	body.params.cyl.isSteering = 1;
	body.xyz[0] = -1;
	body.xyz[1] = -0.5;
	body.xyz[2] = 1.5;
	body.rotation = getSteering();
	body.rgb[0] = 0;
	body.rgb[1] = 0;
	body.rgb[0] = 1;

	ShapeInit C4;
	body.type = CYLINDER;
	body.params.cyl.radius = 0.5;
	body.params.cyl.depth = 0.5;
	body.params.cyl.isRolling = 1;
	body.params.cyl.isSteering = 1;
	body.xyz[0] = -1;
	body.xyz[1] = -0.5;
	body.xyz[2] = -1.5;
	body.rotation = getSteering();
	body.rgb[0] = 0;
	body.rgb[1] = 0;
	body.rgb[0] = 1;


	//std::vector<ShapeInit> ShapeInits;
	this->ShapeInits.push_back(body);
	this->ShapeInits.push_back(madaesthetics);
	this->ShapeInits.push_back(windowthingo);
	this->ShapeInits.push_back(C1);
	this->ShapeInits.push_back(C2);
	this->ShapeInits.push_back(C3);
	this->ShapeInits.push_back(C4);
}


std::vector<ShapeInit> MyVehicle::getVectorVM() {

	return ShapeInits;
}

void MyVehicle::draw()
{

	glPushMatrix();
	positionInGL();
	for (std::vector<Shape*>::iterator it = ShapeList.begin(); it != ShapeList.end(); ++it) {
		glPushMatrix();
		
		(*it)->setColorInGL();
		//(*it)->positionInGL();
		(*it)->draw();
		glPopMatrix();
	}	
	glPopMatrix();
}
void MyVehicle::update(double dt)
{
	speed = clamp(MAX_BACKWARD_SPEED_MPS, speed, MAX_FORWARD_SPEED_MPS);
	steering = clamp(MAX_LEFT_STEERING_DEGS, steering, MAX_RIGHT_STEERING_DEGS);

	// update position by integrating the speed
	x += speed * dt * cos(rotation * 3.1415926535 / 180.0);
	z += speed * dt * sin(rotation * 3.1415926535 / 180.0);

	// update heading
	rotation += dt * steering * speed;

	while (rotation > 360) rotation -= 360;
	while (rotation < 0) rotation += 360;


	if (fabs(speed) < .1)
		speed = 0;
	if (fabs(steering) < .1)
		steering = 0;

	this->dt = dt;

	for (std::vector<Shape*>::iterator it = ShapeList.begin(); it != ShapeList.end(); ++it) {
		Cylinder *cyl = dynamic_cast<Cylinder *>(*it);
		if (cyl != nullptr) {
			if (cyl->getIsSteering()) {
				cyl->setRotation(steering);
			}
			if (cyl->getIsRolling()) {
				this->distTravelled += this->speed * this->dt;
				double circum = 2 * Pi* cyl->getRadius();
				//revolutions per second
				
				//double revolutions = fmod(distTravelled, circum);
				double revolutions = distTravelled / circum;
				
				double rotateZ = revolutions * 360 / 25;
				

				cyl->setZRotation(-rotateZ);
				//				cyl->setX(-1 + 0.4*sin(rotateZ * Pi / 180));
	//			cyl->setY(-0.05 + 0.4*cos(rotateZ * Pi / 180));
			}
/*			else {
				this->distTravelled += this->speed * this->dt;
				double studRadius = 0.1;
				double modifier = 10;
				double studCircumference = 10 * 2 * Pi*studRadius;
				//revolutions per second

				double revolutions = fmod(distTravelled, studCircumference);
				double rotateZ = revolutions * 360;
				//r(-1, -0.5, -1.5, 0.5, 0.5)
				std::cout << "distTravelled" << distTravelled << " circum: " << studCircumference << " revolutions" << revolutions << " rotateZ: " << rotateZ << std::endl;
				cyl->setX(-1 +0.4*sin(rotateZ * Pi / 180));
				cyl->setY(-0.05 +0.4*cos(rotateZ * Pi / 180));
			}*/
		}
	}

	//setRotation


}