/*
 * sequenceAssembler.h
 *
 *  Created on: Oct 19, 2019
 *      Author: noopurrkalawatia
 */

#ifndef SEQUENCEASSEMBLER_H_
#define SEQUENCEASSEMBLER_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class sequenceAssembler
{
private:
    string inputFile;
    string outputFile;
    int scoreMatch;
    signed int penaltyReplace;
    signed int penaltyDelete;

    int initialiseGlobalAlignmentMatrix(string s1,string s2);

public:
    sequenceAssembler(string inFile,int match,
            signed int replace, signed int deleteScore,
            string outFile);
    void displayDetails();
    virtual ~sequenceAssembler();
};

#endif /* SEQUENCEASSEMBLER_H_ */
