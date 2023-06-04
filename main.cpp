// JAAR
// 06/04/2023
// C++ Primer Plus 6th Ed
// CH 8 Program Ex 2
// Version 1

// Updates:

// Future goals:

// Potential Use cases/errors:

// ------------------------------ Prompt---------------------------------------
// create a structure that contains a candy bars name, weight (double), 
// calories (int). write functions that take a ref to candy bar, 
// pointer-to-char, double, and int.
// default of Millennium Munch, 2.85, and 350
// function that ref candy bar and displays it.
// ------------------------------ Prompt---------------------------------------

// Headers:
#include <iostream>
#include <string>

using namespace std;

// Global Constants and Structures:
struct candyBar
{
	string name;
	double weight;
	int calories;
};

// Prototypes:
void display(const candyBar& bar);
void updateStructure(candyBar& bar, int calories = 350,
	double weight = 2.85, string name = "Millennium Munch");


int main()
{
	int calories;
	double weight;
	string name;
	
	// create a function that takes this.
	cout << "\nEnter candy bar name: ";
	getline(cin,name);
	cout << "\nEnter weight: ";
	cin >> weight;
	cin.get(); // clears the \n
	cout << "\nEnter calories: ";
	cin >> calories;
	cin.get(); // clears the \n
	candyBar bar;
	updateStructure(bar, calories, weight, name);
	display(bar);

}

void updateStructure(candyBar& bar, int calories, double weight, string name)
{
	bar.name = name;
	bar.weight = weight;
	bar.calories = calories;
}

void display(const candyBar& bar)
{
	cout << "Name: " << bar.name << "\n";
	cout << "Weight: " << bar.weight << "\n";
	cout << "Calories: " << bar.calories << "\n";
}