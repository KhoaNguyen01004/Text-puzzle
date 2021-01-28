#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>										// Finished

using namespace std;

//Global variables
int area = 8;
string userInput = "no";
string inventory[3] = { "", "", "" };
int take[] = { 1, 1, 1, 1, 1, 1 };
int index = 0;
int lockSecret = 3;
int lockBedroom = 1;
int lockBalcony = 1;
int lockStoreRoom = 1;
const int maxBag = 2;

//this funtion use to show mainMenu screen
void mainMenu();
//this function use to show the tutorial
void tutorial();
//this function use to take user input
string input();
//this function use to make all decision in the game after user has input their choice
void decision();
//this function use to show area
void showArea();
//this function use to show inventory
void showInventory();

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
	cout << "1. The goal is to reach the final destination.\n2. Some of the common commands that you can use are forward, backward, left, right, yes, and no.";
	cout << "\n3. If you want to pick up the item, type take.";
	cout << "\n4. If you want to see your inventory, type inventory";
	cout << "\n5. To use item in your inventory type use and the symbol of that item. For example: use *";
	cout << "\n6. If you don't know where you are currently at, type location";
	cout << "\n7. !!!! The command is CASE and SPACE sensitive so type exactly as you see in this tutorial !!!!";
	cout << "\n8. If you want to see this tutorial again, type help.";
	cout << "\n\n\n                                                  Type next to continue!";
}

string input()
{
	cout << "\n\n>> ";
	getline(cin, userInput);
	return userInput;
}

