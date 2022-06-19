#include <iostream>
#include <utility>
#include <map>
//#include "Terminal.h"
#include <vector>
#include "Table.h"
#include "CreateCard.h"
#include "Exceptions.h"
#include <string>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

namespace Solitaire
{
    void Table::create_deck() {
        int j = 0;
        std::vector<char> card_identifiers{'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'A'};
        std::map<std::string, std::vector<char>> deck_model;
        deck_model["hearts"] = card_identifiers;
        deck_model["diamonds"] = card_identifiers;
        deck_model["clubs"] = card_identifiers;
        deck_model["spades"]= card_identifiers;

        for(std::map<std::string, std::vector<char>>::iterator it = deck_model.begin(); 
            it != deck_model.end();
            it++) {
                for(int i = 0; i < 13; i++) {
                    deck[j] = std::make_pair(it->second[i], it->first);
                    j++;
                }
            }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
        j = 0;
        slots['A'].push_back(create_card(deck[j].first, deck[j].second));
        j++;
        (slots['A'])[0]->change_covered();
        for(int i = 0; i < 2; i++) {
            slots['B'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['B'])[1]->change_covered();
        for(int i = 0; i < 3; i++) {
            slots['C'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['C'])[2]->change_covered();
        for(int i = 0; i < 4; i++) {
            slots['D'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['D'])[3]->change_covered();    
        for(int i = 0; i < 5; i++) {
            slots['E'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['E'])[4]->change_covered();
        for(int i = 0; i < 6; i++) {
            slots['F'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['F'])[5]->change_covered();
        for(int i = 0; i < 7; i++) {
            slots['G'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['G'])[6]->change_covered();
        for(int i = 0; i < 24; i++) {
            pile.push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
    }
    void Table::change_location(const Position& start, const char& end, std::vector<Card*> moving_cards) {
        if(start.first == 'P') {
            int index = 0;
            for(int i = 0; i < pile.size(); i++) {
                if( pile[i]->is_covered() == false) {
                    index = i;
                }
            }
            pile.erase(pile.begin() + index);
        }
        else {
            for(int i = 0; i < moving_cards.size(); i++) {
                slots[start.first].pop_back();
            }
        }
        for(int i = 0; i < moving_cards.size(); i++) {
            slots[end].push_back(moving_cards[moving_cards.size() - 1 - i]);
        }

        
    }

    void Table::erase_table() {
        for(int i = 0; i < pile.size(); i++) {
            delete pile[i];
        }

        for(std::map<char, std::vector<Card*>>::iterator it = slots.begin();
            it != slots.end();
            it++) {
                for(std::vector<Card*>::iterator it_vec = (it->second).begin(); 
                    it_vec != (it->second).end();
                    it_vec++) {
                        delete *it_vec;
                }
        }
    }

    void Table::deal_new_cards() {
        int size = pile.size();
        int index = 0; 
        while((pile[size - index - 1])->is_covered() == false) {
            index++; 
        }
        for(int i = index; i < index + 3; i++) {
            (pile[size - index - 1])->change_covered();
        }

    }
    
    bool Table::is_winner() {
        for(int i = 1; i < 5; i++) {
            if ((slots[single_card_piles[i]]).size() != 13) {
                return false;
            }
        }
        return true;
    }

    void Table::make_move(const Position& start, const char& end) {
        is_valid_pos(start, end);
        is_valid_order(start, end);
        std::vector<Card*> moving_cards; 
        if(start.first == 'P') {
            int index = 0;
            for(int i = 0; i <  pile.size(); i++) {
                if( pile[i]->is_covered() == false) {
                    index = i;
                }
            }
            moving_cards.push_back( pile[index]);
        }
        else if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end() && start.first != 'P') {
            int size =  slots[start.first].size();
            moving_cards.push_back((slots[start.first])[size - 1]);
             change_location(start, end, moving_cards);
        }
        else {
            int size =  slots[start.first].size();
            for(int i = 0; i < start.second; i++) {
                moving_cards.push_back(( slots[start.first])[size - 1 - i]);
            }
             change_location(start, end, moving_cards);
            ( slots[start.first])[size - 1]->change_covered();
        }
        
     }

    void Table::is_valid_order(const Position& start, const char& end) const {
        char start_upper;
        char end_lower;
        int index = -1;
        bool start_red;
        std::string start_suit;
        bool is_king = false ;
        if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end()) {//in the single card piles
            if (end == 'P') {
                for(int i = 0; i <  pile.size(); i++) {
                    if( pile[i]->is_covered() == false) {
                        index = i;
                    }
                }
                if(index == -1) {
                    throw Exception("no cards available to be moved from deck");
                }
                start_upper =  pile[index]->get_upper();
                start_red =  pile[index]->is_red();
                start_suit =  pile[index]->get_suit();
                is_king = 'K' ==  pile[index]->to_ascii();
                }
            else {
                int size =  slots[start.first].size();
                if(size == 0) {
                    throw Exception("no cards available to be moved from ace slot ");
                }
                if(( slots[start.first])[size - 1]->is_covered()) {
                    throw Exception("cannot move covered card(s)");
                }
                start_upper = ( slots[start.first])[size - 1]->get_upper();
                start_red = ( slots[start.first])[size - 1]->is_red();
                start_suit = ( slots[start.first])[size - 1]->get_suit();
                is_king = 'K' == ( slots[start.first])[size - 1]->to_ascii();
            }
        }
        else {//in the general slots
            int size2 =  slots[start.first].size();
            start_upper =  slots[start.first][size2 - start.second]->get_upper();
            start_red = ( slots[start.first])[size2 - start.second]->is_red();
            start_suit = ( slots[start.first])[size2 - start.second]->get_suit();
            is_king = 'K' == ( slots[start.first])[size2 - start.second]->to_ascii();
        }
        if (std::find(single_card_piles.begin(), single_card_piles.end(), end) != single_card_piles.end()) {
            int size3 =  slots[end].size();
            if(size3 == 0) {
                end_lower = '2';
            }
            else {
                end_lower = ( slots[end])[size3 - 1]->get_lower();
            }
            if(end_lower != start_upper) {
                throw Exception("improper order of card values");
            }
            if(start_suit != ( slots[end])[size3 - 1]->get_suit()) {
                throw Exception("incorrect suit");
            }
        }
        else {
            if(!is_king &&  slots[end].size() == 0) {
                throw Exception("only a King can be placed in an empty slot");
            }
            for(int i = 0; i <  slots[end].size(); i++) {
                if( slots[end][i]->is_covered() == false) {
                    end_lower =  slots[end][i]->get_lower();  
                    if(end_lower != start_upper) {
                        throw Exception("improper order of card values");
                    }
                    if(start_red == ( slots[end])[i]->is_red()) {
                        throw Exception("colors do not alternate");
                    }                  
                    break;
                }
            }     
        }
    }
}


