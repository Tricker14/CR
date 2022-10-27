#pragma once
#include <iostream>
#include "Windows.h"

using namespace std;
extern const int road_leng;
extern int SPEED;
extern int board_height;
extern int board_width;

extern const int y1_truck;
extern const int y2_truck;
extern const int y3_truck;
extern const int y4_truck;


extern const int y1_car;
extern const int y2_car;
extern const int y3_car;
extern const int y4_car;

extern int stop_thread;
extern int MOVING;


class Truck
{
private:
	int x;
	string truck1 = "██████";
	string truck2 = "######";
	string truck3 = "######";
	string truck4 = "OO  OO";

	int truck_leng = 6;
public:
	Truck()
	{
		x = road_leng - 1;
	}
	void setX(int x);
	int getX();
	void MoveTruck();
	void ShowTruck();
	void DeleteTruck();
};
