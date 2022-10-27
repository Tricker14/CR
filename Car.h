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

class Car
{

private:
	int x;
	string car1 = "     ______ _      ";
	string car2 = "  ,*/______|_\\__   ";
	string car3 = " (    _   =|   __\\ ";
	string car4 = " =`.-(_) - - (_)-* ";

	int car_leng = 20;
public:
	Car()
	{
		x = 1;
	}

	void setX(int x);

	int getX();
	void MoveCar();
	void ShowCar();
	void DeleteCar();
	int getLeng();
};

