#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>

class VectorHelper {
	public:
		VectorHelper();
		void generate();
		std::vector<std::string> getVector();
		void display();
		std::string getRandomWord();
		std::string getCoveredWord();

	private:
		int getRandomIndex(int distributionCeiling);

		std::vector<std::string> allWordsVector;
		std::vector<std::string> randomWordsMemoryVector;
		std::string randomWordToGuess;
		std::mt19937 rng;

		int sizeOfMemoryVector = 5;
};