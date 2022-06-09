#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
//#include "Game.h"

void show_commands() {
	std::cout << "List of commands:" << std::endl;
	std::cout << "\t'?':            show this list of options" << std::endl;
	std::cout << "\t'Q':            quit the game" << std::endl;
	std::cout << "\t'M' <move>:     try to make the specified move" << std::endl;
	std::cout << "\t                where <move> is a six character string." << std::endl;
	std::cout << "\t                The first three characters giving the origin position" << std::endl;
    std::cout << "\t                of a card and the last three giving its destination position." << std::endl;
    std::cout << "\t                Each three character position identifier indicates a" << std::endl;
    std::cout << "\t                location type, location identifier, and a number of cards." << std::endl;
    std::cout << "\t                A location type can be either a 'D' for deck, " << std::endl;
    std::cout << "\t                an 'A' for ace slots, or an  'S' for slots." << std::endl;
    std::cout << "\t                A location identifier can be either an additional 'D' for deck, " << std::endl;
    std::cout << "\t                a ['D', 'H', 'C', or 'S'] for ace slots indicating the suit, " << std::endl;
    std::cout << "\t                or an ['A' - 'G'] for slots, where 'A' is the leftmost " << std::endl;
    std::cout << "\t                pile and 'G' is the rightmost pile. The number of " << std::endl;
    std::cout << "\t                cards can be a '1' for deck, a '1' for ace slots, " << std::endl;
    std::cout << "\t                and either a ['1' - '13'] for origin slots or '1' for destination slots." << std::endl;
    std::cout << "\t'N':            issue new 3-card draw" << std::endl;
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