#ifndef SEVEN_H
#define SEVEN_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Seven : public Card {

  public:

    char to_ascii() const override { return '7'; }

    char get_upper() const override { return '8'; }

    char get_lower() const override { return '6'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B7";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C7";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D7";
      }
      else {
        return"\U0001F0A7";
      }
    }
      Seven(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
