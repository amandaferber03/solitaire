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
            slot_identifiers = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'P', 'd', 'h', 'c', 's'};
            single_card_piles = {'P', 'd', 'h', 'c', 's'};
            valid_numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        }


        void change_location(const Position& start, const char& end, std::vector<Card*> moving_cards);

        void create_deck();
        
        void erase_table();

        void display(); 

        void deal_new_cards(int& deal_begin);

        bool is_winner();

        void make_move(const Position& start, const char& end);

        void is_valid_order(const Position& start, const char& end);
        
        private:
        
        std::array<std::pair<char, std::string>, 52>deck;
        std::vector<Card*>pile;
        std::map<char, std::vector<Card*>>slots;
        std::vector<char> slot_identifiers;
        std::vector<char> single_card_piles;
        std::vector<int> valid_numbers;


    };
}
#endif
