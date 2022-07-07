#ifndef FOUR_H
#define FOUR_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Four : public Card {

  public:

    char to_ascii() const override { return '4'; }

    char get_upper() const override { return '5'; }

    char get_lower() const override { return '3'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B4";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C4";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D4";
      }
      else {
        return "\U0001F0A4";
      }
    }
      Four(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
