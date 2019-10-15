/*
 * sequenceGenerator.cpp
 *
 *  Created on: Oct 15, 2019
 *      Author: noopurrkalawatia
 */

#include "sequenceGenerator.h"

sequenceGenerator::sequenceGenerator(vector<double> inputVector,
		string outputFile) {
	cout << "constructor entered" << endl;
	seqInfo.seqLength = inputVector[0];
	seqInfo.adenineFraction = inputVector[1];
	seqInfo.cytosineFraction = inputVector[2];
	seqInfo.guanineFraction = inputVector[3];
	seqInfo.thymineFraction = inputVector[4];
	seqInfo.noOfFractions = inputVector[5];
	seqInfo.mutualProbability = inputVector[6];
	outputFilePath = outputFile;
}

void sequenceGenerator::displayDetails() {
	cout << "seqLength is : " << this->seqInfo.seqLength << endl;
	cout << "adenineFraction is : " << this->seqInfo.adenineFraction << endl;
	cout << "cytosineFraction is : " << this->seqInfo.cytosineFraction << endl;
	cout << "guanineFraction is : " << this->seqInfo.guanineFraction << endl;
	cout << "thymineFraction is : " << this->seqInfo.thymineFraction << endl;
	cout << "noOfFractions is : " << this->seqInfo.noOfFractions << endl;
	cout << "mutualProbability is : " << this->seqInfo.mutualProbability
			<< endl;
}

void sequenceGenerator::generate() {
	cout << "generate function entered" << endl;

	double sum = this->seqInfo.adenineFraction + this->seqInfo.cytosineFraction
			+ this->seqInfo.guanineFraction + this->seqInfo.thymineFraction;

	nucleotidePro['a'] = this->seqInfo.adenineFraction / sum;
	nucleotidePro['c'] = this->seqInfo.cytosineFraction / sum
			+ nucleotidePro['a'];
	nucleotidePro['g'] = this->seqInfo.guanineFraction / sum
			+ nucleotidePro['a'] + nucleotidePro['c'];
	nucleotidePro['t'] = this->seqInfo.thymineFraction / sum
			+ nucleotidePro['a'] + nucleotidePro['c'] + nucleotidePro['g'];

	string firstSeq;
	generateFirstRandomSeq(firstSeq, this->seqInfo.seqLength);
	generateRemainingSeq(firstSeq, this->seqInfo.noOfFractions);
}

void sequenceGenerator::generateFirstRandomSeq(string &result, int length) {
	char c;
	for (int i = 0; i < length; ++i)
	{
		generateRandomLetter(c);
		result += c;
	}
	convertToFASTA(result);
}

void sequenceGenerator::generateRandomLetter(char &c)
{
	std::random_device rd; //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

	if (dis(gen) < nucleotidePro['a'])
	{
		c = 'A';
	}

	else if (dis(gen) > nucleotidePro['a'] && dis(gen) <= nucleotidePro['c'])
	{
		c = 'C';
	}

	else if (dis(gen) > nucleotidePro['c'] && dis(gen) <= nucleotidePro['g'])
	{
		c = 'G';
	}

	else
	{
		c = 'T';
	}
}

void sequenceGenerator::generateRemainingSeq(string input, int length)
{
	double tossMutate = 0;
	double tossWhichMutate = 0;
	string master;
	for(int i = 0 ; i < length - 1; ++i)
	{
		master = input;
		for(int j = 0 ; j < master.size(); ++j)
		{
			simulateCoinToss(tossMutate);
			if(tossMutate < 0.5)
			{
				simulateCoinToss(tossWhichMutate);
				if(tossWhichMutate < 0.5)
				{
					generateRandomLetter(master[j]);
				}
				else
				{
					master.erase(master.begin() + j);
				}
			}
		}
		convertToFASTA(master);
	}
}

void sequenceGenerator::simulateCoinToss(double &result)
{
	std::random_device rd; //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);
	result = dis(gen);
}

void sequenceGenerator::convertToFASTA(string input)
{
	/*
	 * Append '>' in the beginning of the format and one line should consist of only
	 * 80 characters at a time.
	 */
	string start = ">";
	cout << start << endl;
	string intermediate;
	writeToFile(start);
	for (int i = 0; i < input.size(); i += MAX_LENGTH_FASTA - 1)
	{
		intermediate = "";
		for (int j = i; j < i + MAX_LENGTH_FASTA - 1; ++j)
		{
			intermediate += input[j];
		}
		cout << intermediate << endl;
		writeToFile(intermediate);
	}
}

void sequenceGenerator::writeToFile(string input)
{
	ofstream myfile(this->outputFilePath + ".txt", std::ofstream::out | std::ofstream::app);
	int n = input.length();
	char char_array[n + 1];
	strcpy(char_array, input.c_str());

	if (myfile.is_open())
	{
		myfile << char_array;
		myfile << "\n";
	}
	myfile.close();
}

sequenceGenerator::~sequenceGenerator()
{

}

