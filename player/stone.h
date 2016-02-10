// -*-c++-*-  Hey emacs, wake up, this is C++!

/* Christian Schaeufler
 * (C.) Copyright 1999, Christian Schaeufler
 */

#ifndef __STONE_H
#define __STONE_H

enum Party {X, O, UNASSIGNED, READY};

class Stone{
public:
  Party _party;
  unsigned short _id;
  Stone() : _party(ALLONE), _id(0) {};
};

#endif __STONE_H
