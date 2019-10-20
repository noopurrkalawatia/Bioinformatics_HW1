//============================================================================
// Name        : third.cpp
// Author      : Noopur R K
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "sequenceAssembler.h"
using namespace std;

#define MAX_SIZE_ARGUMENTS 6

void processArguments(vector<double> &input, char* argin[], int size);
int main(int argc, char *argv[])
{
    int size = argc;
    if(argc < MAX_SIZE_ARGUMENTS)
    {
        cout << "Invalid number of arguments entered" << endl;
        exit(0);
    }

    string inputFile = argv[1];
    int matchScore = stoi(argv[2]);
    signed int penReplace = stoi(argv[3]);
    signed int penDelete = stoi(argv[4]);
    string outputFile = argv[size - 1];

    sequenceAssembler seqAssembler(inputFile,matchScore,penReplace,penDelete,
            outputFile);

    seqAssembler.displayDetails();
}

void processArguments(vector<double> &input, char* argin[], int size)
{
    if(size < MAX_SIZE_ARGUMENTS)
        {
            cout << "Invalid number of arguments entered" << endl;
            exit(0);
        }

    double intermediate = 0;
    for(int i = 1, j = 0; i < size - 1; ++i, ++j)
    {
        intermediate = stod(argin[i]);
        input.push_back(intermediate);
    }
}
