// word-guesser.cpp : Defines the entry point for the application.
//

#include "../headers/word-guesser.h"
#include "../headers/vector-helper.h"

int main()
{
	VectorHelper wordVector;

	std::cout << "Welcome to Word Guesser!" << std::endl;
	std::cout << "You will be given a list of words and then 3 rounds of a word being shown from that list with letters missing, you have to guess that word." << std::endl;
	std::cout << "You will be given 15 seconds to memorise the list." << std::endl;

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

		int amountCorrect = 0;
		std::string givenWord = "";
		for (int i = 0; i < 3; i++) {
			std::cout << "Round " << i + 1 << std::endl;
			randomWord = wordVector.getRandomWord();
			std::cout << wordVector.getCoveredWord() << std::endl;

			std::cout << "Enter the full word." << std::endl;
			std::cin >> givenWord;
			if (givenWord == randomWord) {
				amountCorrect++;
				std::cout << "That is correct." << std::endl;
			}
			else {
				std::cout << "That is incorrect." << std::endl;
			}

			std::cout << std::string(10, '\n');
		}

		std::cout << "Type 'y' to continue, or type 'exit' to stop";
		std::cin >> answer;
	}

	return 0;
}
