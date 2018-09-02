#include "Shape.hpp"

class RectangularPrism: public Shape
{
private:
	double x_length;
	double y_length;
	double z_length;
public:
	RectangularPrism();
	RectangularPrism(double x, double y, double z, double x_length, double y_length, double z_length);
	RectangularPrism(double x, double y, double z, double x_length, double y_length, double z_length, double rotation);

	void draw();
};
