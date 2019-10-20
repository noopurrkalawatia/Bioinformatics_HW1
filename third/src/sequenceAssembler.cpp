/*
 * sequenceAssembler.cpp
 *
 *  Created on: Oct 19, 2019
 *      Author: noopurrkalawatia
 */

#include "sequenceAssembler.h"

sequenceAssembler::sequenceAssembler(string inFile,int match,
        signed int replace, signed int deleteScore,
        string outFile)
{
    inputFile = inFile;
    outputFile = outFile;
    scoreMatch = match;
    penaltyReplace = replace;
    penaltyDelete = deleteScore;
}

void sequenceAssembler::displayDetails()
{
    cout << "Input file name is : " << inputFile << endl;
    cout << "Output File name is : " << outputFile << endl;
    cout << "Match score is  : " << scoreMatch << endl;
    cout << "Penalty for Replace is :  " << penaltyReplace << endl;
    cout << "Penalty for Delete is : " << penaltyDelete << endl;
}

int sequenceAssembler::initialiseGlobalAlignmentMatrix(string s1,string s2)
{
    cout << "initialiseGlobalAlignmentMatrix" << endl;
}

sequenceAssembler::~sequenceAssembler()
{
    // TODO Auto-generated destructor stub
}

