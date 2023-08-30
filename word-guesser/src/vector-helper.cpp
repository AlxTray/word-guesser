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

void VectorHelper::generateMemoryWordVector()
{
	randomWordsMemoryVector.clear();
	for (int i = 0; i < sizeOfMemoryVector; i++) {
		randomWordsMemoryVector.push_back(allWordsVector
			.at(getRandomIndex(allWordsVector.size())));
	}
}

std::vector<std::string> VectorHelper::getWordVector()
{
	return randomWordsMemoryVector;
}

std::string VectorHelper::getRandomWordFromVector()
{
	return randomWordsMemoryVector.at(getRandomIndex(sizeOfMemoryVector - 1));
}

int VectorHelper::getRandomIndex(int distributionCeiling)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, distributionCeiling);
	return dist(rng);
}
