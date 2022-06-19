#ifndef NINE_H
#define NINE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Nine : public Card {

  public:

    char to_ascii()   override { return '9'; }

    char get_upper()   override { return 'T'; }

    char get_lower()   override { return '8'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
        return "\u1F0B9";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0C9";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0A9";
      }
      else {
        return"\u1F0D9";
      }
    }
    private:
      Nine(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
