#ifndef NINE_H
#define NINE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Nine : public Card {

  public:

    char to_ascii() const override { return '9'; }

    char get_upper() const override { return 'T'; }

    char get_lower() const override { return '8'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0B9";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0C9";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0D9";
      }
      else {
        return"\U0001F0A9";
      }
    }
      Nine(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
