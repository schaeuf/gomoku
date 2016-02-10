
// -*-c++-*-  Hey emacs, wake up, this is C++!

/* Christian Schaeufler
 * (C.) Copyright 1999, Christian Schaeufler
 * Glue together the EMatrix and the Stone - class
 */

#ifndef __BOARD_H
#define __BOARD_H

#include "ematrix.h"
#include "stone.h"

class Board : public EMatrix<Stone>
{
private:
  unsigned _moveCount;
  Player *_playerX;
  Player *_playerO;
  void set(short row, short col, Party party);
public:
  Board()
    : _playerX(_playerO(NULL)), _moveCount(0), EMatrix<Stone>(*new Stone) {};
  Party register(Player *player, Party party);
  Party get(short row, short col);
};



#endif __BOARD_H
