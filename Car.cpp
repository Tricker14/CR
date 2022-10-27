#include "Car.h"

void Car::setX(int x)
{
	this->x = x;
}
int Car::getX()
{
	return x;
}
void Car::MoveCar()
{
	if (x > road_leng + car_leng)
	{
		x = 1;
	}
	x++;
}
void Car::ShowCar()
{
	Windows::setconsolecolor(0, 12);
	if (x > road_leng + car_leng)
	{
		x = 1;
	}
	if (x <= car_leng)
	{
		Windows::GotoXY(1, y1_car);
		int j = car_leng - x;
		while (j < car_leng)
		{
			cout << car1[j];
			j++;
		}

		Windows::GotoXY(1, y2_car);
		j = car_leng - x;
		while (j < car_leng)
		{
			cout << car2[j];
			j++;
		}

		Windows::GotoXY(1, y3_car);
		j = car_leng - x;
		while (j < car_leng)
		{
			cout << car3[j];
			j++;
		}
		Windows::GotoXY(1, y4_car);

		j = car_leng - x;
		while (j < car_leng)
		{
			cout << car4[j];
			j++;
		}
	}
	else if (x > car_leng && x < road_leng)
	{

		Windows::GotoXY(x - car_leng + 1, y1_car);
		cout << car1;
		Windows::GotoXY(x - car_leng + 1, y2_car);
		cout << car2;
		Windows::GotoXY(x - car_leng + 1, y3_car);
		cout << car3;
		Windows::GotoXY(x - car_leng + 1, y4_car);
		cout << car4;
	}
	else if (x >= road_leng)
	{
		Windows::GotoXY(x - car_leng + 1, y1_car);
		for (int j = 0; j < car_leng - (x - road_leng + 1); j++)
		{
			cout << car1[j];
		}
		Windows::GotoXY(x - car_leng + 1, y2_car);
		for (int j = 0; j < car_leng - (x - road_leng + 1); j++)
		{
			cout << car2[j];
		}
		Windows::GotoXY(x - car_leng + 1, y3_car);
		for (int j = 0; j < car_leng - (x - road_leng + 1); j++)
		{
			cout << car3[j];
		}
		Windows::GotoXY(x - car_leng + 1, y4_car);
		for (int j = 0; j < car_leng - (x - road_leng + 1); j++)
		{
			cout << car4[j];
		}
	}
}

void Car::DeleteCar() {
	Windows::GotoXY(x - car_leng, y1_car);
	cout << " ";
	Windows::GotoXY(x - car_leng, y2_car);
	cout << " ";
	Windows::GotoXY(x - car_leng, y3_car);
	cout << " ";
	Windows::GotoXY(x - car_leng, y4_car);
	cout << " ";
}

int Car::getLeng() {
	return this->car_leng;
}