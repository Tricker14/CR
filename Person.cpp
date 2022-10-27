#include "Person.h"

void Person::setSTATE(int STATE)
{
	this->STATE = STATE;
}

int Person::getSTATE()
{
	return STATE;
}

void Person::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Person::getX()
{
	return x;
}

int Person::getY()
{
	return y;
}

void Person::ClearPerson()
{
	Windows::setconsolecolor(0, 15);
	if (y == y1_car || y == y1_truck)
	{
		Windows::setconsolecolor(0, 12);
	}
	Windows::GotoXY(x, y);
	cout << "    ";
	Windows::GotoXY(x, y + 1);
	cout << "    ";
	Windows::GotoXY(x, y + 2);
	cout << "    ";
	Windows::GotoXY(x, y + 3);
	cout << "    ";
}

void Person::ShowPerson()
{
	Windows::setconsolecolor(0, 15);
	if (y == y1_car || y == y1_truck)
	{
		Windows::setconsolecolor(0, 12);
	}
	Windows::GotoXY(x, y);
	cout << person1;
	Windows::GotoXY(x, y + 1);
	cout << person2;
	Windows::GotoXY(x, y + 2);
	cout << person3;
	Windows::GotoXY(x, y + 3);
	cout << person4;
}
void Person::MoveLeft()
{
	for (int i = 0; i < 4; i++)
	{
		if (car[i].getX() == x && y1_car == y)
		{
			// process dead
			STATE = 0;


			for (int i = 0; i < 4; i++)
			{
				car[i].ShowCar();
			}
			truck[0].ShowTruck();

			Windows::GotoXY(50, 40);
			cout << "YOU DIE";
		}
	}
	if (x > 1)
	{
		ClearPerson();
		--x;
	}
}
void Person::MoveRight()
{
	if (x < board_width - 4)
	{
		ClearPerson();
		++x;
	}
}
void Person::MoveUp()
{
	if (y > 1)
	{
		ClearPerson();
		y -= 4;
	}
}
void Person::MoveDown()
{
	if (y < board_height - 4)
	{
		ClearPerson();
		y += 4;
	}
}
