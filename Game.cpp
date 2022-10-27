#include "Game.h"

void Game::PauseGame(HANDLE t)
{
	SuspendThread(t);
}
void Game::setData(int speed, int x_person, int y_person)
{
	SPEED = speed;
	person.setXY(x_person, y_person);
}
void Game::ProcessDeath() {
	// process dead
	person.setSTATE(0);


	for (int i = 0; i < 4; i++)
	{
		car[i].ShowCar();
	}
	truck[0].ShowTruck();

	Windows::GotoXY(50, 40);
	cout << "YOU DIE";
}

