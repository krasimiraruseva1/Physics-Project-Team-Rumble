#include < iostream >

#include < conio.h >

using namespace std;

bool gameover;

const int width = 20;

const int height = 20;

int x, y, appleX, appleY, score;

int tailX[70], tailY[70]; 

int nTail;

enum eDirecton 
{
	STOP = 0, LEFT, RIGHT, UP, DOWN 
};

eDirecton dir;

void setup() 
{
	gameover = false;

	dir = STOP;

	x = width / 2;

	y = height / 2;

	appleX = rand() % width;

	appleY = rand() % height; score = 0;

}

void structure() 
{
	system("cls");

	for (int i = 0; i < width + 2; i++)

		cout << "#";

	cout << endl;

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) 
		{

			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "*";
			}
			else if (i == appleY && j == appleX)
			{
				cout << "%";
			}
			else {

				bool print = false;

				for (int k = 0; k < nTail; k++) 
				{

					if (tailX[k] == j && tailY[k] == i) 
					{

						cout << "*"; 

						print = true;

					}

				}

				if (!print)
				{
					cout << " ";
				}
			}

			if (j == width - 1)
			{
				cout << "#";
			}
		}

		cout << endl;

	}

	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}

		cout << endl;

		cout << "Score:" << score << endl;
	

}

void input()
{

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

void algor()
{

	int insX = tailX[0];

	int insY = tailY[0];

	int ins2X, ins2Y;

	tailX[0] = x;

	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {

		ins2X = tailX[i];

		ins2Y = tailY[i];

		tailX[i] = insX;

		tailY[i] = insY;

		insX = ins2X;

		insY = ins2Y;

	}

	switch (dir) {

	case LEFT:

		x--;

		break;

	case RIGHT:

		x++;

		break;

	case UP:

		y--;

		break;

	case DOWN:

		y++;

		break;

	default:

		break;

	}

	if (x >= width)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}

	if (y >= height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
	}

	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameover = true;
		}
	}
	if (x == appleX && y == appleY) {

		score += 10;

		appleX = rand() % width;

		appleY = rand() % height;

		nTail++;

	}

}

int main()
{

	setup();

	while (!gameover) {

		structure();

		input();

		algor();

	}

	return 0;

}