#include <cassert>
#include "Game.h"
#include <string>
#include <cctype> 
#include <iostream>
#include <algorithm>

namespace Solitaire {
    Game::Game() {
        table.create_deck();
    }

    void Game::erase_table() {
        table.erase_table();
    }
    
    void Game::deal_new_cards() {
        table.deal_new_cards();

    }
    
    bool Game::is_winner() const {
        table.is_winner();
    }
     
    void Game::make_move(const Position& start, const char& end) {
        is_valid_order(start, end);
        table.make_move();
     }

    void Game::is_valid_order(const Position& start, const char& end) const {
        table.is_valid_order();
    }

    void Game::is_valid_pos(const Position& start, const char& end) const {
        if(std::find(slot_identifiers.begin(), slot_identifiers.end(), start.first) == slot_identifiers.end()) {
            throw Exception("invalid origin location identifier");
        }

        if((end == 'P') || (std::find(slot_identifiers.begin(), slot_identifiers.end(), end) == slot_identifiers.end())) {
            throw Exception("invalid destination location identifier");
        }

        if(std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end()) {
            if(start.second != 1) {
                throw Exception("invalid number of cards identified");
            }
        }
        else {
            if(std::find(valid_numbers.begin(), valid_numbers.end(), start.second) == single_card_piles.end()) {
               throw Exception("invalid number of cards identified"); 
            }
        }
    }
}