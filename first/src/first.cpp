//============================================================================
// Name        : first.cpp
// Author      : Noopur R K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <vector>
#include <string>
#include <sstream>
#include "sequenceGenerator.h"
using namespace std;

#define MAX_SIZE_ARGUMENTS 8


void processArguments(vector<double> &input, char* argin[], int size);

int main(int argc, char * argv[])
{
	vector<double> inputVector;
	string outputFile = argv[8];

	processArguments(inputVector, argv, argc);
	sequenceGenerator seqGen(inputVector, outputFile);
	seqGen.generate();
}

void processArguments(vector<double> &input, char* argin[], int size)
{
	if(size < MAX_SIZE_ARGUMENTS)
		{
			cout << "Invalid number of arguments entered" << endl;
			exit(0);
		}

	double intermediate = 0;
	for(int i = 1,  j = 0; i < size - 1; ++i, ++j)
	{
		intermediate = stod(argin[i]);
		input.push_back(intermediate);
	}
}
