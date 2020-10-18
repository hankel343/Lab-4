/*******************************************************************************************************
* Hankel Haldin
* Lab 4: Printing a bar graph that models hourly temperatures read from an input file of temperatures
* Due: 10/19/2020
* Program reads in hourly temperatures from an input file and outputs a bar graph of hourly temperatures
********************************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <math.h>
/*****************************************************************************************************************************
*I choose to use a vector to store temperatures because I could have the data set of all temperatures in one location and then 
*iterate through the vector's elements using a range based for loop.
******************************************************************************************************************************/

using namespace std;

void Print_Star(vector<float>& data); //Print_Star uses a reference parameter to pass the value of the vector "data" to the Print_Star function.

int main()
{
	ifstream inFile;
	string fileName;
	float temp;
	vector <float> data{};

	cout << "Enter the name of your input file: ";
	cin >> fileName;

	inFile.open(fileName.c_str());

	//In the following block the user either enters a valid file name or decides to terminate program in this loop when the input stream is in the failed state.
	if (!inFile) {
		do
		{
			cout << "The input file failed to open.\n";
			cout << "Try again to enter the file name or alternatively enter 'Q' or 'q' to terminate this program.\n\n";
			cout << "File name:";
			cin >> fileName;

			if (fileName == "Q" || fileName == "q") { //User decides to terminate program.
				cout << "Goodbye.";
				return 1; //Terminates program.
			}

			inFile.open(fileName.c_str()); //Attempts to open file stream again
		} while (!inFile); 
	}

	cout << "\n\nOpening file..."; //Program successfully finds input file.

	inFile >> temp; //Priming read for data input in the coming while loop.

	//EOF controlled while loop that reads temperatures in from input file and adds them to a vector
	while (inFile)
	{
		data.push_back(ceil(temp)); //The ceil function rounds any floating point input from the input file to the next highest value.
		inFile >> temp;
	}

	//Heading and x-axis of bar graph.
	cout << "\n\n\nTemperatures for 24 hours: \n";
	cout << setw(7) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	//Prints y-axis of hourly temperatures and a corresponding number of stars.
	Print_Star(data);

	cout << "\n#############\n";
	cout << "* = 3 degrees";
	cout << "\n#############";

	return 0;
}

void Print_Star(vector<float>& data)
{
	//Range based for loop that loops through each item in the vector named "data" that stored temps from input file. Values in "data" are also used to calculate star output.
	for (auto val : data) {

		string starOutput; //Stores stars for output to the console.
		starOutput = ""; //Resets the string that stars are stored in every iteration through the ranged based for loop on the vector "data".

		//Following if statements vet out any values out of range -30 to 120 so they don't appear on the graph.
		if (val < -30 || val > 120) {
			continue; //Tells compiler to skip body of loop and return to loop condition of first for loop.
		} else {
			cout << val << ":";
		}

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
		else if (val > 120) {
			continue;
		}
		
		cout << endl;
	}
}