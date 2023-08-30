#include "../headers/vector-helper.h"

VectorHelper::VectorHelper()
{
    std::ifstream wordsStream("../../../../words.txt"); // Reading from build folder
	if (!wordsStream) {
		std::cerr << "Cannot read 'words.txt'. Please make sure file is present in root directory";
	}

	std::istream_iterator<std::string> start(wordsStream), end;
	allWordsVector = std::vector<std::string>(start, end);
	wordsStream.close();

	std::random_device dev;
	rng = std::mt19937(dev());
}

void VectorHelper::generate()
{
	randomWordsMemoryVector.clear();
	for (int i = 0; i < sizeOfMemoryVector; i++) {
		randomWordsMemoryVector.push_back(allWordsVector
			.at(getRandomIndex(allWordsVector.size())));
	}
}

std::vector<std::string> VectorHelper::getVector()
{
	return randomWordsMemoryVector;
}

void VectorHelper::display()
{
	for (auto& word : randomWordsMemoryVector) {
		std::cout << word << ", ";
	}
	std::cout << std::endl;
}

std::string VectorHelper::getRandomWord()
{
	randomWordToGuess = randomWordsMemoryVector.at(getRandomIndex(sizeOfMemoryVector - 1));
	return randomWordToGuess;
}

std::string VectorHelper::getCoveredWord()
{
	std::string coveredWord = randomWordToGuess;
	for (int i = 0; i < (std::floor(randomWordToGuess.size() / 2) - 1); i++) {
		coveredWord[getRandomIndex(randomWordToGuess.size() - 1)] = '-';
	}

	return coveredWord;
}

int VectorHelper::getRandomIndex(int distributionCeiling)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, distributionCeiling);
	return dist(rng);
}
