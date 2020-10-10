#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Function protoype:
string PrintStar(int temp);
int starSort(int temp);

int main()
{
	ifstream inFile;
	unsigned temp;
	inFile.open("test.txt");

	inFile >> temp;	//Reads in integer values stored in "test.txt"
	while (inFile)
	{
		cout << PrintStar(temp) << endl; //Passes integer temp value as an argument to printStar()
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