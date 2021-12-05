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

//възможни посоки
enum eDirecton
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};

eDirecton dir;

//с помощта на тази функция извеждането ще може да започва от определени координати
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
	//x и y определят координатите на змията, тя започва от центъра
	x = width / 2;

	y = height / 2;

	//генерираме ябълка на случаен принцип
	appleX = rand() % width;

	appleY = rand() % height; score = 0;

}

//тази функция е отговорна за извеждането на един кадър
void structure()
{
	//задаваме извеждането на новия кадър да започва от горен ляв ъгъл
	setPosition(0, 0);
	//setPosition ни освобождава от нуждата да използваме system("CLS");

	//генерираме горния ред
	for (int i = 0; i < width + 2; i++)

		cout << "#";

	cout << endl;
	//генерираме всеки ред
	for (int i = 0; i < height; i++) {
		//за отделните елементи на реда проверяваме:
		for (int j = 0; j < width; j++)
		{
			//ако елемента е на нулева позиция, то това е лява стена
			if (j == 0)
			{
				cout << "#";
			}
			//ако индексите на позициите съвпадат с координатите на змията, извеждаме звезда
			if (i == y && j == x)
			{
				cout << "*";
			}
			//ако съвпадат с координатите на ябълката, извеждаме процент
			else if (i == appleY && j == appleX)
			{
				cout << "%";
			}
			else {
				//в противен случай:
				bool print = false; //тази променлива определя дали трябва да отпечатаме нещо
				//за всяко парче от змията проверяаме
				for (int k = 0; k < nTail; k++)
				{
					//дали неговите координати съвпадат с разглежданата позиция и ако да
					if (tailX[k] == j && tailY[k] == i)
					{
						//извеждаме звездичка
						cout << "*";

						print = true; //и маркираме, че сме отпечатали звездичката

					}

				}

				if (!print) //ако нищо не е било изведено се извежда интервал, за да не се наруши фигурата на картата
				{
					cout << " ";
				}
			}
			//ако координата е равен на общата дължина - 1, то имаме дясна стена
			if (j == width - 1)
			{
				cout << "#";
			}
		}

		cout << endl;

	}

	//тук изкарваме долния ред
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}

	cout << endl;

	cout << "Score:" << score << endl;

	//караме програмата да "заспи" за 100 милисекунди, за да не се получава грозно и неконтролируемо "мигане"
	std::this_thread::sleep_for(100ms);
}

void input()
{
	//проверяваме кой клавиш е бил натиснат и задаваме посоката
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

//тази функция определя изместването на змията
void algor()
{
	//определяме позиция за вмъкване, която сочи към началото на змията
	int insX = tailX[0];

	int insY = tailY[0];

	int ins2X, ins2Y;

	//задаваме началото на змията на глобалните ѝ координати
	tailX[0] = x;

	tailY[0] = y;

	//за всяко парче на змията
	for (int i = 1; i < nTail; i++) {
		//определяме координатите на парчето
		ins2X = tailX[i];

		ins2Y = tailY[i];

		tailX[i] = insX;

		tailY[i] = insY;

		insX = ins2X;

		insY = ins2Y;

	}

	switch (dir) {

	case LEFT:
		//ако отиваме наляво намаляме х координата
		x--;

		break;

	case RIGHT:
		//надясно увеличаваме х координата
		x++;

		break;

	case UP:
		//нагоре намаляме y координата
		y--;

		break;

	case DOWN:
		//надолу увеличаваме y координата
		y++;

		break;

	default:

		break;

	}
	//ако отидем до десния край, искаме да излезем от левия, затова задаваме координата на 0
	if (x >= width)
	{
		x = 0;
	}
	//ако отидем до левия край, искаме да излезем от десния
	else if (x < 0)
	{
		x = width - 1;
	}
	//ако отидем до долу, искаме да излезем отгоре
	if (y >= height)
	{
		y = 0;
	}
	//ако отидем до горе, искаме да излезем отдолу
	else if (y < 0)
	{
		y = height - 1;
	}

	//ако след придвижването на змията, се окаже, че някое от нейните парчета е равно на нейните основни координати,
	//то тя сама е захапала себе си и играта приключва
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			gameover = true;
		}
	}

	//ако сме попаднали в координатите на ябълката, то сме я изяли
	if (x == appleX && y == appleY) {
		//печелим точки
		score += 10;
		//генерираме нова ябълка, която да се покаже в следващия кадър
		appleX = rand() % width;

		appleY = rand() % height;
		//увеличаваме размера на змията
		nTail++;

	}

}

int main()
{

	setup();

	while (!gameover) {
		//генерирай кадър
		structure();
		//приемай копчета
		input();
		//изчисли промянта на змията
		algor();

	}

	return 0;

}