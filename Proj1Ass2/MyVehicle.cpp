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

//constructor for own vehicle
MyVehicle::MyVehicle()
{
	this->distTravelled = 0;

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

	ShapeList.push_back(body);
	ShapeList.push_back(madaesthetics);
	ShapeList.push_back(windowthingo);
	ShapeList.push_back(C1);
	ShapeList.push_back(C2);
	ShapeList.push_back(C3);
	ShapeList.push_back(C4);

	//init to shape vector
	createVectorVM();
}

//Constructor based on server details
MyVehicle::MyVehicle(VehicleModel vm)
{
	//iterate through shapeinit vector, getting each shape to draw
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

//vm representation of own vehicle
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
	body.rgb[2] = 0;

	ShapeInit madaesthetics;
	madaesthetics.type = TRIANGULAR_PRISM;
	madaesthetics.params.tri.alen = 2;
	madaesthetics.params.tri.blen = 1;
	madaesthetics.params.tri.angle = 90;
	madaesthetics.params.tri.depth = 3;
	madaesthetics.xyz[0] = 3;
	madaesthetics.xyz[1] = 0;
	madaesthetics.xyz[2] = 0;
	madaesthetics.rotation = 0;
	madaesthetics.rgb[0] = 1;
	madaesthetics.rgb[1] = 0.6;
	madaesthetics.rgb[2] = 0;

	ShapeInit windowthingo;
	windowthingo.type = TRAPEZOIDAL_PRISM;
	windowthingo.params.trap.alen = 2;
	windowthingo.params.trap.blen = 1;
	windowthingo.params.trap.height = 1;
	windowthingo.params.trap.aoff = 0;
	windowthingo.params.trap.depth = 3;
	windowthingo.xyz[0] = 1;
	windowthingo.xyz[1] = 1;
	windowthingo.xyz[2] = 0;
	windowthingo.rotation = 0;
	windowthingo.rgb[0] = 1;
	windowthingo.rgb[1] = 0.6;
	windowthingo.rgb[2] = 0;

	ShapeInit C1;
	C1.type = CYLINDER;
	C1.params.cyl.radius = 0.5;
	C1.params.cyl.depth = 0.5;
	C1.params.cyl.isRolling = 1;
	C1.params.cyl.isSteering = 1;
	C1.xyz[0] = 1;
	C1.xyz[1] = -0.5;
	C1.xyz[2] = 1.5;
	C1.rotation = getSteering();
	C1.rgb[0] = 1;
	C1.rgb[1] = 0;
	C1.rgb[2] = 0;

	ShapeInit C2;
	C2.type = CYLINDER;
	C2.params.cyl.radius = 0.5;
	C2.params.cyl.depth = 0.5;
	C2.params.cyl.isRolling = 1;
	C2.params.cyl.isSteering = 1;
	C2.xyz[0] = 1;
	C2.xyz[1] = -0.5;
	C2.xyz[2] = -1.5;
	C2.rotation = getSteering();
	C2.rgb[0] = 1;
	C2.rgb[1] = 0;
	C2.rgb[2] = 0;

	ShapeInit C3;
	C3.type = CYLINDER;
	C3.params.cyl.radius = 0.5;
	C3.params.cyl.depth = 0.5;
	C3.params.cyl.isRolling = 1;
	C3.params.cyl.isSteering = 1;
	C3.xyz[0] = -1;
	C3.xyz[1] = -0.5;
	C3.xyz[2] = 1.5;
	C3.rotation = getSteering();
	C3.rgb[0] = 0;
	C3.rgb[1] = 0;
	C3.rgb[2] = 1;

	ShapeInit C4;
	C4.type = CYLINDER;
	C4.params.cyl.radius = 0.5;
	C4.params.cyl.depth = 0.5;
	C4.params.cyl.isRolling = 1;
	C4.params.cyl.isSteering = 1;
	C4.xyz[0] = -1;
	C4.xyz[1] = -0.5;
	C4.xyz[2] = -1.5;
	C4.rotation = getSteering();
	C4.rgb[0] = 0;
	C4.rgb[1] = 0;
	C4.rgb[2] = 1;

	//push onto std::vector<ShapeInit> ShapeInits;
	this->ShapeInits.push_back(body);
	this->ShapeInits.push_back(madaesthetics);
	this->ShapeInits.push_back(windowthingo);
	this->ShapeInits.push_back(C1);
	this->ShapeInits.push_back(C2);
	this->ShapeInits.push_back(C3);
	this->ShapeInits.push_back(C4);
}

//getter for shpaeinit vector that defines the vehicle
std::vector<ShapeInit> MyVehicle::getVectorVM() {
	return ShapeInits;
}

//draws the vehicle based on definition in the ShapeList vector
void MyVehicle::draw()
{
	glPushMatrix();
	//move to position of the vehicle
	positionInGL();
	for (std::vector<Shape*>::iterator it = ShapeList.begin(); it != ShapeList.end(); ++it) {
		//draw shapes of vehicle relative to position of vehicle
		glPushMatrix();
		(*it)->setColorInGL();
		(*it)->draw();
		glPopMatrix();
	}	
	glPopMatrix();
}

//overload of update function that implements rotation and steering
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

	//iterate through shapelist, looking for 
	for (std::vector<Shape*>::iterator it = ShapeList.begin(); it != ShapeList.end(); ++it) {
		//dynamic cast the shapes
		Cylinder *cyl = dynamic_cast<Cylinder *>(*it);
		//check if nullptr, not nullptr if shape is cylinder
		if (cyl != nullptr) {
			//set rotation on y-plane for steering
			if (cyl->getIsSteering()) {
				cyl->setRotation(steering);
			}
			//rotates the wheel alongs its centre axis
			if (cyl->getIsRolling()) {
				//calculate cumulative distance travelled
				this->distTravelled += this->speed * dt;
				double circum = 2 * Pi* cyl->getRadius();
					
				double revolutions = distTravelled / circum;
				//makes the wheels rotate at a lower rate for observation
				double modifier = 25;
				double rotateZ = revolutions * 360 / modifier;
				
				//rotates the wheel
				cyl->setZRotation(-rotateZ);
			}

		}
	}

}