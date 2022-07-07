#ifndef FIVE_H
#define FIVE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Five : public Card {

  public:

    char to_ascii() const override { return '5'; }

    char get_upper() const override { return '6'; }

    char get_lower() const override { return '4'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B5";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C5";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D5";
      }
      else {
        return"\U0001F0A5";
      }
    }
      Five(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
