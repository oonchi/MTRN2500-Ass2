
#include <iostream>
#include "Vehicle.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle 
{

private:
	std::vector<Shape *> ShapeList;
	std::vector<ShapeInit> ShapeInits;
	double dt;
	double distTravelled;
	void createVectorVM();
public:
	
	MyVehicle();
	MyVehicle(VehicleModel vm);
	std::vector<ShapeInit> getVectorVM();
	void draw();
	void update(double dt);
	
};


