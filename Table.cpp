#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include "Terminal.h"
#include "Table.h"
#include "CreatePiece.h"
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
        (slots['A'])[0].covered = false;
        for(int i = 0; i < 2; i++) {
            slots['B'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['B'])[1].covered = false;
        for(int i = 0; i < 3; i++) {
            slots['C'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['C'])[2].covered = false;
        for(int i = 0; i < 4; i++) {
            slots['D'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['D'])[3].covered = false;    
        for(int i = 0; i < 5; i++) {
            slots['E'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['E'])[4].covered = false;
        for(int i = 0; i < 6; i++) {
            slots['F'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['F'])[5].covered = false;
        for(int i = 0; i < 7; i++) {
            slots['G'].push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
        (slots['G'])[6].covered = false;
        for(int i = 0; i < 24; i++) {
            pile.push_back(create_card(deck[j].first, deck[j].second));
            j++;
        }
    }
}