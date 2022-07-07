#ifndef ACE_H
#define ACE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Ace : public Card {

  public:

    char to_ascii() const override { return 'A'; }

    char get_upper() const override { return '2'; }

    char get_lower() const override { return '?'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B1";
      }
      else if (get_suit()== "diamonds") {
        return "\U0001F0C1";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D1";
      }
      else {
        return "\U0001F0A1";
      }
    }
      Ace(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
