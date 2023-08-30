// word-guesser.cpp : Defines the entry point for the application.
//

#include "../headers/word-guesser.h"
#include "../headers/vector-helper.h"

int main()
{
	VectorHelper wordVector;
	wordVector.generate();
	wordVector.display();

	return 0;
}
