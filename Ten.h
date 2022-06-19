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
        return "\u1F0BA";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0CA";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0AA";
      }
      else {
        return"\u1F0DA";
      }
    }
    private:
      Ten(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
