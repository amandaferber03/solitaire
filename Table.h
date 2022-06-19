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
            
            slots = {     {'A',  std::vector<Card*> slot_1},
                          {'B',  std::vector<Card*> slot_2},
                          {'C',  std::vector<Card*> slot_3},
                          {'D',  std::vector<Card*> slot_4},
                          {'E',  std::vector<Card*> slot_5},
                          {'F',  std::vector<Card*> slot_6},
                          {'G',  std::vector<Card*> slot_7}, 
                          {'h',  std::vector<Card*> slot_hearts},
                          {'d',  std::vector<Card*> slot_diamonds;},
                          {'c',  std::vector<Card*> slot_clubs},
                          {'s',  std::vector<Card*> slot_spades}};
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
