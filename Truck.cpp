#include "Truck.h"

void Truck::setX(int x)
{
	this->x = x;
}
int Truck::getX()
{
	return x;
}
void Truck::MoveTruck()
{
	if (x < 1 - truck_leng)
	{
		x = road_leng - 1;
	}
	x--;
}
void Truck::ShowTruck()
{
	Windows::setconsolecolor(0, 12);
	if (x < 1 - truck_leng)
	{
		x = road_leng - 1;
	}
	if (x >= road_leng - truck_leng)
	{
		Windows::GotoXY(x, y1_truck);
		int j = 0;
		while (j < road_leng - x + 1)
		{
			SetConsoleOutputCP(CP_UTF8);
			cout << truck1[j];
			j++;
			SetConsoleOutputCP(437);
		}
		Windows::GotoXY(x, y2_truck);
		j = 0;
		while (j < road_leng - x + 1)
		{
			cout << truck2[j];
			j++;
		}
		Windows::GotoXY(x, y3_truck);
		j = 0;
		while (j < road_leng - x + 1)
		{
			cout << truck3[j];
			j++;
		}
		Windows::GotoXY(x, y4_truck);
		j = 0;
		while (j < road_leng - x + 1)
		{
			cout << truck4[j];
			j++;
		}
	}
	else if (x < road_leng - truck_leng && x >= 1)
	{
		Windows::GotoXY(x, y1_truck);
		for (int j = 0; j < truck_leng; j++)
		{
			SetConsoleOutputCP(CP_UTF8);
			cout << truck1[j];
			SetConsoleOutputCP(437);
		}
		Windows::GotoXY(x, y2_truck);
		for (int j = 0; j < truck_leng; j++)
		{
			cout << truck2[j];
		}
		Windows::GotoXY(x, y3_truck);
		for (int j = 0; j < truck_leng; j++)
		{
			cout << truck3[j];
		}
		Windows::GotoXY(x, y4_truck);
		for (int j = 0; j < truck_leng; j++)
		{
			cout << truck4[j];
		}
	}
	else if (x < 1)
	{
		Windows::GotoXY(1, y1_truck);
		for (int j = -x; j < truck_leng; j++)
		{
			SetConsoleOutputCP(CP_UTF8);
			cout << truck1[j];
			SetConsoleOutputCP(437);
		}
		Windows::GotoXY(1, y2_truck);
		for (int j = -x; j < truck_leng; j++)
		{
			cout << truck2[j];
		}
		Windows::GotoXY(1, y3_truck);
		for (int j = -x; j < truck_leng; j++)
		{
			cout << truck3[j];
		}
		Windows::GotoXY(1, y4_truck);
		for (int j = -x; j < truck_leng; j++)
		{
			cout << truck4[j];
		}
	}
}
void Truck::DeleteTruck()
{
	if (x <= road_leng - truck_leng)
	{
		Windows::setconsolecolor(0, 12);
		Windows::GotoXY(x + truck_leng, y1_truck);
		cout << " ";
		Windows::GotoXY(x + truck_leng, y2_truck);
		cout << " ";
		Windows::GotoXY(x + truck_leng, y3_truck);
		cout << " ";
		Windows::GotoXY(x + truck_leng, y4_truck);
		cout << " ";
	}

}
