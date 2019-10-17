/*
 * sequencePartitioner.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: noopurrkalawatia
 */

#include "sequencePartitioner.h"

using namespace std;

sequencePartitioner::sequencePartitioner(string _inputFile, int _interval1,
        int _interval2, string _outputFile)
{
    inputFile = _inputFile;
    outputFile = _outputFile;
    minFragmentLength = _interval1;
    maxFragmentLength = _interval2;
}

void sequencePartitioner::displayDetails()
{
    cout << "Input file is : " << this->inputFile << endl;
    cout << "Maximum Fragment length is : " << this->maxFragmentLength << endl;
    cout << "Minimum Fragment Length is : " << this->minFragmentLength << endl;
    cout << "Output File is  : " << this->outputFile << endl;
}

void sequencePartitioner::performPartition()
{
    readContentsOfFile(inputFile);
    performFragmentation();
}

void sequencePartitioner::performFragmentation()
{
    string intermediate;

    while(bulk.size() > 0)
    {
        int start = 0;
        int partition = 0;
        generateRandomNumber(partition);
        if(bulk.size() < partition)
        {
            bulk.erase(bulk.begin(),bulk.end());
            return;
        }
        intermediate = bulk.substr(start,partition);
        bulk.erase(bulk.begin(),bulk.begin() + partition);
        start = partition + 1;
        convertToFASTA(intermediate);
    }
}

void sequencePartitioner::readContentsOfFile(string inputFile)
{
    ifstream myFile(inputFile + ".txt");
    /*
     * Read the contents of the file and fragment these fragments line by line and
     * output it to the output file specified. Discard the segments of lesser length.
     * Generate a random number between the minimum interval and maximum interval.
     */
    string line;
    if (myFile.is_open())
    {
        while (getline(myFile,line))
        {
            if(line.find(">") == std::string::npos)
            {
                bulk += line;
            }
            line = "";
        }
        myFile.close();
    }
    else
    {
        cout << "Error opening the file" << endl;
    }
}

void sequencePartitioner::generateRandomNumber(int &num)
{
    const int maximum_number = this->maxFragmentLength;
    const int minimum_number = this->minFragmentLength;

    num = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
}

void sequencePartitioner::convertToFASTA(string input)
{
    /*
     * Append '>' in the beginning of the format and one line should consist of only
     * 80 characters at a time.
     */

    string start = ">";
    string intermediate;
    writeToFile(start);

    for (int i = 0; i < input.size(); i += MAX_LENGTH_FASTA - 1)
    {
        intermediate = "";
        for (int j = i; j < i + MAX_LENGTH_FASTA - 1; ++j)
        {
            intermediate += input[j];
        }
        writeToFile(intermediate);
    }
}

void sequencePartitioner::writeToFile(string input)
{
    ofstream myfile(this->outputFile + ".txt",
            std::ofstream::out | std::ofstream::app);
    int n = input.length();
    cout << "size of the segment is : " << n << endl;
    char char_array[n + 1];
    strcpy(char_array, input.c_str());

    if (myfile.is_open()) {
        myfile << char_array;
        myfile << "\n";
    }
    myfile.close();
}

sequencePartitioner::~sequencePartitioner()
{
    // TODO Auto-generated destructor stub
}

