#ifndef SEVEN_H
#define SEVEN_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Seven : public Card {

  public:

    char to_ascii()   override { return '7'; }

    char get_upper()   override { return '8'; }

    char get_lower()   override { return '6'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
        return "\u1F0B7";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0C7";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0A7";
      }
      else {
        return"\u1F0D7";
      }
    }
    private:
      Seven(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
