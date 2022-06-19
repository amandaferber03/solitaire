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
      if(suit == "hearts") {
        return "\u1F0B4";
      }
      else if (suit == "diamonds") {
        return "\u1F0C4";
      }
      else if (suit == "clubs") {
        return "\u1F0A4";
      }
      else {
        return"\u1F0D4";
      }
    }
    private:
      Four(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
