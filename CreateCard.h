#ifndef CREATE_CARD_H
#define CREATE_CARD_H
#include <string>
#include "Card.h"

namespace Solitaire
{
  Card* create_card(  char& card_designator,   std::string& suit_designator);
}
#endif
