#ifndef SIX_H
#define SIX_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Six : public Card {

  public:

    char to_ascii() const override { return '6'; }

    char get_upper() const override { return '7'; }

    char get_lower() const override { return '5'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B6";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C6";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D6";
      }
      else {
        return"\U0001F0A6";
      }
    }
      Six(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
