#include "board.h"
[6~
void
Board::set(short row, short col, Party party)
{
  Stone &stone = EMatrix<Stone>::get(row, col);
  stone._id = _moveCount;
  stone._party = party;
  _moveCount++;

}

Party
Board::get(short row, short col)
{
  Stone &stone = EMatrix<Stone>::get(row, col);
  return stone._party;
}

Party
Board::regigster(Player *player, Party party)
{
  switch(party){
  case X, UNASSIGNED:
    if(_playerX==NULL){
      _playerX=player;
      return X;
    } else
      if(_playerO==NULL){
	_playerO=player;
	return O;
      } else
	return UNASSIGNED;
    break;
  case O:
    if(_playerO==NULL){
      _playerO=player;
      return O;
    } else
      if(_playerX==NULL){
	_playerX=player;
	return X;
      } else
	return UNASSIGNED;

  }
}
