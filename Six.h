#ifndef SIX_H
#define SIX_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class SIX : public Card {

  public:

    char to_ascii() const override { return '6'; }

    char get_upper() const override { return '7'; }

    char get_lower() const override { return '5'; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B6";
      }
      else if (suit == "diamonds") {
        return "\u1F0C6";
      }
      else if (suit == "clubs") {
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
