#ifndef THREE_H
#define THREE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Three : public Card {

  public:

    char to_ascii() const override { return '3'; }

    char get_upper() const override { return '4'; }

    char get_lower() const override { return '2'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B3";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C3";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D3";
      }
      else {
        return "\U0001F0A3";
      }
    }
      Three(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
