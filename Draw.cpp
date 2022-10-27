#include "Draw.h"

void Draw::GameBoard()
{
	int x = 0, y = 0;

	for (int i = y + 1; i < board_height + y; i++)
	{ // In ra bên tường
		Windows::GotoXY(x, i);
		cout << char(219);
		Sleep(1);
	}
	Windows::GotoXY(x, y); // In ra hàng trên
	cout << char(220);
	for (int i = 1; i < board_width; i++) {
		cout << char(220);
		Sleep(1);
	}
	cout << char(220);
	Windows::GotoXY(x, board_height + y); // In ra hàng dưới
	cout << char(223);
	for (int i = 1; i < board_width; i++) {
		cout << char(223);
		Sleep(1);
	}
	cout << char(223);

	for (int i = y + 1; i < board_height + y; i++)
	{ // In ra 2 bên tường
		Windows::GotoXY(x + board_width, i);
		cout << char(219);
		Sleep(1);
	}
}
void Draw::VehicleAndAnimalLane()
{
	// truck lane
	Windows::setconsolecolor(0, 12);
	Windows::GotoXY(1, y1_truck);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y2_truck);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y3_truck);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y4_truck);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	// car lane
	Windows::GotoXY(1, y1_car);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y2_car);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y3_car);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	Windows::GotoXY(1, y4_car);
	for (int i = 0; i < road_leng; i++) {
		cout << " ";
	}
	// person lane

}
