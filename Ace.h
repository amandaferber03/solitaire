#ifndef ACE_H
#define ACE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Ace : public Card {

  public:

    char to_ascii() const override { return "A"; }

    char get_lower() const override { return "2"; }

    char get_upper() const override { return "?"; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B1";
      }
      else if (suit == "diamonds") {
        return "\u1F0C1";
      }
      else if (suit == "clubs") {
        return "\u1F0A1";
      }
      else {
        return"\u1F0D1";
      }
    }
    private:
      Ace(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
