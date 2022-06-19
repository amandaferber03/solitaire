#include <cstddef>
#include "CreateCard.h"
#include "King.h"
#include "Queen.h"
#include "Jack.h"
#include "Ten.h"
#include "Nine.h"
#include "Eight.h"
#include "Seven.h"
#include "Six.h"
#include "Five.h"
#include "Four.h"
#include "Three.h"
#include "Two.h"
#include "Ace.h"

namespace Solitaire
{
  Card* create_card(const char& card_designator, const std::string& suit_designator) {
    switch(card_designator) {
    case 'K': {
      if(suit_designator == "hearts") {
	return new King("hearts");
      }
      else if (suit_designator == "diamonds") {
        return new King("diamonds");
      }
      else if (suit_designator == "clubs") {
        return new King("clubs");
      }
      else {
	return new King("spades");
      }
    }
    case 'Q': {
      if(suit_designator == "hearts") {
	return new Queen("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Queen("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Queen("clubs");
      }
      else {
	return new Queen("spades");
      }
    }
    case 'J': {
      if(suit_designator == "hearts") {
	return new Jack("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Jack("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Jack("clubs");
      }
      else {
	return new Jack("spades");
      }
    }
    case 'T': {
      if(suit_designator == "hearts") {
	return new Ten("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Ten("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Ten("clubs");
      }
      else {
	return new Ten("spades");
      }
    }
    case '9': {
      if(suit_designator == "hearts") {
	return new Nine("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Nine("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Nine("clubs");
      }
      else {
	return new Nine("spades");
      }
    }
    case '8': {
      if(suit_designator == "hearts") {
	return new Eight("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Eight("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Eight("clubs");
      }
      else {
	return new Eight("spades");
      }
    }
    case '7': {
      if(suit_designator == "hearts") {
	return new Seven("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Seven("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Seven("clubs");
      }
      else {
	return new Seven("spades");
      }
    }
   case '6': {
      if(suit_designator == "hearts") {
	return new Six("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Six("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Six("clubs");
      }
      else {
	return new Six("spades");
      }
    }
    case '5': {
      if(suit_designator == "hearts") {
	return new Five("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Five("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Five("clubs");
      }
      else {
	return new Five("spades");
      }
    }
    case '4': {
      if(suit_designator == "hearts") {
	return new Four("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Four("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Four("clubs");
      }
      else {
	return new Four("spades");
      }
    }
    case '3': {
      if(suit_designator == "hearts") {
	return new Three("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Three("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Three("clubs");
      }
      else {
	return new Three("spades");
      }
    }
    case '2': {
      if(suit_designator == "hearts") {
	return new Two("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Two("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Two("clubs");
      }
      else {
	return new Two("spades");
      }
    }
    case 'A': {
      if(suit_designator == "hearts") {
	return new Ace("hearts");
      }
      else if (suit_designator == "diamonds") {
	return new Ace("diamonds");
      }
      else if (suit_designator == "clubs") {
	return new Ace("clubs");
      }
      else {
	return new Ace("spades");
      }
    }
    default: return nullptr;
    }
  }
}

 
