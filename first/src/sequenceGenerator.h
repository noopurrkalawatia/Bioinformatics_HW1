/*
 * sequenceGenerator.h
 *
 *  Created on: Oct 15, 2019
 *      Author: noopurrkalawatia
 */

#ifndef SEQUENCEGENERATOR_H_
#define SEQUENCEGENERATOR_H_

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

#define MAX 4
#define MAX_LENGTH_FASTA 80
#include <random>

struct sequenceInformation
{
	double seqLength;
	double adenineFraction;
	double cytosineFraction;
	double guanineFraction;
	double thymineFraction;
	double noOfFractions;
	double mutualProbability;
};

class sequenceGenerator
{
private:
	sequenceInformation seqInfo;
	string outputFilePath;
	unordered_map<char,double> nucleotidePro;

	void generateFirstRandomSeq(string &result, int length);
	void convertToFASTA(string input);
	void generateRemainingSeq(string input, int length);
	void generateRandomLetter(char &c);
	void simulateCoinToss(double &result);
	void writeToFile(string input);

public:
	sequenceGenerator(vector<double> inputVector, string outputFile);
	virtual ~sequenceGenerator();
	void generate();
	void displayDetails();

};

#endif /* SEQUENCEGENERATOR_H_ */
