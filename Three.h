#ifndef THREE_H
#define THREE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Three : public Card {

  public:

    char to_ascii() const override { return "3"; }

    char get_upper() const override { return "4"; }

    char get_lower() const override { return "2"; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B3";
      }
      else if (suit == "diamonds") {
        return "\u1F0C3";
      }
      else if (suit == "clubs") {
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
