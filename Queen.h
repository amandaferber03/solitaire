#ifndef QUEEN_H
#define QUEEN_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Queen : public Card {

  public:

    char to_ascii() const override { return 'Q'; }

    char get_upper() const override { return 'K'; }

    char get_lower() const override { return 'J'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\u1F0BD";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0CD";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0AD";
      }
      else {
        return"\u1F0DD";
      }
    }
    private:
      Queen(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
