#ifndef KING_H
#define KING_H

#include <string>
#include "Card.h"


namespace Solitaire
{
  class King : public Card {

  public:

    char to_ascii()   override { return 'K'; }

    char get_upper()   override { return '?'; }

    char get_lower()   override { return 'Q'; }

    std::string to_unicode()   override {
      if(get_suit() == "hearts") {
	return "\u1F0BE";
      }
      else if (get_suit() == "diamonds") {
	return "\u1F0CE";
      }
      else if (get_suit() == "clubs") {
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
