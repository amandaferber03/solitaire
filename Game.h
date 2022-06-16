#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Card.h"
#include "Table.h"
#include "Exceptions.h"

namespace Solitaire
{
  class Game {
  public:
    Game();

    void display() const { table.display(); }

    void valid_pos(const Position& start, const Position& end) const;
    //A-G, P, d, h, c, s, and the second position identifier is not P
    //A-G: 1-13; P, d, h, c, s: 1
    
    //start: last uncovered card of P, last card of [d, c, h, s] 
    //or the first uncovered card from A-G
    //end: last card of [d, c, h, s] or last card of A-G
    //start's upper should match end's lower
   
    void is_valid_order(const Position& start, const Position& end) const;
    //if the destination vector is empty, is the first (or only) start card a King?
    //are values in the correct order

    void make_move(const Position& start, const Position& end) const;
    //uncover if needed 

    bool end_of_game() const;

    void erase_table();

    void deal_new_cards() const;

  private:

    Table table;
    std::vector<char> slot_identifiers;
    std::vector<char> single_card_piles;
    std::vector<int> valid_numbers;
  };
}
#endif

    
    

		   
