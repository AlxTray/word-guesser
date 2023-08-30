#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class VectorHelper {
	public:
		VectorHelper();
		std::vector<std::string> getWordVector();
		std::string getRandomWordFromVector();

	private:
		std::vector<std::string> allWordsVector;
		std::vector<std::string> randomWordsMemoryVector;
		std::string randomWordToGuess;
};