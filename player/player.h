// -*-c++-*-  Hey emacs, wake up, this is C++!

/* Christian Schaeufler
 * (C.) Copyright 1999, Christian Schaeufler
 */

#ifndef __PLAYER_H
#define __PLAYER_H

#include "ematrix.h"

class Player{
private:
  Ematrix &_board;
  Party _party;
  String _name;
public:
  Player(char *name, Board board, Party party = UNASSIGNED);
  
  Point suggest() = 0;
  Point doMove() = 0;

};

#endif __PLAYER_H
