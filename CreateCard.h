#ifndef CREATE_CARD_H
#define CREATE_CARD_H
#include <string>
#include "Card.h"

namespace Solitaire
{
  Card* create_card(const char& card_designator, const std::string& suit_designator);
}
#endif
