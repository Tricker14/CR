#pragma once
#include "Car.h"
#include "Truck.h"
#include "Person.h"
#include "Windows.h"
#include <thread>

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
extern Person person;

class Game
{
public:
	void PauseGame(HANDLE t);
	void setData(int speed, int x_person, int y_person);
	void ProcessDeath();
};

