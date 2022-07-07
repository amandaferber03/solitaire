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
        return "\U0001F0BB";
      }
      else if (get_suit() == "diamonds") {
        return "\U0001F0CB";
      }
      else if (get_suit() == "clubs") {
        return "\U0001F0DB";
      }
      else {
        return"\U0001F0AB";
      }
    }
      Jack(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
