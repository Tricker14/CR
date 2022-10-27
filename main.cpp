#include <iostream>
#include <Windows.h>
#include <cwchar>
#include <thread>
#include <conio.h>
#include "Car.h"
#include "Truck.h"
#include "Draw.h"
#include "Person.h"
#include "Game.h"
#include "Windows.h"

const int road_leng = 99;
int SPEED;
int board_height = 45;
int board_width = 100;

const int y1_truck = 1;
const int y2_truck = 2;
const int y3_truck = 3;
const int y4_truck = 4;

const int y1_person1 = 5;
const int y2_person1 = 6;
const int y3_person1 = 7;
const int y4_person1 = 8;


const int y1_car = 9;
const int y2_car = 10;
const int y3_car = 11;
const int y4_car = 12;

int stop_thread = 0;
int MOVING;
int MOVING_TEMP;

Person person;
Car* car = new Car[4];
Truck* truck = new Truck;
Game GAME;



void SetVehicle()
{
	car[1].setX(30);
	car[2].setX(60);
	car[3].setX(90);
}

int MSNumber(long a)
{
	while (a > 100)
	{
		a = a / 10;
	}
	a = a / 10;
	return a;
}

long count_step = 0;
bool isMovingCar = 1;
bool isMovingTruck = 1;

void MoveVehicle()
{
	if (count_step > 1000)
	{
		count_step = 0;
	}
	count_step++;

	// dieu kien de car chay/ngung
	if (count_step % 50 == 0 && count_step % 2 == 0)
	{

		isMovingCar = 0;
		Windows::GotoXY(102, y1_car);
		Windows::setconsolecolor(0, 12);
		cout << "DO  ";
	}
	if (count_step % 50 == 0 && MSNumber(count_step) % 2 != 0)
	{
		isMovingCar = 1;
		Windows::GotoXY(102, y1_car);
		Windows::setconsolecolor(0, 2);
		cout << "XANH";
	}

	// dieu kien de truck chay/ ngung

	if (count_step % 24 == 0 && count_step % 5 == 0)
	{
		isMovingTruck = 0;
		Windows::GotoXY(102, y1_truck);
		Windows::setconsolecolor(0, 12);
		cout << "DO  ";
	}
	if (count_step % 24 == 0 && count_step % 5 != 0)
	{
		Windows::setconsolecolor(0, 2);
		isMovingTruck = 1;
		Windows::GotoXY(102, y1_truck);
		cout << "XANH";
	}

	if (isMovingCar == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			car[i].MoveCar();
		}
	}
	if (isMovingTruck == 1)
	{
		truck[0].MoveTruck();
	}


	for (int i = 0; i < 4; i++)
	{
		car[i].ShowCar();
	}
	truck[0].ShowTruck();

	Sleep(SPEED);


	////
	if (isMovingCar == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			car[i].DeleteCar();
		}
	}

	if (isMovingTruck == 1)
	{
		for (int i = 0; i < 1; i++)
		{
			truck[i].DeleteTruck();
		}
	}

	//////////////////////////////////////////////////////

}


void ThreadFunc()
{
	while (stop_thread != 1) {

		if (person.getSTATE() == 1) //If my snake is alive
		{
			MoveVehicle();
			switch (MOVING)
			{

			case 'A':
			{
				person.MoveLeft();
				break;
			}
			case 'D':
				person.MoveRight();
				break;
			case 'W':
				person.MoveUp();
				break;
			case 'S':
				person.MoveDown();
				break;
			}
			MOVING_TEMP = MOVING;
			MOVING = ' ';
			person.ShowPerson();
			// person will die when hit
			for (int i = 0; i < 4; i++)
			{
				if (car[i].getX() - 1 == person.getX() && y1_car == person.getY())		// hit from right
				{
					person.ClearPerson();
					person.setXY(person.getX() + 1, person.getY());
					person.ShowPerson();
					GAME.ProcessDeath();
				}
				else if (car[i].getX() - (car[i].getLeng() + 1) == person.getX() && y1_car == person.getY()) {		// hit from left
					person.ClearPerson();
					person.setXY(person.getX() - 1, person.getY());
					person.ShowPerson();
					GAME.ProcessDeath();
				}
				else if (person.getX() >= (car[i].getX() - car[i].getLeng()) && person.getX() <= car[i].getX() && y1_car == person.getY()) {	// hit from top and bottom
					if(MOVING_TEMP == 'W') {
						person.ClearPerson();
						person.setXY(person.getX(), person.getY() + 4);
						person.ShowPerson();
					}
					else if (MOVING_TEMP == 'S') {
						person.ClearPerson();
						person.setXY(person.getX(), person.getY() - 4);
						person.ShowPerson();
					}
					GAME.ProcessDeath();
				}
			}
		}
	}
}



int main()
{
	Game GAME;


	Windows::SetWindowSize(800, 600);
	Windows::DisableResizeWindow();


	Windows::setconsolecolor(0, 15);
	system("cls");

	Windows::ShowConsoleCursor(false);

	Windows::setconsolecolor(0, 2);
	Windows::GotoXY(102, y1_truck);
	cout << "XANH";
	Windows::GotoXY(102, y1_car);
	cout << "XANH";

	Draw draw;
	draw.GameBoard();
	draw.VehicleAndAnimalLane();
	GAME.setData(20, 50, 33);
	SetVehicle();

	int temp;
	thread t1(ThreadFunc); //Create thread for snake
	HANDLE handle_t1 = t1.native_handle(); //Take handle of thread
	while (1)
	{
		temp = toupper(_getch());
		if (person.getSTATE() == 1)
		{
			if (temp == 'P')
			{
				GAME.PauseGame(handle_t1);
			}
			else if (temp == 'O')
			{
				GAME.PauseGame(handle_t1);
			}
			else {
				ResumeThread(handle_t1);
				if (temp == 'D' || temp == 'A' || temp ==
					'W' || temp == 'S')
				{
					MOVING = temp;
				}
			}
		}
		else
		{
			if (temp == 'Y')
			{
				person.ClearPerson();
				Windows::setconsolecolor(0, 15);
				Windows::GotoXY(50, 40);
				cout << "         ";
				person.setSTATE(1);
				person.setXY(50, 33);
			}
		}
	}
	return 0;
}