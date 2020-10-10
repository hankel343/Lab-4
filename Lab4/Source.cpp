#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Function protoype:
string StarSort(int temp);

ifstream inFile;
string lineNeg30, lineNeg20, line0, line1, line2, line3, line4, line5, line10, line50, line100;

int main()
{
	
	int temp;
	string stars;
	
	inFile.open("test.txt");
	inFile >> temp;	//Reads in integer values stored in "test.txt"

	while (inFile)
	{
		for (int i = 0; i < 1; ++i)
		{
			if (temp >= -30 && temp < 0)
			{
				lineNeg20.append("*");
			}
			else if (temp == 0)
			{
				line0.append("*");
			}
			else if (temp == 1)
			{
				line1.append("*");
			}
			else if (temp == 2)
			{
				line2.append("*");
			}
			else if (temp == 3)
			{
				line3.append("*");
			}
			else if (temp == 4)
			{
				line4.append("*");
			}
			else if (temp == 5)
			{
				line5.append("*");
			}
			else if (temp >= 5 && temp < 10)
			{
				line10.append("*");
			}
			else if (temp >= 10 && temp < 50)
			{
				line50.append("*");
			}
			else if (temp >= 50 && temp <= 100)
			{
				line100.append("*");
			}
		}
		inFile >> temp; //Reads next integer value in test.txt
	}

	cout << "Temperatures for 24 hours:\n";
	cout << setw(6) << "-30" << setw(12) << "0" << setw(12) << "30" << setw(12) << "60" << setw(12) << "90" << setw(12) << "120\n";
	cout << "-20    " << setw(11) << lineNeg20 + "|" << endl;
	cout << "0      " << setw(11) << "|" << line0 << endl;
	cout << "1      " << setw(11) << "|" << line1 << endl;
	cout << "2      " << setw(11) << "|" << line2 << endl;
	cout << "3      " << setw(11) << "|" << line3 << endl;
	cout << "4      " << setw(11) << "|" << line4 << endl;
	cout << "5      " << setw(11) << "|" << line5 << endl;
	cout << "10     " << setw(11) << "|" << line10 << endl;
	cout << "50     " << setw(11) << "|" << line50 << endl;
	cout << "100    " << setw(11) << "|" << line100 << endl;

	return 0;
}