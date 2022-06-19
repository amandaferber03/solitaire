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

        Table() {}

        ~Table();

        //void display()  ;

        void change_location(  Position& start,   char& end, std::vector<Card*> moving_cards);

        void create_deck();
        
        void erase_table();

        
        std::array<std::pair<char, std::string>, 52>deck;
        std::vector<Card*>pile;
        std::map<char, std::vector<Card*>>slots;

    };
}
#endif
