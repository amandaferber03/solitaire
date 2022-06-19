#ifndef TWO_H
#define TWO_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Two : public Card {

  public:

    char to_ascii() const override { return '2'; }

    char get_upper() const override { return '3'; }

    char get_lower() const override { return 'A'; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B2";
      }
      else if (suit == "diamonds") {
        return "\u1F0C2";
      }
      else if (suit == "clubs") {
        return "\u1F0A2";
      }
      else {
        return"\u1F0D2";
      }
    }
    private:
      Two(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
