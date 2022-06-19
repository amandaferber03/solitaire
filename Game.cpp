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
    
    void Game::deal_new_cards() {
        int size = table.pile.size();
        int index = 0; 
        while((table.pile[size - index - 1])->is_covered() == false) {
            index++; 
        }
        for(int i = index; i < index + 3; i++) {
            (table.pile[size - index - 1])->change_covered();
        }

    }
    
    bool Game::is_winner() const {
        for(int i = 1; i < 5; i++) {
            if ((table.slots[single_card_piles[i]]).size() != 13) {
                return false;
            }
        }
        return true;
    }
     
    void Game::make_move(const Position& start, const char& end) {
        is_valid_pos(start, end);
        is_valid_order(start, end);
        std::vector<Card*> moving_cards; 
        if(start.first == 'P') {
            int index = 0;
            for(int i = 0; i < table.pile.size(); i++) {
                if(table.pile[i]->is_covered() == false) {
                    index = i;
                }
            }
            moving_cards.push_back(table.pile[index]);
        }
        else if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end() && start.first != 'P') {
            int size = table.slots[start.first].size();
            moving_cards.push_back((table.slots[start.first])[size - 1]);
            table.change_location(start, end, moving_cards);
        }
        else {
            int size = table.slots[start.first].size();
            for(int i = 0; i < start.second; i++) {
                moving_cards.push_back((table.slots[start.first])[size - 1 - i]);
            }
            table.change_location(start, end, moving_cards);
            (table.slots[start.first])[size - 1]->change_covered();
        }
        
     }

    void Game::is_valid_order(const Position& start, const char& end) const {
        char start_upper;
        char end_lower;
        int index = -1;
        bool start_red;
        std::string start_suit;
        bool is_king = false ;
        if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end()) {//in the single card piles
            if (end == 'P') {
                for(int i = 0; i < table.pile.size(); i++) {
                    if(table.pile[i]->is_covered() == false) {
                        index = i;
                    }
                }
                if(index == -1) {
                    throw Exception("no cards available to be moved from deck");
                }
                start_upper = table.pile[index]->get_upper();
                start_red = table.pile[index]->is_red();
                start_suit = table.pile[index]->get_suit();
                is_king = 'K' == table.pile[index]->to_ascii();
                }
            else {
                int size = table.slots[start.first].size();
                if(size == 0) {
                    throw Exception("no cards available to be moved from ace slot ");
                }
                if((table.slots[start.first])[size - 1]->is_covered()) {
                    throw Exception("cannot move covered card(s)");
                }
                start_upper = (table.slots[start.first])[size - 1]->get_upper();
                start_red = (table.slots[start.first])[size - 1]->is_red();
                start_suit = (table.slots[start.first])[size - 1]->get_suit();
                is_king = 'K' == (table.slots[start.first])[size - 1]->to_ascii();
            }
        }
        else {//in the general slots
            int size2 = table.slots[start.first].size();
            start_upper = table.slots[start.first][size2 - start.second]->get_upper();
            start_red = (table.slots[start.first])[size2 - start.second]->is_red();
            start_suit = (table.slots[start.first])[size2 - start.second]->get_suit();
            is_king = 'K' == (table.slots[start.first])[size2 - start.second]->to_ascii();
        }
        if (std::find(single_card_piles.begin(), single_card_piles.end(), end) != single_card_piles.end()) {
            int size3 = table.slots[end].size();
            if(size3 == 0) {
                end_lower = '2';
            }
            else {
                end_lower = (table.slots[end])[size3 - 1].]->get_lower();
            }
            if(end_lower != start_upper) {
                throw Exception("improper order of card values");
            }
            if(start_suit != (table.slots[end])[size3 - 1]->get_suit()) {
                throw Exception("incorrect suit");
            }
        }
        else {
            if(!is_king && table.slots[end].size() == 0) {
                throw Exception("only a King can be placed in an empty slot");
            }
            for(int i = 0; i < table.slots[end].size(); i++) {
                if(table.slots[end][i]->is_covered() == false) {
                    end_lower = table.slots[end][i]->get_lower();  
                    if(end_lower != start_upper) {
                        throw Exception("improper order of card values");
                    }
                    if(start_red == (table.slots[end])[i]->is_red()) {
                        throw Exception("colors do not alternate");
                    }                  
                    break;
                }
            }     
        }
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