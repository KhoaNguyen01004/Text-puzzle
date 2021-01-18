#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global variables
int area = 8;
string userInput = "no";

//this funtion use to show mainMenu screen
void mainMenu();
//this function use to show the tutorial
void tutorial();
//this function use to take user input
string input();
//this function use to make all decision in the game
void decision();
//this function use to show area
void showArea();
//this function use to chage area
int changeArea();

int main()
{
	mainMenu();
	tutorial();
	while (true)
	{
		input();
		decision();
	}
}

void mainMenu()
{
	for (int i = 1; i <= 60; i++)
	{
		cout << "--";
	}
	cout << setw(65) << "Text Puzzle\n";
	for (int i = 1; i <= 60; i++)
	{
		cout << "--";
	}
	cout << endl;
}

void tutorial()
{
	cout << "The goal is to reach the final destination.\nSome of the comand you can use are foward, backward, yes, and no";
	cout << "\nIf you want to see this tutorial again, type help";
	cout << "\nType next to continue!";
}

string input()
{
	cout << "\n>>";
	cin >> userInput;
	return userInput;
}

void decision()
{
	if (userInput == "help")
		tutorial();
	if (userInput == "next")
	{
		system("cls");
		showArea();
	}
}

void showArea()
{
	switch (area)
	{
	case 1: cout << "This is area 1"; break;
	case 2: cout << "This is area 2"; break;
	case 3: cout << "This is area 3"; break;

	case 4: cout << "This is area 4"; break;
	case 5: cout << "This is area 5"; break;
	case 6: cout << "This is area 6"; break;

	case 7: cout << "This is area 7"; break;
	case 8: cout << "This is area 8"; break;
	case 9: cout << "This is area 9"; break;
	}
}
