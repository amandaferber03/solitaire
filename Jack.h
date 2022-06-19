#ifndef JACK_H
#define JACK_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Jack : public Card {

  public:

    char to_ascii() const override { return 'J'; }

    char get_upper() const override { return 'Q'; }

    char get_lower() const override { return 'T'; }

    std::string to_unicode() const override {
      if(get_suit() == "hearts") {
        return "\u1F0BB";
      }
      else if (get_suit() == "diamonds") {
        return "\u1F0CB";
      }
      else if (get_suit() == "clubs") {
        return "\u1F0AB";
      }
      else {
        return"\u1F0DB";
      }
    }
    private:
      Jack(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
