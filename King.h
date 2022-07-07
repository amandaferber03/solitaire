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
      if(get_suit() == "hearts") {
	return "\U0001F0BE";
      }
      else if (get_suit() == "diamonds") {
	return "\U0001F0CE";
      }
      else if (get_suit() == "clubs") {
	return "\U0001F0DE";
      }
      else {
	return "\U0001F0AE";
      }
    }
      King(std::string card_suit) :  Card(card_suit) {}
  };
}
#endif
