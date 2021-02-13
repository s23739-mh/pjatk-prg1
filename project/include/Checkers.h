#ifndef CHECKERS_H
#define CHECKERS_H

#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

struct Checker {
  unsigned short int cell_no;
  bool color;
  bool is_here;
  bool is_Queen;
  Checker(unsigned short int, bool, bool, bool);
};

class Game {
  unsigned short int n_moves;
  unsigned short int points;
  std::string l_moves;

public:
  std::vector<Checker> Board;
  int isMove(int, int, bool);
  int GetInput(WINDOW *, bool);
  bool CanTake(int, int);
  bool IsThereTakes(int, bool);
  bool IsAnyTakes(bool);
  bool isEnd();
  bool isDraw(int);
  std::vector<Checker> setupBoard();
  Game(unsigned short int, unsigned short int, std::vector<Checker>);
};

#endif
