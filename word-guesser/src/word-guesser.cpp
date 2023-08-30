// word-guesser.cpp : Defines the entry point for the application.
//

#include "../headers/word-guesser.h"
#include "../headers/vector-helper.h"

int main()
{
	VectorHelper wordVector;

	std::cout << "Welcome to Word Guesser!" << std::endl;
	std::cout << "You will be given a list of words and then a word from that list with letters missing, you have to guess that word." << std::endl;
	std::cout << "You will be given 5 seconds to memorise the list." << std::endl;

	std::cout << "Type anything to begin." << std::endl;
	std::string answer = "";
	std::cin >> answer;
	std::string randomWord = "";
	while (answer != "exit") {
		std::cout << std::string(5, '\n');
		wordVector.generate();
		wordVector.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // Pause for 5 seconds
		std::cout << std::string(30, '\n'); // Clear console

		randomWord = wordVector.getRandomWord();
		std::cout << wordVector.getCoveredWord() << std::endl;

		std::cout << "Type 'y' to continue, or type 'exit' to stop";
		std::cin >> answer;
	}

	return 0;
}
