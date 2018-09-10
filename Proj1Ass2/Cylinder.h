#include "Shape.hpp"

class Cylinder : public Shape
{
private:
	double radius;
	double height;
	//for stud
	double rotateZ;
	//point to rotate about
	double x2;
	double y2;
	double z2;
public:

	Cylinder();
	Cylinder(double x, double y, double z, double radius, double height);
	Cylinder(double x, double y, double z, double radius, double height, double rotation);

	double getRadius();
	void draw();
};
