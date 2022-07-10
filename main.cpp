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
    std::cout << "\t                where <move> is a three character string with no spaces." << std::endl;
    std::cout << "\t                The first two characters give the origin position" << std::endl;
    std::cout << "\t                of a card and the last character gives its destination position." << std::endl;
    std::cout << "\t                The two-character origin position identifier indicates a" << std::endl;
    std::cout << "\t                location identifier and a number of cards." << std::endl;
    std::cout << "\t                A location identifier can be a 'P' for leftover pile, " << std::endl;
    std::cout << "\t                a lowercase ['d', 'h', 'c', or 's'] for ace slots (indicating the suit), " << std::endl;
    std::cout << "\t                or an uppercase ['A' - 'G'] for one of the seven table slots, " << std::endl;
    std::cout << "\t                where 'A' is the leftmost slot and 'G' is the rightmost slot. The number of " << std::endl;
    std::cout << "\t                cards can be a 1 for deck, a 1 for ace slots, " << std::endl;
    std::cout << "\t                and either a [1 - 13] for origin slots or 1 for destination slots." << std::endl;
    std::cout << "\t                The one-character destination identifier indicates a location identifier listed above." << std::endl;               
    std::cout << "\t'N':            issue new 3-card draw" << std::endl;
    std::cout << "\tExamples:       Let's say I wanted to move a stack of three cards from slot F to slot B." << std::endl;
    std::cout << "\t                My command would be 'M F3B'. If I wanted to move an available ace of hearts" << std::endl;
    std::cout << "\t                from the deck to the appropriate ace slot, my command would be 'M P1h'." << std::endl;
    std::cout << "\t                Lastly, if I wanted to move a card from the deck to slot C, my command" << std::endl;
    std::cout << "\t                would be 'M P1C'. Good luck!" << std::endl; 
}

int main() {
  Solitaire::Game game;
  //show_commands();
  bool game_end = false;
  int deal_begin = 0;

  while(game_end == false) {

    game.display();
    
    if(game.is_winner()) {
      std::cout << "congratulations! you're a winner" << std::endl;
      game_end = true;
      break;
    }

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
      case 'N': case 'n':
        game.deal_new_cards(deal_begin);
        break;
      case 'M': case 'm': {
        std::string arg;
        std::cin >> arg; 
	      std::stringstream argument;
        argument << arg;
        char start1;
        int start2 = 0;
        char end1;
        argument >> start1 >> start2 >> end1;
	      try{
	        game.make_move(std::make_pair(start1, start2), end1);
	      }
	      catch (const std::exception& e) {
	        std::cerr << "Could not make move: " << e.what() << std::endl;
	      }
	    }
	      break;
      default:
	      std::cerr << "Invalid action '" << choice << "'" << std::endl;
    }
  }
  }
  game.erase_table();  
  return 0; 
}

