#ifndef FIVE_H
#define FIVE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Five : public Card {

  public:

    char to_ascii()   override { return '5'; }

    char get_upper()   override { return '6'; }

    char get_lower()   override { return '4'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
        return "\u1F0B5";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0C5";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0A5";
      }
      else {
        return"\u1F0D5";
      }
    }
    private:
      Five(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
