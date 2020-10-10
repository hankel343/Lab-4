#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Function protoype:
string PrintStar(int temp);

int main()
{
	ifstream inFile;
	unsigned temp;
	inFile.open("test.txt");

	inFile >> temp;	//Reads in integer values stored in "test.txt"
	while (inFile)
	{
		if (temp >= -30 && temp < -20)
		{
			cout << PrintStar(temp);
		}
		else if (temp >= -20 && temp < 0)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 0)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 1)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 2)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 3)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 4)
		{
			cout << PrintStar(temp);
		}
		else if (temp == 5)
		{
			cout << PrintStar(temp);
		}
		else if (temp >= 5 && temp < 10)
		{
			cout << PrintStar(temp);
		}
		else if (temp >= 10 && temp < 50)
		{
			cout << PrintStar(temp);
		}
		else if (temp >= 50 && temp <= 100)
		{
			cout << PrintStar(temp);
		}
		//Passes integer temp value as an argument to printStar()
		inFile >> temp; //Reads next integer value in test.txt
	}

	cout << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120";
	cout << endl << "-30" << setw(7) << "|" << endl;
	cout << "-20" << setw(7) << "|" << endl;
	cout << "0" << setw(9) << "|" << endl;
	cout << "1" << setw(9) << "|" << endl;
	cout << "2" << setw(9) << "|" << endl;
	cout << "3" << setw(9) << "|" << endl;
	cout << "4" << setw(9) << "|" << endl;
	cout << "5" << setw(9) << "|" << endl;
	cout << "10" << setw(8) << "|" << endl;
	cout << "50" << setw(8) << "|" << endl;
	cout << "100" << setw(7) << "|" << endl;

	return 0;
}

string PrintStar(int temp)
{
	string star = "";
	for (int i = 1; i <= temp; ++i)
	{
		star.append("*");
	}

	return star;
}