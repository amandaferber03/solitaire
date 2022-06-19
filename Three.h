#ifndef THREE_H
#define THREE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Three : public Card {

  public:

    char to_ascii()   override { return '3'; }

    char get_upper()   override { return '4'; }

    char get_lower()   override { return '2'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
        return "\u1F0B3";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0C3";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0A3";
      }
      else {
        return"\u1F0D3";
      }
    }
    private:
      Three(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
