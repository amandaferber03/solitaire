#ifndef NINE_H
#define NINE_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class Nine : public Card {

  public:

    char to_ascii() const override { return "9"; }

    char get_lower() const override { return "T"; }

    char get_upper() const override { return "8"; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
        return "\u1F0B9";
      }
      else if (suit == "diamonds") {
        return "\u1F0C9";
      }
      else if (suit == "clubs") {
        return "\u1F0A9";
      }
      else {
        return"\u1F0D9";
      }
    }
  };
}
#endif
