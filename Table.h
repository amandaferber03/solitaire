#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <utility>
#include <map>
#include <array>
#include <vector>
#include "Card.h"
#include "King.h"
#include "Queen.h"
#include "Jack.h"
#include "Ten.h"
#include "Nine.h"
#include "Eight.h"
#include "Seven.h"
#include "Six.h"
#include "Five.h"
#include "Four.h"
#include "Three.h"
#include "Two.h"
#include "Ace.h"

namespace Solitaire
{
    class Table {
        public:

        Table() {
            std::vector<Card*> slot_1;
            std::vector<Card*> slot_2;
            std::vector<Card*> slot_3;
            std::vector<Card*> slot_4;
            std::vector<Card*> slot_5;
            std::vector<Card*> slot_6;
            std::vector<Card*> slot_7;
            std::vector<Card*> slot_hearts;
            std::vector<Card*> slot_diamonds;
            std::vector<Card*> slot_clubs;
            std::vector<Card*> slot_spades;
            slots = {     {'A',  slot_1},
                          {'B',  slot_2},
                          {'C',  slot_3},
                          {'D',  slot_4},
                          {'E',  slot_5},
                          {'F',  slot_6},
                          {'G',  slot_7}, 
                          {'h',  slot_hearts},
                          {'d',  slot_diamonds},
                          {'c',  slot_clubs},
                          {'s',  slot_spades}};
        }

        ~Table();

        //void display() const;

        void change_location(const Position& start, const char& end, std::vector<Card*> moving_cards);

        void create_deck();
        
        void erase_table();
        
        std::array<std::pair<char, std::string>, 52>deck;
        std::vector<Card*>pile;
        std::map<char, std::vector<Card*>>slots;

    };
}
#endif
