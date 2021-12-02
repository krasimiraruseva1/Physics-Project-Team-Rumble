#include <iostream>

using namespace std;

// Menu label
void menu()
{
cout << R"(
_ _____ _ _
/ \__/|/ __// \ /|/ \ /\
| |\/||| \ | |\ ||| | ||
| | ||| /_ | | \||| \_/|
\_/ \|\____\\_/ \|\____/
)" << '\n';

}

// Uniform and equidistant movements
void one()
{
	double V, V0, a, t;

	cout << endl;
	cout << "Which formula do you want to use? " << endl;
	cout << endl; cout << "UNIFORM MOVEMENT - U" << endl;
	cout << "EQUIDISTANT MOVEMENT - E" << endl;

	char formula;

	cin >> formula;

	if (formula == 'U')
	{
		cout << "You have chosen UNIFORM MOVEMENT." << endl;
		cout << "Enter your values for V0, a, t." << endl; 
		
		
		cin >> V0 >> a >> t; 
		
		cout << "V = " << V0 + a * t << endl;
	}

	else if (formula == 'E')
	{
		cout << "You have chosen EQUIDISTANT MOVEMENT." << endl;
		cout << "Enter your values for V0, a, t." << endl;
		
		cin >> V0 >> a >> t; 
		
		cout << "V = " << V0 - a * t << endl;
	}
	else
	{
		cout << "You have a mistake." << endl;
	}
}



// Your weight on different planets
void two()
{
	double weight;
	int planet;

	cout << "Enter your weight. ";

	// Enter your current weight
	cin >> weight;

	cout << "Choose a planet." << endl;

	cout << "1. Mercury" << endl;
	cout << "2. Venus" << endl;
	cout << "3. Earth" << endl;
	cout << "4. Mars" << endl;
	cout << "5. Jupiter" << endl;
	cout << "6. Saturn" << endl;
	cout << "7. Uranus" << endl;
	cout << "8. Neptune" << endl;

	cout << "Enter the number of the planet. ";

	cin >> planet;

	switch (planet)
	{
	case 1:
	{
		cout << "On Mercury your weight is: ";
		cout << weight * 0.01 << " kg.";
		break;
	}
	case 2:
	{
		cout << "On Venus your weight is ";
		cout << weight * 0.9 << " kg.";
		break;
	}
	case 3:
	{
		cout << "On Earth your weight is ";
		cout << weight << " kg.";
		break;
	}
	case 4:
	{
		cout << "On Mars your weight is ";
		cout << weight * 0.38 << " kg.";
		break;
	}
	case 5:
	{
		cout << "On Jupiter your weight is ";
		cout << weight * 2.52 << " kg.";
		break;
	}
	case 6:
	{

		cout << "On Saturn your weight is ";
		cout << weight * 1.06 << " kg.";
		break;

	}
	case 7:
	{

		cout << "On Uranus your weight is ";
		cout << weight * 0.88 << " kg.";
		break;

	}
	case 8:
	{

		cout << "On Neptune your weight is ";
		cout << weight * 1.13 << " kg.";
		break;

	}
	default:
	{
		cout << weight * 0.38;
		cout << "You have a mistake." << endl;
	}
	}
}



// Speed, way and time
void three()
{
	double V, t, S;
	char choice;
	
	cout << "What do you want to calculate? S, V or t? ";



	// Enter what you want to calculate
	cin >> choice;

	if (choice == 'V')
	{
		cout << "Enter S and t." << endl;

		cin >> S >> t;

		cout << "Your speed is ";
		cout << S / t;
		cout << " per hour.";
	}
	else if (choice == 'S')
	{
		cout << "Enter V and t." << endl;

		cin >> V >> t;

		cout << "Your way is ";
		cout << V * t;
		cout << " km.";
	}
	else if (choice == 't')
	{
		cout << "Enter S and V." << endl;

		cin >> S >> V;

		cout << "Your time is ";
		cout << S / V;
		cout << " hours.";
	}
	else
	{
		cout << "You have a mistake";
	}
}



// Electric current
void four()
{
	double I, q, t;

	char choice;

	cout << "What do you want to calculate? I, q or t? ";

	// Enter what you want to calculate
	cin >> choice;

	if (choice == 'I')
	{
		cout << "Enter q and t." << endl;

		cin >> q >> t;

		cout << "Your current is ";
		cout << q / t;
		cout << "A.";
	}



	else if (choice == 'q')
	{
		cout << "Enter I and t." << endl;

		// Enter what you want to calculate

		cin >> I >> t;

		cout << "Your current is ";
		cout << I * t;
		cout << "C";
	}



	else if (choice == 't')
	{
		cout << "Enter I and q." << endl;



		// Enter what you want to calculate
		cin >> I >> q;

		cout << "Your time is ";
		cout << q / I;
		cout << "per hour.";
	}



	else
	{
		cout << "You have a mistake";
	}
}



// Call the menu and all the functions
int main()
{
	// Print the menu
	menu();

	cout << endl;
	cout << endl;
	cout << endl;

	// List of the functions
	cout << "Number 1: UNIFORM and EQUIDISTANT MOVEMENT" << endl;
	cout << "Number 2: WEIGHT on DIFFERENT PLANETS " << endl;
	cout << "Number 3: SPEED, WAY and TIME" << endl;
	cout << "Number 4: ELECTRIC CURRENT, ELECTRIC CHARGE and TIME" << endl;

	cout << endl;

	cout << "Which programme do you want do run? ";

	int choice;

	// Enter your programme

	cin >> choice;

	// Call your function

	switch (choice)
	{
	case 1:
	{
		one();
		break;
	}
	case 2:
	{
		two();
		break;
	}
	case 3:
	{
		three();
		break;
	}
	case 4:
	{
		four();
		break;
	}
	}
}