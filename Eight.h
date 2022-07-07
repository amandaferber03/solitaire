#ifndef EIGHT_H
#define EIGHT_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Eight : public Card {

  public:

    char to_ascii() const override { return '8'; }

    char get_upper() const override { return '9'; }

    char get_lower() const override { return '7'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B8";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C8";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D8";
      }
      else {
        return"\U0001F0A8";
      }
    }
      Eight(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
