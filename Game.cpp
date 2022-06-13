#include <cassert>
#include "Game.h"
#include <string>
#include <cctype> 
#include <iostream>

namespace Solitaire {
    Game::Game() {
        table.create_deck();
        pile_identifiers = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'P', 'd', 'h', 'c', 's'};
        single_card_piles = {'P', 'd', 'h', 'c', 's'}
        valid_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    }
    void Game::valid_pos(const Position& start, const Position& end) const {
        if(std::find(slot_identifiers.begin(), slot_identifiers.end(), start.first) == slot_identifiers.end()) {
            throw Exception("invalid origin location identifier");
        }

        if((end.first == 'P') || (std::find(slot_identifiers.begin(), slot_identifiers.end(), end.first) == slot_identifiers.end())) {
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
        if(end.second != 1) {
            throw Exception("invalid number of cards identified");
        }
    }
}