void decision()
{
	if (userInput == "help")
		tutorial();
	else if (userInput == "next")
	{
		system("cls");
		mainMenu();
		showArea();
	}
	else if (userInput == "forward")
	{
		area -= 3;
		if (area >= 1 && area <= 9 && area != 1 && area != 3 && area != 4 && area != 6)
			showArea();
		else if (area == 1 || area == 3 || area == 4 || area == 6)
		{
			cout << "There is a wall there";
			area += 3;
		}
		else
		{
			cout << "There is a wall there";
			area += 3;
		}
	}
	else if (userInput == "backward")
	{
		area += 3;
		if (area >= 1 && area <= 9 && area != 4 && area != 6 && area != 7 && area != 9)
			showArea();
		else if (area == 4 || area == 6 || area == 7 || area == 9)
		{
			cout << "There is a wall there";
			area -= 3;
		}
		else
		{
			cout << "There is a wall there";
			area -= 3;
		}
	}
	else if (userInput == "left")
	{
		area -= 1;
		if (area >= 1 && area <= 9 && area != 3 && area != 6)
			showArea();
		else if (area == 3 || area == 6)
		{
			cout << "There is a wall there";
			area += 1;
		}
		else
		{
			cout << "There is a wall there";
			area += 1;
		}
	}
	else if (userInput == "right")
	{
		area += 1;
		if (area >= 1 && area <= 9 && area != 4 && area != 7)
			showArea();
		else if (area == 4 || area == 7)
		{
			cout << "There is a wall there";
			area -= 1;
		}
		else
		{
			cout << "There is a wall there";
			area -= 1;
		}
	}
	else if (userInput == "inventory")
	{
		showInventory();
	}
	else if (userInput == "take")
	{
		if (area == 1 && take[0] == 1)
		{
			if (index != maxBag && lockBedroom != 1)
			{
				take[0] = 0;
				inventory[index] = "*";
				index++;
				cout << "You have take a * key";
			}
			else if (index != maxBag && lockBedroom == 1)
			{
				cout << "The door is lock!";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else if (area == 3 && take[1] == 1)
		{
			if (index != maxBag && lockBalcony != 1)
			{
				take[1] = 0;
				inventory[index] = "*";
				index++;
				cout << "You have take a * key";
			}
			else if (index != maxBag && lockBalcony == 1)
			{
				cout << "The door is lock!";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else if (area == 4 && take[2] == 1)
		{
			if (index != maxBag)
			{
				take[2] = 0;
				inventory[index] = "$";
				index++;
				cout << "You have take a $ key";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else if (area == 6 && take[3] == 1)
		{
			if (index != maxBag)
			{
				take[3] = 0;
				inventory[index] = "#";
				index++;
				cout << "You have take a # key";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else if (area == 7 && take[4] == 1)
		{
			if (index != maxBag)
			{
				take[4] = 0;
				inventory[index] = "*";
				index++;
				cout << "You have take a * key";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else if (area == 9 && take[5] == 1)
		{
			if (index != 3 && lockStoreRoom != 1)
			{
				take[5] = 0;
				inventory[index] = "@";
				index++;
				cout << "You have take a @ key";
			}
			else if (index != maxBag && lockStoreRoom == 1)
			{
				cout << "The door is lock!";
			}
			else if (index == maxBag)
				cout << "Your inventory has reached max capacity";
			else
				cout << "You have already take the item";
		}
		else
			cout << "There is nothing here to take";
	}
	else if (userInput == "use *")
	{
		for (int i = 0; i < 3; i++)
		{
			if (inventory[i] == "*" && area == 2)
			{
				inventory[i] = "";
				index--;
				lockSecret -= 1;
				cout << "You have use an item in your inventory";
				break;
			}
			else if (inventory[i] == "*" && area != 2)
			{
				cout << "You can't use that item here";
				break;
			}
			else if (i == 2)
			{
				cout << "You don't have that item in your inventory";
			}
		}
	}
	else if (userInput == "use @")
	{
		for (int i = 0; i < 3; i++)
		{
			if (inventory[i] == "@" && area == 1)
			{
				inventory[i] = "";
				index--;
				lockBedroom -= 1;
				cout << "You have use an item in your inventory";
				break;
			}
			else if (inventory[i] == "@" && area != 1)
			{
				cout << "You can't use that item here";
				break;
			}
			else if (i ==2)
			{
				cout << "You don't have the item in your inventory";
			}
		}
	}
	else if (userInput == "use $")
	{
		for (int i = 0; i < 3; i++)
		{
			if (inventory[i] == "$" && area == 3)
			{
				inventory[index - 1] = "";
				index--;
				lockBalcony -= 1;
				cout << "You have use an item in your inventory";
				break;
			}
			else if (inventory[i] == "$" && area != 3)
			{
				cout << "You can't use that item here";
				break;
			}
			else if (i ==2)
			{
				cout << "You don't have the item in your inventory";
			}
		}
	}
	else if (userInput == "use #")
	{
		for (int i = 0; i < 3; i++)
		{
			if (inventory[i] == "#" && area == 9)
			{
				inventory[i] = "";
				index--;
				lockStoreRoom -= 1;
				cout << "You have use an item in your inventory";
				break;
			}
			else if (area != 9)
			{
				cout << "You can't use that item here";
				break;
			}
			else if (i == 2)
			{
				cout << "You don't have the item in your inventory";
			}
		}
	}
	else if (userInput == "yes" && area == 2)
	{
		if (lockSecret == 0)
		{
			cout << "\nYou win!!!\n";
			cout << "Thanks for playing !! See you again!\n";
			exit(0);
		}
		else
			cout << "You can't enter the room yet, there are still " << lockSecret << " lock left to open!";
	}
	else if (userInput == "no" && area == 2)
	{
		showArea();
	}
	else if (userInput == "location")
	{
		showArea();
	}
	else
		cout << "Syntax error, please try again or type help for more info";
}

void showArea()
{
	switch (area)
	{
	case 1: cout << "You are in the BEDROOM, it has a @ lock and you see a * key inside"; break;
	case 2: cout << "You see a SECRET ROOM, it has " << lockSecret << " of * lock, do you want to enter?"; break;
	case 3: cout << "You are in the BALCONY, it has a $ and you see a * key"; break;

	case 4: cout << "You are in the HALLWAY, you see a $ key"; break;
	case 5: cout << "You are in the CENTER"; break;
	case 6: cout << "You are in the LIVING ROOM, you see a # key"; break;

	case 7: cout << "You are in the kitchen and you see a * key"; break;
	case 8: cout << "You are in the MAIN HALL"; break;
	case 9: cout << "you are in the STORE ROOM, it has a # lock and you see a @ lock"; break;
	}
}

void showInventory()
{
	cout << "Here are items in your inventory: \n";
	for (int i = 0; i < maxBag; i++)
	{
		int c = i + 1;
		cout << c << ". " << inventory[i] << endl;
		c++;
	}
}
