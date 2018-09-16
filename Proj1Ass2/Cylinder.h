#include "Shape.hpp"

class Cylinder : public Shape
{
private:
	double radius;
	double height;
	double zRotation;
	//determines if the shape will move
	bool isRolling;
	bool isSteering;

public:
	//constructors
	Cylinder();
	Cylinder(double x, double y, double z, double radius, double height, double rotation, bool isRolling, bool isSteering);
	
	//getters for variables that were added
	double getRadius();
	double getZRotation();
	bool getIsRolling();
	bool getIsSteering();

	//setters for variables that update
	void setZRotation(double zRotation);

	//overloaded draw function
	void draw();
};
