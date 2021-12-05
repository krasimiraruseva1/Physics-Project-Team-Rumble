#include < iostream >
#include < conio.h >
#include <Windows.h>
#include <thread>
 
using namespace std;
bool gameover;
 
const int width = 20;
 
const int height = 15;
 
int x, y, appleX, appleY, score;
 
int tailX[70], tailY[70];
 
int nTail;
 
// possible directions
enum eDirecton
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
 
eDirecton dir;
 
// with this function the output will be able to start from certain coordinates
void setPosition(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
 
	SetConsoleCursorPosition(hStdout, position);
}
 
void setup()
{
	gameover = false;
 
	dir = STOP;
	// x and y determine the coordinates of the snake, it starts from the center
	x = width / 2;
 
	y = height / 2;
 
	// generate an apple at random
	appleX = rand() % width;
 
	appleY = rand() % height; score = 0;
 
}
 
// this function is responsible for displaying a frame
void structure()
{
	// set the output of the new frame to start from the upper left corner
	setPosition(0, 0);
	// setPosition frees us from the need to use system ("CLS");
 
	// generate the top row
	for (int i = 0; i < width + 2; i++)
 
		cout << "#";
 
	cout << endl;
	// generate each row
	for (int i = 0; i < height; i++) {
		// for the individual elements of the row we check:
		for (int j = 0; j < width; j++)
		{
			// if the element is at zero position, then this is the left wall
			if (j == 0)
			{
				cout << "#";
			}
			// if the indices of the positions coincide with the coordinates of the snake, we display a star
			if (i == y && j == x)
			{
				cout << "*";
			}
			// if they match the coordinates of the apple, we display a percentage
			else if (i == appleY && j == appleX)
			{
				cout << "%";
			}
			else {
				//otherwise:
				bool print = false; // this variable determines whether we need to print something
					// for each piece of the snake we check
				for (int k = 0; k < nTail; k++)
				{
					// whether its coordinates match the position in question and if so
					if (tailX[k] == j && tailY[k] == i)
					{
						// display an asterisk
						cout << "*";
 
						print = true; // and we mark that we have printed the asterisk-
 
					}
 
				}
 
				if (!print) // if nothing has been displayed, a space is displayed so as not to distort the figure on the card
				{
					cout << " ";
				}
			}
			// if the coordinate is equal to the total length - 1, then we have a right wall
			if (j == width - 1)
			{
				cout << "#";
			}
		}
 
		cout << endl;
 
	}
 
	// here we get the bottom row
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
 
	cout << endl;
 
	cout << "Score:" << score << endl;
 
	// make the program "sleep" for 100 milliseconds to avoid ugly and uncontrollable "blinking"
	std::this_thread::sleep_for(100ms);
}
 
void input()
{
	// check which key was pressed and set the direction
	if (_kbhit()) {
 
		switch (_getch()) {
 
		case 'a':
 
			dir = LEFT;
 
			break;
 
		case 'd':
 
			dir = RIGHT;
 
			break;
 
		case 'w':
 
			dir = UP;
 
			break;
 
		case 's':
 
			dir = DOWN;
 
			break;
 
		case 'z':
 
			gameover = true;
 
			break;
 
		}
 
	}
 
}
 
// this function determines the displacement of the snake
void algor()
{
	// specify an insertion position that points to the beginning of the snake
	int insX = tailX[0];
 
	int insY = tailY[0];
 
	int ins2X, ins2Y;
 
	// set the snake's origin to its global coordinates
	tailX[0] = x;
 
	tailY[0] = y;
 
	// for each piece of the snake
	for (int i = 1; i < nTail; i++) {
		// determine the coordinates of the piece
		ins2X = tailX[i];
 
		ins2Y = tailY[i];
 
		tailX[i] = insX;
 
		tailY[i] = insY;
 
		insX = ins2X;
 
		insY = ins2Y;
 
	}
 
	switch (dir) {
 
	case LEFT:
		// if we go left we decrease the x coordinate
		x--;
 
		break;
 
	case RIGHT:
		// increase the x coordinate to the right
		x++;
 
		break;
 
	case UP:
		// up reduce the y coordinate
		y--;
 
		break;
 
	case DOWN:
		// down increase the y coordinate
		y++;
 
		break;
 
	default:
 
		break;
 
	}
	// if we go to the right end, we want to get out of the left, so we set the coordinate to 0
	if (x >= width)
	{
		x = 0;
	}
	// if we go to the left end, we want to get out of the right
	else if (x < 0)
	{
		x = width - 1;
	}
	// if we go down, we want to go up
	if (y >= height)
	{
		y = 0;
	}
	// if we go to the top, we want to get to the bottom
	else if (y < 0)
	{
		y = height - 1;
	}
 
	// if, after moving the snake, it turns out that one of its pieces is equal to its basic coordinates,
	// she has bitten herself and the game is over
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameover = true;
		}
	}
 
	// if we came across the coordinates of the apple, we ate it
	if (x == appleX && y == appleY) {
		// earn points
		score += 10;
		// generate a new apple to display in the next frame
		appleX = rand() % width;
 
		appleY = rand() % height;
		// increase the size of the snake
		nTail++;
 
	}
 
}
 
int main()
{
 
	setup();
 
	while (!gameover) {
		// generate frame
		structure();
		// accept buttons
		input();
		// calculate the change of the snake
		algor();
 
	}
 
	return 0;
 
}