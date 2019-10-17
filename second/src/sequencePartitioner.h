/*
 * sequencePartitioner.h
 *
 *  Created on: Oct 15, 2019
 *      Author: noopurrkalawatia
 */
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <iostream>
#include <fstream>


using namespace std;

#ifndef SEQUENCEPARTITIONER_H_
#define SEQUENCEPARTITIONER_H_
#define MAX_LENGTH_FASTA 80


class sequencePartitioner
{
private:
    string inputFile;
    string outputFile;
    int minFragmentLength;
    int maxFragmentLength;
    string bulk;
    void convertToFASTA(string input);
    void writeToFile(string input);
    void readContentsOfFile(string inputFile);
    void generateRandomNumber(int &num);
    void performFragmentation();


public:
    sequencePartitioner(string _inputFile, int _interval1, int _interval2, string _outputFile);
    virtual ~sequencePartitioner();
    void displayDetails();
    void performPartition();
};

#endif /* SEQUENCEPARTITIONER_H_ */
