#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void Print_Star(vector<float>& data); //Print_Star uses a reference parameter to pass the value of the vector "data" to the Print_Star function.

int main()
{
	ifstream inFile;
	bool isNumber;
	float temp;
	vector <float> data{};

	inFile.open("test.txt");

	if (!inFile) {
		cout << "Input file failed to open.";
		return 1;
	}

	inFile >> temp;

	//EOF controlled while loop that reads in data from input file and adds it to vector that stores temps.
	while (inFile) {
		data.push_back(temp); //Adds every data type read in from the input file to the vector "data".
		inFile >> temp; //Reads new value in from input file. Also functions as loop control when file reaches EOF.
	}

	//Heading and x-axis of bar graph.
	cout << "Temperatures for 24 hours: \n";
	cout << setw(7) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	Print_Star(data);

	cout << "\n###############\n";
	cout << "1 * = 3 degrees";
	cout << "\n###############";

	return 0;
}

void Print_Star(vector<float>& data)
{
	//Range based for loop that loops through each item in the vector named "data" that stored temps from input file. Values in "data" are also used to calculate star output.
	for (auto val : data) {

		string starOutput; //Stores stars for output to the console.
		starOutput = ""; //Resets the string that stars are stored in every iteration through the ranged based for loop on the vector "data".

		cout << val << ":"; //Prints out the vertical axis of the graph.

		//This for loop takes the temperature read from the input file and divides it by three to get the correct number of degrees per star (1 star = 3 deg).
		for (int i = 1; i <= (abs(val) / 3.0); ++i) { //Temperatures are converted to their absolute value, then divided by three for each star to represent 3 degrees.
			starOutput.append("*"); //For every iteration that i is less than or equal to the temp divided by three, a star is added to the string starOutput.
		}

		//Following if else ladder prints the corressponding temperature and number of stars associated with that value
		if (val == -30) {
			cout << setw(10) << starOutput + "|";
		}
		else if (val > -30 && val <= -10) {
			cout << setw(11) << starOutput + "|";
		}
		else if (val > -10 && val < 0) {
			cout << setw(12) << starOutput + "|";
		}
		else if (val >= 0 && val < 10) {
			cout << setw(13) << "|" << starOutput;
		}
		else if (val >= 10 && val < 100) {
			cout << setw(12) << "|" << starOutput;
		}
		else if (val >= 100 && val <= 120) {
			cout << setw(11) << "|" << starOutput;
		}
		
		cout << endl;
	}
}