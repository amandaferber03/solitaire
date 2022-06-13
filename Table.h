#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <utility>
#include <map>
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
            gen_slots = { {'A', std::vector<Card*> slot_1},
                          {'B', std::vector<Card*> slot_2},
                          {'C', std::vector<Card*> slot_3},
                          {'D', std::vector<Card*> slot_4},
                          {'E', std::vector<Card*> slot_5},
                          {'F', std::vector<Card*> slot_6},
                          {'G', std::vector<Card*> slot_7}};

            ace_slots = { {'h', std::vector<Card*> slot_hearts},
                          {'d', std::vector<Card*> slot_diamonds},
                          {'c', std::vector<Card*> slot_clubs},
                          {'s', std::vector<Card*> slot_spades}};
        }

        ~Table();

        void display() const;

        void change_location(const Position& start, const Position& end, Card* card);

        void create_deck();
        
        void erase_board();

        private:
        std::array<Card*, 52>deck;
        std::vector<Card*>pile;
        std::map<char, std::vector<Card*>>gen_slots;
        std::map<char, std::vector<Card*>>ace_slots;

    };
}
