//============================================================================
// Name        : second.cpp
// Author      : Noopur R K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "sequencePartitioner.h"
using namespace std;

#define MAX_SIZE_ARGUMENTS 5

int main(int argc, char *argv[])
{
	vector<double> input;

	if (argc < MAX_SIZE_ARGUMENTS)
	{
		cout << "Invalid number of arguments entered" << endl;
		exit(0);
	}

	string inputFile = argv[1];
	int interval1 = stoi(argv[2]);
	int interval2 = stoi(argv[3]);
	string outputFile = argv[argc - 1];

	sequencePartitioner seqPart(inputFile,interval1,interval2,outputFile);
	seqPart.displayDetails();
	seqPart.performPartition();
	return 0;
}


