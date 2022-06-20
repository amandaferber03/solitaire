#include <cassert>
#include "Game.h"
#include <string>
#include <cctype> 
#include <iostream>
#include <algorithm>

namespace Solitaire {
    Game::Game() {
        table.create_deck();
        slot_identifiers = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'P', 'd', 'h', 'c', 's'};
        single_card_piles = {'P', 'd', 'h', 'c', 's'};
        valid_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    }

    void Game::erase_table() {
        table.erase_table();
    }
    
    void Game::deal_new_cards(int& deal_begin) {
        table.deal_new_cards(deal_begin);

    }
    
    bool Game::is_winner() {
        return table.is_winner();
    }
     
    void Game::make_move(const Position& start, const char& end) {
        is_valid_pos(start, end);
        table.make_move(start, end);
     }

    void Game::is_valid_order(const Position& start, const char& end) {
        table.is_valid_order(start, end);
    }

    void Game::is_valid_pos(const Position& start, const char& end) {
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
            if(std::find(valid_numbers.begin(), valid_numbers.end(), start.second) == valid_numbers.end()) {
               throw Exception("invalid number of cards identified"); 
            }
        }
    }
}