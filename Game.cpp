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
    
    void 

    void is_valid_order(const Position& start, const Position& end) const {
        char start_upper = '';
        char end_lower = '';
        int index = -1;
        bool start_red;
        std::string start_suit;
        if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end()) {//in the single card piles
            if (end.first == 'P') {
                for(int i = 0; i < table.pile.size(); i++) {
                    if(table.pile[i].covered() == false) {
                        index = i;
                    }
                }
                if(index == -1) {
                    throw Exception("no cards available to be moved from deck");
                }
                start_upper = table.pile[i].get_upper();
                start_red = table.pile[i].is_red();
                start_suit = table.pile[i].get_suit();
                }
            else {
                int size = table.slots[start.first].size();
                if(size == 0) {
                    throw Exception("no cards available to be moved from ace slot ");
                }
                start_upper = (table.slots[start.first])[size - 1].get_upper();
                start_red = (table.slots[start.first])[size - 1].is_red();
                start_suit = (table.slots[start.first])[size - 1].get_suit();
            }
        }
        else {//in the general slots
            int size2 = table.slots[start.first].size();
            start_upper = table.slots[start.first][size2 - start.second].get_upper();
            start_red = (table.slots[start.first])[size2 - start.second].is_red();
            start_suit = (table.slots[start.first])[size2 - start.second].get_suit();
        }
        if (std::find(single_card_piles.begin(), single_card_piles.end(), end.first) != single_card_piles.end()) {
            int size2 = table.slots[end.first].size();
            if(size2 == 0) {
                end_lower = '2';
            }
            else {
                end_lower = (table.slots[end.first])[size2 - 1].get_lower();
            }
            if(end_lower != start_upper) {
                throw Exception("cannot place card in ace slot: improper order of card values");
            }
            if(start_suit != (table.slots[end.first])[size2 - 1].get_suit()) {
                throw Exception("cannot place card in ace slot: incorrect suit");
            }
        }
        else {
            for(int i = 0; i < table.slots[end.first].size(); i++) {
                if(table.slots[end.first][i].covered() == false) {
                    end_lower = table.slots[end.first][i].get_lower();  
                    if(end_lower != start_upper) {
                        throw Exception("cannot place card in slot: improper order of card values");
                    }
                    if(start_color == (table.slots[end.first])[size2 - 1].is_red()) {
                        throw Exception("cannot place card in slot: colors do not alternate");
                    }                  
                    break;
                }
            }     
        }
    }
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