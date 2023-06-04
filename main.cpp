// JAAR
// 06/04/2023
// C++ Primer Plus 6th Ed
// CH 8 Program Ex 2
// Version 2

// Updates:
// -default updateStructure
// +tolower function
// +userResponse function; template.
// userResponse function; non-template

// Future Goals:
// TODO: ask user to print vector

// ------------------------------ Prompt---------------------------------------
// Create a structure that contains a candy bars name, weight (double), 
// calories (int). Write functions that take a ref to candy bar, pointer-to-char,
// double, and int which default of Millennium Munch, 2.85, and 350.
// function that ref candy bar and displays it.
// ------------------------------ Prompt---------------------------------------

// Headers:
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Global Constants and Structures:
struct candyBar
{
	string name;
	double weight;
	int calories;
};

// Prototypes:
string tolower(string response);
void display(const candyBar& bar);
void userResponse(string& response);
template <typename T1>
void updateStructure(T1& input, string type);
void updateStructure(string& str);

int main()
{
	vector <candyBar> candyBarList{ {"Millennium Munch", 2.85, 350}};
	string response = "yes";
	while (response == "yes")
	{
		cout << "Do you want to record a new candy bar?\n";
		userResponse(response);
		if (response == "yes")
		{
			candyBar* newBar = new candyBar;
			updateStructure((*newBar).name);
			updateStructure((*newBar).weight, "weight");
			updateStructure((*newBar).calories, "calories");
			display(*newBar);
			candyBarList.push_back(*newBar);
		}
	}
}

// Gets a value referring to some type and verifies that it is a valid response.
// typename: T1
// Param: T1& input, string type 
template <typename T1>
void updateStructure(T1& input, string type)
{
	do
	{
		cout << "\tEnter " << type << ": ";
		cin >> input;
		while (!cin)
		{
			cin.clear();
		}
		while (cin.get() != '\n')
		{
			continue;
		}
	} while (input <= 0);
}

// Gets the name of a candy bar from the user and asks them to verify their input.
// Param: string str
void updateStructure(string& str)
{
	string response;
	do
	{
		cout << "\tEnter name: ";
		getline(cin, str);
		cout << "Is the name correct?\n";
		userResponse(response);
		response = tolower(response);
	} while (response != "yes");
	
}

// Displays the contents of a candy bar;
// Param: candyBar & bar
void display(const candyBar& bar)
{
	cout << "Name: " << bar.name << "\n";
	cout << "Weight: " << bar.weight << "\n";
	cout << "Calories: " << bar.calories << "\n";
}

// Gets a user response and if it's not yes or no, prompts the user to enter
// another response.
// Param: string response
void userResponse(string & response)
{
	do
	{
		cout << "Enter your response: ";
		getline(cin, response);
		response = tolower(response);
	} while (response != "yes" && response != "no");
}


// Takes a phrase replaces all uppercase letters with lowercase letters.
// Param: string response
// Return: string response
string tolower(string phrase)
{
	for (int i = 0; i < phrase.size(); i++)
	{
		phrase.at(i) = tolower(phrase.at(i));
	}
	return phrase;
}