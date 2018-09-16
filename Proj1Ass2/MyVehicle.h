#include <iostream>
#include "Vehicle.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle 
{

private:
	//vector that contains pointers to shapes, only used for representation of own vehicle
	std::vector<Shape *> ShapeList;
	
	//vector of shapeinits used for VMs
	std::vector<ShapeInit> ShapeInits;
	
	//cumulative distance travelled by vehicle
	double distTravelled;
	
	//create vector vm of own vehicle to earn 
	void createVectorVM();

public:
	//base constructor that makes my own class
	MyVehicle();
	
	//constructor for vehicle based on server data
	MyVehicle(VehicleModel vm);
	
	//function to get the vector vm that defines our vehicle
	std::vector<ShapeInit> getVectorVM();
	
	//draw function for vehicles
	void draw();

	//overload of function so that steering and rolling works
	void update(double dt);
	
};


