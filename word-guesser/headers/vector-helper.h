#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>

class VectorHelper {
	public:
		VectorHelper();
		std::vector<std::string> getWordVector();
		std::string getRandomWordFromVector();

	private:
		int getRandomIndex(int distributionCeiling);

		std::vector<std::string> allWordsVector;
		std::vector<std::string> randomWordsMemoryVector;
		std::string randomWordToGuess;

		std::mt19937 rng;
};