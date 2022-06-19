#ifndef SIX_H
#define SIX_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Six : public Card {

  public:

    char to_ascii()   override { return '6'; }

    char get_upper()   override { return '7'; }

    char get_lower()   override { return '5'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
        return "\u1F0B6";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0C6";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0A6";
      }
      else {
        return"\u1F0D6";
      }
    }
    private:
      Six(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
