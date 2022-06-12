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

    bool is_valid_slot(const Position& start, const Position& end) const;
    //A-G, P, d, h, c, s, and the second position identifier is not P
    
    bool is_valid_num(const Position& start, const Position& end) const;
    //A-G: 1-13; P, d, h, c, s: 1

    bool is_valid_gen_slot(const Position& start, const Position& end) const;
    //uncover if needed
    
    bool is_valid_ace_slot(const Position& start, const Position& end) const;
    //uncover if needed

    bool make_move(const Position& start, const Position& end) const;

    bool end_of_game() const;

    void erase_table();

    void deal_new_cards() const;

  private:

    Table table;

    
    

		   
