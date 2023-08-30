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

std::vector<std::string> VectorHelper::getWordVector()
{
	return allWordsVector;
}

std::string VectorHelper::getRandomWordFromVector()
{
	return std::string();
}

int VectorHelper::getRandomIndex(int distributionCeiling)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, distributionCeiling);
	return dist(rng);
}
