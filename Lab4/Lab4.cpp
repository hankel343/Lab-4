/*******************************************************************************************************
* Hankel Haldin
* Lab 4: Printing a bar graph that models hourly temperatures read from an input file of temperatures
* Due: 10/19/2020
* Program reads in hourly temperatures from an input file and outputs a bar graph of hourly temperatures
********************************************************************************************************/

#include <iostream>
#include <fstream> //File I/O
#include <string> //c++ string method .append() is used to store stars in a string
#include <iomanip> //Formating graph
#include <cctype> //Used for error checking

using namespace std;

//Function Prototypes.

int ErrorCheck(ifstream& inFile);
//Precondition: File name that user types in able to be found.
//Postcondition: All data in the input file is error free (correct data type) and can be used to print the graph.

void PrintGraph(ifstream& inFile, string fileName);
//Precondition: Input file has appropriate data.
//Postcondition: Print bar graph representing temperatures over 24 hours.

int main()
{
	ifstream inFile;
	string fileName;

	//Following do-while prompts user for filename.
	do
	{
		cout << "Enter the name of your input file: ";
		cin >> fileName;
		inFile.open(fileName.c_str());

		if (!inFile)
		{
			cout << "Input file failed to open. Make sure you typed its name correctly and that the input file exists.\n";
			cout << "Try again or press 'Q' to quit: ";
			cin >> fileName;
			cout << "\n\n\n";

			if (fileName == "Q" || fileName == "q") //User terminates program. 
			{
				cout << "Goodbye...\n\n\n";
				return 1; //User terminates program.
			}
			inFile.open(fileName.c_str());
		}
	} while (!inFile);


	/*********************************************************************************************************
	*ErrorCheck is a value returning function of type int.
	*It returns 1 if an error is present, so the if statement terminates the program if the call is equal to 1
	**********************************************************************************************************/
	if (ErrorCheck(inFile) == 1)
	{
		return 1;
	}

	//Print graph reads data in from the input file, determines how many stars are needed, and then prints the graph to the screen.
	PrintGraph(inFile, fileName);

	return 0;
}

int ErrorCheck(ifstream& inFile)
{
	char errorCheck;
	//Priming read for vetting values in input file
	inFile >> errorCheck;

	//Following while loop reads does an initial read through the input file to determine if any invalid data types are present.
	while (inFile)
	{
		if (isalpha(errorCheck)) //True when input character is a letter.
		{
			cout << "\n\n\n###ERROR###\n";
			cout << "*********************************************************************************************\n";
			cout << "The input stream has encountered an invalid input type " << "'" << errorCheck << "'" << " in the input stream.\n";
			cout << "Ensure that the input file only contains data of type integer or float.\n";
			cout << "*********************************************************************************************\n";
			return 1; //Errors were found in the input file and program terminates.
		}
		inFile >> errorCheck;
	}
	inFile.close();
	return 0; //Means no errors where found in the input file.
}

void PrintGraph(ifstream& inFile, string fileName)
{
	float temp;

	cout << "\nOpening file...";


	//Heading for graph.
	cout << "\n\nTemperatures for 24 hours: \n";
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;

	inFile.open(fileName.c_str());
	inFile >> temp;

	while (inFile)
	{
		temp = ceil(temp); //Ceil is used to round any floating point values to a whole number. Avoids graph being off due to decimal char.

		string starOutput; //Stores stars
		starOutput = ""; //Resets the contents of the string every iteration.

		//The following if else block functions as a way to vet out of bound temperatures from the input file.
		if (temp < -30 || temp > 120) { //If temp is too high or low, a new value is read in from the input file and then iteration of the outer while loop begins again.
			inFile >> temp;
			continue; //Tells compiler to skip body of loop and return to loop condition of first for loop.

		}
		else { //temp in range
			cout << temp << ":";
		}

		//This for loop is used to get the correct amount of stars per degree.
		for (int i = 1; i <= (abs(temp) / 3.0); ++i) //abs() is used to calculate values for negative inputs.
		{
			starOutput.append("*"); //Appends a star to a string called starOutput every time the loop iterates.
		}

		//Following if else ladder prints the corressponding temperature and number of stars associated with that value
		if (temp == -30) {
			cout << setw(12) << starOutput + "|";
		}
		else if (temp > -30 && temp <= -10) {
			cout << setw(12) << starOutput + "|";
		}
		else if (temp > -10 && temp < 0) {
			cout << setw(13) << starOutput + "|";
		}
		else if (temp >= 0 && temp < 10) {
			cout << setw(14) << "|" << starOutput;
		}
		else if (temp >= 10 && temp < 100) {
			cout << setw(13) << "|" << starOutput;
		}
		else if (temp >= 100 && temp <= 120) {
			cout << setw(12) << "|" << starOutput;
		}

		cout << endl;
		inFile >> temp;
	}
	inFile.close();
}