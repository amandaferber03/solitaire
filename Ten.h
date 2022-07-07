#ifndef TEN_H
#define TEN_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Ten : public Card {

  public:

    char to_ascii() const override { return 'T'; }

    char get_upper() const override { return 'J'; }

    char get_lower() const override { return '9'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\U0001F0BA";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0CA";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0DA";
      }
      else {
        return"\U0001F0AA";
      }
    }
      Ten(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
