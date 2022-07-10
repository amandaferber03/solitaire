#include <iostream>
#include <utility>
#include <map>
#include "Terminal.h"
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

    void Table::deal_new_cards(int& begin) {
        if(begin == 1) {
            for(int i = 0; i < pile.size(); i++ ) {
                pile[i]->change_covered();
            }
            begin = 0; 
            return;
        }
        int index = 0; 
        while((pile[index])->is_covered() == false) {
            index++; 
        }
        for(int i = index; i < index + 3; i++) {
            if(i < pile.size()) {
                (pile[i])->change_covered();
            }
        }
        if(pile[pile.size() - 1]->is_covered() == false) {
            begin = 1; 
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
    std::string Table::get_string(std::string suit) {
        if(suit == "hearts") {
            return "\u2665";
        }
        else if(suit == "diamonds") {
            return "\u2666";
        }
        else if(suit == "clubs") {
            return "\u2663";
        }
        else {
            return "\u2660";
        }
    }
    void Table::display() {
        std::cout << std::endl;
        std::string gen = "\U0001F0A0";
        int count = 0; 
        int pile_index = 0;
        Terminal::color_bg(Terminal::WHITE);
        Terminal::color_fg(true, Terminal::MAGENTA);
        std::cout << gen.c_str();
        Terminal::set_default();
        std::cout << "    ";
        std::vector<int> last_uncovered;
        for(int i = pile.size() - 1; i >= 0; i--) {
            if(pile[i]->is_covered() == false) {
                if(count == 3) {
                    break;
                }
                last_uncovered.push_back(i);
                count++;
            }
        }
        for(int i = last_uncovered.size() - 1; i >= 0; i--) {
            Terminal::color_bg(Terminal::WHITE);
            if(pile[last_uncovered[i]]->is_red() == true) {
                Terminal::color_fg(true, Terminal::RED);
            }
            else {
                Terminal::color_fg(true, Terminal::BLACK);
            }
            std::cout << pile[last_uncovered[i]]->to_unicode().c_str();
            pile_index = last_uncovered[i];
            Terminal::set_default();
            std::cout << " ";
        }
        for(int i = 0; i < 16 - (2 * count); i++) {
            std::cout << " ";
        }
        std::vector<std::string> suit_icons = { "\u2665", "\u2666", "\u2663", "\u2660"};
        std::vector<char> suit_identifiers = {'h', 'd', 'c', 's'};
        std::vector<int> last_indices;
        int last_index = 0;
        std::vector<bool> has_cards;
        for(int i = 0; i < 4; i++) {
            if(i < 2){
                Terminal::color_fg(true, Terminal::RED);
            }
            else {
                Terminal::color_fg(true, Terminal::BLACK);
            }
            if(slots[suit_identifiers[i]].empty() == true) {
                std::cout << suit_icons[i].c_str();
                has_cards.push_back(false);
            }
            else{
                has_cards.push_back(true);
                Terminal::color_bg(Terminal::WHITE);
                for(int j = slots[suit_identifiers[i]].size() - 1; j >= 0; j--) {
                    if(slots[suit_identifiers[i]][j]->is_covered() == false) {
                        last_indices.push_back(j);
                        last_index = j;
                        break;
                    }
                }
                std::cout << slots[suit_identifiers[i]][last_index]->to_unicode().c_str(); 
            }
            Terminal::set_default();
            std::cout << "      "; 
        }
        std::cout << std::endl;
        if(count > 0) {
            std::cout << "    ";
            for(int i = 1; i < count; i++) {
                std::cout << "  ";
            }
            std::cout << pile[pile_index]->to_ascii() << pile[pile_index]->get_suit();
        }
        else {
            std::cout << "              ";
        }
        std::cout << "     ";
        int k = 0;
        for(int i = 0; i < 4; i++) {
            if(i == 0) {
                std::cout << "       ";
            }
            if (has_cards[i]) {
                std::cout << slots[suit_identifiers[i]][last_indices[k]]->to_ascii() << slots[suit_identifiers[i]][last_indices[i]]->get_suit();
                k++
            }
            if(i > 0 && && k > 0 !has_cards[k-1]) {
                std::cout << "       ";
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
        int large_slot = 0;
        for(int i = 0; i < 7; i++) {
            if(slots[chars[i]].size() > large_slot) {
                large_slot = slots[chars[i]].size();
            }
        }
        last_indices.clear();
        for(int i = 0; i < 7; i++) {
            std::cout << chars[i] << "      ";
        }
        std::cout << std::endl;
        for(int i = 0; i < large_slot; i++) {
            for(int j = 0; j < 7; j++) {
                if(i >= slots[chars[j]].size()) {
                    if(i == 6 && slots[chars[j]].empty()) {
                    }
                    std::cout << "       ";
                    continue;
                }
                Terminal::color_bg(Terminal::WHITE);
                if(slots[chars[j]][i]->is_covered() == true) {
                    Terminal::color_fg(true, Terminal::MAGENTA);
                    std::cout << gen.c_str();
                }
                else {
                    if(slots[chars[j]][i]->is_red() == true) {
                        Terminal::color_fg(true, Terminal::RED);
                    }
                    else {
                        Terminal::color_fg(true, Terminal::BLACK);
                    }
                    std::cout << slots[chars[j]][i]->to_unicode().c_str();
                }
                Terminal::set_default();
                std::cout << "      ";
            }
            std::cout << std::endl;
        }
        for(int i = 0; i < 7; i++) {
            if(slots[chars[i]].size() > 0) {
                if(slots[chars[i]][slots[chars[i]].size() - 1]->is_red() == true) {
                    Terminal::color_fg(true, Terminal::RED);
                }
                else {
                    Terminal::color_fg(true, Terminal::BLACK);
                }
                std::cout << slots[chars[i]][slots[chars[i]].size() - 1]->to_ascii();
                std::cout << get_string(slots[chars[i]][slots[chars[i]].size() - 1]->get_suit()).c_str();
                Terminal::set_default();
            }
            else {
                std::cout << "NA";
            }
            std::cout << "     ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void Table::make_move(const Position& start, const char& end) {
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
            change_location(start, end, moving_cards);
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
             size = slots[start.first].size();
             if(size > 0 && (slots[start.first])[size - 1]->is_covered() == true) {
                (slots[start.first])[size - 1]->change_covered();
             }
        }
        
     }

    void Table::is_valid_order(const Position& start, const char& end) {
        char start_upper;
        char end_lower;
        int index = -1;
        bool start_red;
        std::string start_suit;
        bool is_king = false ;
        int size2 =  slots[start.first].size();
        if (std::find(single_card_piles.begin(), single_card_piles.end(), start.first) != single_card_piles.end()) {//in the single card piles
            if (start.first == 'P') {
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
            start_red = ( slots[start.first])[size2 - start.second]->is_red();
            start_suit = ( slots[start.first])[size2 - start.second]->get_suit();
            is_king = 'K' == ( slots[start.first])[size2 - start.second]->to_ascii();
        }
        if (std::find(single_card_piles.begin(), single_card_piles.end(), end) != single_card_piles.end()) {
            int size3 =  slots[end].size();
            if(start.first != 'P') {
                start_upper =  slots[start.first][size2 - start.second]->get_lower();
            }
            else {
                start_upper = pile[index]->get_lower();
            }
            
            if(size3 == 0) {
                end_lower = '?';
            }
            else {
                end_lower = ( slots[end])[size3 - 1]->to_ascii();
            }
            if(end_lower != start_upper) {
                throw Exception("improper order of card values");
            }
            if(size3 > 0 && start_suit != ( slots[end])[size3 - 1]->get_suit()) {
                throw Exception("incorrect suit");
            }
            else if(size3 == 0) {
                switch(end) {
                    case 'd': {
                        if(start_suit != "diamonds") {
                            std::cout << start_suit << std::endl;
                            throw Exception("incorrect suit");
                        }
                        break;
                    }
                    case 'h' : {
                        if(start_suit != "hearts") {
                            std::cout << start_suit << std::endl;
                            throw Exception("incorrect suit");
                        }
                        break;
                    }
                    case 'c': {
                        if(start_suit != "clubs") {
                            std::cout << start_suit << std::endl;
                            throw Exception("incorrect suit");
                        }
                        break;
                    }
                    case 's': {
                        if(start_suit != "spades") {
                            std::cout << start_suit << std::endl;
                            throw Exception("incorrect suit");
                        }
                        break;
                    }
                }
            }
        }
        else {
            if(start.first != 'P') {
                start_upper =  slots[start.first][size2 - start.second]->get_upper();
            }
            if(is_king == false &&  slots[end].size() == 0) {
                throw Exception("only a King can be placed in an empty slot");
            }
            else if(is_king == true && slots[end].size() == 0) {
                return;
            }
            index = 0;
            for(int i = 0; i <  slots[end].size(); i++) {
                if( slots[end][i]->is_covered() == false) {
                    index = i; 
                }
            }
            end_lower =  slots[end][index]->to_ascii();  
            if(end_lower != start_upper) {
                throw Exception("improper order of card values");
            }
            if(start_red == ( slots[end])[index]->is_red()) {
                throw Exception("colors do not alternate");
            }                  
        }
    }     
}


