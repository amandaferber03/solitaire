#ifndef KING_H
#define KING_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class King : public Card {

  public:

    char to_ascii() const override { return 'K'; }

    char get_upper() const override { return '?'; }

    char get_lower() const override { return 'Q'; }

    std::string to_unicode() const override {
      if(suit == "hearts") {
	return "\u1F0BE";
      }
      else if (suit == "diamonds") {
	return "\u1F0CE";
      }
      else if (suit == "clubs") {
	return "\u1F0AE";
      }
      else {
	return"\u1F0DE";
      }
    }
    private:
      King(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
