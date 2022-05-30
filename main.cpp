#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include "Game.h"

void show_commands() {
	std::cout << "List of commands:" << std::endl;
	std::cout << "\t'?':            show this list of options" << std::endl;
	std::cout << "\t'Q':            quit the game" << std::endl;
	std::cout << "\t'M' <move>:     try to make the specified move" << std::endl;
	std::cout << "\t                <move> is a six character string giving the" << std::endl;
	std::cout << "\t                location type of the cards to be moved" << std::endl;
    std::cout << "\t                ('D' for deck, 'S' for slots, and 'A' for ace slots)," << std::endl;
    std::cout << "\t                the location identifier ('D' for deck," << std::endl;
    std::cout << "\t                ['A' - 'G'] for slots, and ['D', 'H', 'C', or 'S'] for ace slots)," << std::endl;
    std::cout << "\t                and the number of cards identified ('1' for deck, '1' for ace slots," << std::endl;
    std::cout << "\t                and either ['1' - '19'] for origin slots or '1' for destination slots)" << std::endl;
    std::cout << "\t                for both the origin cards and the destination location." << std::endl; 
    std::cout << "\t'N':            issue new 3-card draw"
    std::cout << "\tExamples:       Let's say I wanted to move a stack of three cards from slot F to slot B." << std::endl;
    std::cout << "\t                My command would be 'M SF3SB1'. If I wanted to move an available ace of hearts" << std::endl;
    std::cout << "\t                from the deck to the appropriate ace slot, my command would be 'M DD1AH1'." << std::endl;
    std::cout << "\t                Lastly, if I wanted to move a card from the deck to slot C, my command" << std::endl;
    std::cout << "\t                would be 'M DD1SC1'. Good luck!" << std::endl; 
}

int main(int argc, char* argv[]) {
    show_commands();
    return 0; 
}