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
    std::cout << "\t                where <move> is a four character string." << std::endl;
    std::cout << "\t                The first three characters give the origin position" << std::endl;
    std::cout << "\t                of a card and the last three give its destination position." << std::endl;
    std::cout << "\t                Each two character position identifier indicates a" << std::endl;
    std::cout << "\t                location identifier and a number of cards." << std::endl;
    std::cout << "\t                A location identifier can be a 'P' for leftover pile, " << std::endl;
    std::cout << "\t                a lowercase ['d', 'h', 'c', or 's'] for ace slots (indicating the suit), " << std::endl;
    std::cout << "\t                or an uppercase ['A' - 'G'] for one of the seven table slots, " << std::endl;
    std::cout << "\t                where 'A' is the leftmost slot and 'G' is the rightmost slot. The number of " << std::endl;
    std::cout << "\t                cards can be a '1' for deck, a '1' for ace slots, " << std::endl;
    std::cout << "\t                and either a ['1' - '13'] for origin slots or '1' for destination slots." << std::endl;
    std::cout << "\t'N':            issue new 3-card draw" << std::endl;
    std::cout << "\tExamples:       Let's say I wanted to move a stack of three cards from slot F to slot B." << std::endl;
    std::cout << "\t                My command would be 'M F3B1'. If I wanted to move an available ace of hearts" << std::endl;
    std::cout << "\t                from the deck to the appropriate ace slot, my command would be 'M P1h1'." << std::endl;
    std::cout << "\t                Lastly, if I wanted to move a card from the deck to slot C, my command" << std::endl;
    std::cout << "\t                would be 'M P1C1'. Good luck!" << std::endl; 
}

int main(int argc, char* argv[]) {
  Solitaire::Game game;
  show_commands();
  bool game_end = false;

  while(!game_end) {
    game.display();

    std::string choice;
    std::cout << "Next command: ";
    std::cin >> choice;

    if (choice.length() != 1) {
      std::cerr << "Action specifier must be a single character, but length(" << choice << ") = " << choice.length() << std::endl;
    } else {
      switch (choice[0]) {
      case '?':
	show_commands();
	break;
      case 'Q': case 'q':
	game_end = true;
	break;
      case 'M': case 'm': {
	std::string argument;
	std::cin >> argument;
	if (argument.length() != 4) {
	  std::cerr << "Move specifier must be four characters, but length(" << argument << " ) = " << argument.length() << std::endl;
	} else {
	  try{
	    game.make_move(std::make_pair(argument[0], argument[1]), std::make_pair(argument[2], argument[3]));
	  }
	  catch (const std::exception& e) {
	    std::cerr << "Could not make move: " << e.what() << std::endl;
	  }
	}
	break;
      }
      default:
	std::cerr << "Invalid action '" << choice << "'" << std::endl;
      }
    }
  }
  game.erase_board();  
  return 0; 
}
