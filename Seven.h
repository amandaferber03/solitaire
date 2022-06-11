#ifndef SEVEN_H
#define SEVEN_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Seven : public Card {

  public:

    char to_ascii() const override { return "7"; }

    char get_lower() const override { return "8"; }

    char get_upper() const override { return "6"; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B7";
      }
      else if (suit == "diamonds") {
        return "\u1F0C7";
      }
      else if (suit == "clubs") {
        return "\u1F0A7";
      }
      else {
        return"\u1F0D7";
      }
    }
  };
}
#endif