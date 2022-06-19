#ifndef CARD_H
#define CARD_H

#include <utility>
#include <string>

namespace Solitaire
{
  typedef std::pair<char, int> Position;

  class Card {
  public:

    virtual ~Card(){}

    bool is_covered()  { return covered; }

    void change_covered() { covered = !covered; }

    std::string get_suit() { return suit; }
    
    bool is_red() { return red;}

    virtual char to_ascii()   = 0;

    virtual std::string to_unicode()   = 0;

    virtual char get_lower()   = 0;

    virtual char get_upper()   = 0;


  protected:
    Card(std::string card_suit) : suit(card_suit) {
      covered = true;
      if(suit == "hearts" || suit == "diamonds") {
        red = true;
      }
      else {
        red = false;
      }
    }
  private:
    bool red;
    bool covered;
    std::string suit;

  };
}
#endif

  
