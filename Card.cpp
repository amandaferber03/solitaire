#ifndef CARD_H
#define CARD_H

#include <utility>
#include <string>
#include <tuple>

namespace Solitaire
{
  typedef std::tuple<char, char, char> Position;

  class Card {
  public:

    virtual ~Card(){}

    bool is_red() const { return red; }

    bool is_covered() const {return covered; }
}
