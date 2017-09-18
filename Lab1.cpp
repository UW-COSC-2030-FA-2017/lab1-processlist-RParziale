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

	cout << fileName << endl;

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
				cout << output;
				length++;
			}


		}
		
		//Resting the input stream to the beginning of the file
		inFile.clear();
		inFile.seekg(0, ios::beg);

		//Going through the file again to get the
		//first, second, second to last, and last numbers in the file.
		//Which can't be the best way to do this, but I'm stuck.
		int x = 0;
		while (!inFile.eof())
		{

			inFile >> output;
			//Clearing errors from the input stream
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore();
			}
			else
			{
				//First number
				if (x == 0)
				{
					num1 = output;
				}
				//Second number
				if (x == 1)
				{
					num2 = output;
				}
				//Second to last number
				if (x == (length - 2))
				{
					num3 = output;
				}
				//Last number
				if (x == (length - 1))
				{
					num4 = output;
				}
			}

			x++;
		}



	}
	//Close the file
	inFile.close();

	cout << "The number of numbers in the file is: " << length << endl;
	cout << "The first two numbers in the file are: " << num1 << " " << num2 << endl;
	cout << "The last two numbers in the file are: " << num3 << " " << num4 << endl;
	return 0;
}
	