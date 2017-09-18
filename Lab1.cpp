//Lab1.cpp
//Ryan Parziale
//COSC2030
//Lab01
//9-18-2017

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{

	string fileName; //Name of the file
	int length; //Number of numbers in the file
	double output, num1, num2, num3, num4; //First, second, second to last, and last numbers in the file
	ifstream inFile;


	length = 0;
	cout << "Enter the name of a file.\nThe number of numbers in the file\nand the first two and the last two numbers will be returned.\n" << endl;
	cin >> fileName;


	//Opening the file
	inFile.open(fileName);


	if (inFile.is_open())
	{
		while (!inFile.eof())
		{

			inFile >> output;

			
			//Clearing the input stream of errors
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore();
			}
			else
			{
				//Storing the first number
				if (length == 0)
				{
					num1 = output;
					length++;
				}
				//Storing the last number
				else
				{
					num4 = output;
					length++;
				}
			}

			inFile >> output;

			//Clearing the input stream of error
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore();
			}
			else
			{
				//Storing the second number
				if (length == 1)
				{
					num2 = output;
					length++;
				}
				//Storing the second to last number
				else
				{
					num3 = output;
					length++;
				}
			}


		}

	}
	
	//Close the file
	inFile.close();

	cout << "The number of numbers in the file is: " << length << endl;
	cout << "The first two numbers in the file are: " << num1 << " " << num2 << endl;
	cout << "The last two numbers in the file are: " << num3 << " " << num4 << endl;
	return 0;
}