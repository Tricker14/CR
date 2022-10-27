#pragma once

#include <iostream>
#include "Windows.h"
#include "Car.h"
#include "Truck.h"

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

extern Car* car;
extern Truck* truck;

class Person
{
private:
	string person1 = " O  ";
	string person2 = " |  ";
	string person3 = " |  ";
	string person4 = "/ \\";
	int x, y;
	int STATE;
public:
	Person()
	{
		STATE = 1;
		x = 50;
		y = 33;
	}

	void setSTATE(int STATE);

	int getSTATE();

	void setXY(int x, int y);

	int getX();

	int getY();

	void ClearPerson();

	void ShowPerson();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
};


