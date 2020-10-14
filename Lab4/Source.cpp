#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ifstream inFile;
	float temp;
	vector <float> data{};

	inFile.open("test.txt");

	if (!inFile) {
		cout << "Input file failed to open.";
		return 1;
	}

	inFile >> temp;

	cout << setw(5) << "-30" << setw(7) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	while (inFile) {
		data.push_back(temp);
		inFile >> temp;
	}

	for (float val : data) {
		string starOutput;
		starOutput = "";
		cout << val << ":";

		for (int i = 1; i <= (abs(val) / 3.0); ++i) { //Temperatures are converted to their absolute value, then divided by three for each star to represent 3 degrees.
			starOutput.append("*");
		}
		if (val > -10 && val < 0) {
			cout << setw(9) << starOutput + "|";
		}
		else if (val < 10) {
			cout << setw(10) << "|" << starOutput;
		}
		else if (val >= 10 && val < 100) {
			cout << setw(9) << "|" << starOutput;
		}
		else if (val >= 100) {
			cout << setw(8) << "|" << starOutput;
		}
		cout << endl;
	}

	return 0;
}