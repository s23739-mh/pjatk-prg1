#include "Checkers.h"
// Constructors
Game::Game(unsigned short int move, unsigned short int point,
           std::vector<Checker> Boards)
    : n_moves{move}, points{point}, Board{Boards} {}

Checker::Checker(unsigned short int number, bool col, bool here, bool Queen)
    : cell_no{number}, color{col}, is_here{here}, is_Queen{Queen} {}

bool Game::isDraw(int moves) // moves - number of moves w/o any takes
{
  auto White_no = 0;
  auto Black_no = 0;
  if (moves > 30) {
    return true;
  }                // Draw by 30 moves without any takes - similar to chess
  if (moves > 6) { // Draw by insufficient material
    for (auto i = 0; i < 32; i++) {
      if (Board[i].is_here == true) {
        if (Board[i].color == false) {
          White_no++;
        }
        if (Board[i].color == true) {
          Black_no++;
        }
      }
    }
    if ((White_no == Black_no) && (White_no == 1)) {
      return true;
    }
  }
  return false;
}

bool Game::isEnd() {
  auto help = 0;
  bool areWhite = false;
  bool areBlack = false;
  for (auto i = 0; i < 32; i++) {
    if (Board[i].is_here == true) {
      help++;
      if (Board[i].color == false) {
        areWhite = true;
      }
      if (Board[i].color == true) {
        areBlack = true;
      }
    }
  }
  if (help == 1) {
    return true;
  } // If there is one checker left
  if ((areWhite == true && areBlack == true) == false) {
    return true;
  }
  return false;
}

bool Game::IsThereTakes(int n,
                        bool turn) // Function looking for takes from one cell
{
  auto a = false;
  if (turn == false) {
    a = CanTake(n, n + 3);
    if (a != false && Board[n + 3].color == true) {
      return true;
    }
    a = CanTake(n, n + 4);
    if (a != false && Board[n + 4].color == true) {
      return true;
    }
    a = CanTake(n, n + 5);
    if (a != false && Board[n + 5].color == true) {
      return true;
    }
    a = CanTake(n, n - 3);
    if (a != false && Board[n - 3].color == true) {
      return true;
    }
    a = CanTake(n, n - 4);
    if (a != false && Board[n - 4].color == true) {
      return true;
    }
    a = CanTake(n, n - 5);
    if (a != false && Board[n - 5].color == true) {
      return true;
    }
  }
  if (turn == true) {
    a = CanTake(n, n + 3);
    if (a != false && Board[n + 3].color == false) {
      return true;
    }
    a = CanTake(n, n + 4);
    if (a != false && Board[n + 4].color == false) {
      return true;
    }
    a = CanTake(n, n + 5);
    if (a != false && Board[n + 5].color == false) {
      return true;
    }
    a = CanTake(n, n - 3);
    if (a != false && Board[n - 3].color == false) {
      return true;
    }
    a = CanTake(n, n - 4);
    if (a != false && Board[n - 4].color == false) {
      return true;
    }
    a = CanTake(n, n - 5);
    if (a != false && Board[n - 5].color == false) {
      return true;
    }
  }
  return false;
}

bool Game::IsAnyTakes(bool turn) // Function looking for takes from whole board
{
  for (auto i = 0; i < 32; i++) {
    if (IsThereTakes(i, turn) == true) {
      
      return true;
    }
  }

  return false;
}

bool Game::CanTake(int Taking,
                   int Token) { // Function checking if its possible to take
  int difference = Taking - Token;
  int landingCell = Token - difference;
  if (Board[Taking].is_here == true && Board[Token].is_here == true &&
      Board[Taking].color != Board[Token].color) {


      if (Token < 4 || Token > 28) {
        return false;
      }                   // You cant take when you are next to the Border
      if (Taking % 8 < 4) // if %8/4<4 its 1st,3rd,5th or 7th row
      {
        if (((Token + 1) % 4) > 0 && difference == 5 &&
            Board[landingCell + 1].is_here ==
                false) // White perspective going front left  token%4>0 to
                       // prevent       /ls taking next to the left border
        {
          return true;
        }
        if ((Token + 1) % 4 > 0 && difference == 4 &&
            Board[landingCell + 1].is_here ==
                false) // White perspective going front right  token%4<3 to /ls
                       // prevent taking next to the right border
        {
          return true;
        }
        if ((Token + 1) % 4 > 0 && difference == -4 &&
            Board[landingCell + 1].is_here ==
                false) // White perspective going back right  token%4<3 to
                       // prevent   /ls taking next to the right border
        {
          return true;
        }
        if ((Token + 1) % 4 > 0 && difference == -3 &&
            Board[landingCell + 1].is_here ==
                false) // White perspective going back left  token%4>0 to
                       // prevent taking next to the left border
        {
          return true;
        }
      }

      else { // Then its 2nd,4th,6th or 8th row
        if ((Token) % 4 > 0 && difference == 3 &&
            Board[landingCell - 1].is_here ==
                false) // White perspective going front right  token%4<3 to
                       // prevent taking next to the left border
        {
          return true;
        }
        if ((Token) % 4 > 0 && difference == 4 &&
            Board[landingCell - 1].is_here ==
                false) // White perspective going front left   token%4>0 to
                       // prevent taking next to the right border
        {
          return true;
        }
        if ((Token) % 4 > 0 && difference == -4 &&
            Board[landingCell - 1].is_here ==
                false) // White perspective going back left  token%4>0 to
                       // prevent taking next to the left border
        {
          return true;
        }
        if ((Token) % 4 > 0 && difference == -5 &&
            Board[landingCell - 1].is_here ==
                false) // White perspective going back right  token%4<3 to
                       // prevent taking next to the right border
        {
          return true;
        }
      
    }
  }
  return false;
}

int Game::isMove(int cell1, int cell2,
                 bool move) // color=true - Black
{
  if (IsAnyTakes(move) == true) {
    if (CanTake(cell1, cell2) == true && Board[cell1].color == move) {
      return 10;
    } else
      return false;
  }
  if (move == false &&
      (Board[cell1].is_here != true || Board[cell2].is_here != false ||
       Board[cell1].color != false)) {
    return false;
  } // In case of wrong input
  if (move == true &&
      (Board[cell1].is_here != true || Board[cell2].is_here != false ||
       Board[cell1].color != true)) {
    return false;
  } // In case of wrong input
  if (Board[cell1].is_here == true && Board[cell2].is_here == false) {
    if (Board[cell1].is_Queen == true) {
      if ((cell1 / 4) % 2 == 0) {
        if (cell2 == cell1 - 4 || cell2 == cell1 - 5 || cell2 == cell1 + 4 ||
            cell2 == cell1 + 3) {
          return true;
        }
      }
      if ((cell1 / 4) % 2 == 1) {
        if (cell2 == cell1 - 4 || cell2 == cell1 - 3 || cell2 == cell1 + 4 ||
            cell2 == cell1 + 5) {
          return true;
        }
      }
    }
    if (move == false) {
      if (Board[cell1].color == false) {
        if (Board[cell1].is_Queen == false) {
          if ((cell1 / 4) % 2 == 0) {
            if (cell2 == cell1 - 4 || cell2 == cell1 - 5) {
              return true;
            }
          }
          if ((cell1 / 4) % 2 == 1) {
            if (cell2 == cell1 - 4 || cell2 == cell1 - 3) {
              return true;
            }
          }
        }
      }
    }
    if (move == true) {
      if (Board[cell1].color == true) {
        if (Board[cell1].is_Queen == false) {
          if ((cell1 / 4) % 2 == 1) {
            if (cell2 == cell1 + 4 || cell2 == cell1 + 5) {
              return true;
            }
          }
          if ((cell1 / 4) % 2 == 0) {
            if (cell2 == cell1 + 4 || cell2 == cell1 + 3) {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

void DrawCell(int init_y, int init_x, std::string Value,
              bool real) // Function for creating cells
{
  WINDOW *cell = newwin(3, 5, init_y, init_x);
  box(cell, 0, 0);

  if (real == true) {
    if (Value == "Black") {
      mvwprintw(cell, 1, 2,
                "B"); // Prints Checkers color depending on if its here or not
    }
    if (Value == "BlackQueen") {
      mvwprintw(cell, 1, 2,
                "BQ"); // Prints Checkers color depending on if its here or not
    }
    if (Value == "White") {
      mvwprintw(cell, 1, 2, "W");
    }
    if (Value == "WhiteQueen") {
      mvwprintw(cell, 1, 2,
                "WQ"); // Prints Checkers color depending on if its here or not
    }
  }
  refresh();
  wrefresh(cell);
}

int convert_coordinates(
    std::string cords) // Function converting given coordinates into cell number
{
  int i = 0, j = 0; // i-column (x-axis) j-row (y-axis)
  if (cords[0] == 'a' || cords[0] == 'b') {
    i = 1;
  }
  if (cords[0] == 'c' || cords[0] == 'd') {
    i = 2;
  }
  if (cords[0] == 'e' || cords[0] == 'f') {
    i = 3;
  }
  if (cords[0] == 'g' || cords[0] == 'h') {
    i = 4;
  }
  j = int(cords[1] - 48);
  if (j > 8 || i == 0) {
    return 404;
  }                          // Checks if cords is outside of a board
  if (cords[0] % 2 == j % 2) // Checks if its given a cord of unused cell
  {
    return 404;
  }
  return (4 * (8 - j) + i - 1);
}

int Game::GetInput(WINDOW *BoardWin, bool WantEmpty) {

  auto input = new char[10];
  do {
    move(21, 91);
    do {
      if (input != NULL && input[0] != '\0') {
        mvwprintw(BoardWin, 1, 1, "Input:");
        move(21, 91);
        wrefresh(BoardWin);
      } // In case of wrong input, asks for input again
      getnstr(input, 2);
    } while (convert_coordinates(input) == 404);

  } while (WantEmpty == true &&
           Board[convert_coordinates(input)].is_here == false);

  return convert_coordinates(input);
}

void BoardDraw(std::vector<Checker> CurrentBoard) {
  initscr(); // Creates Two windows. One for the whole game and one just for the
             // board

  WINDOW *BoardWin = newwin(27, 70, 5, 30); // Game
  WINDOW *Board = newwin(25, 49, 6, 31);    // Board

  // Prints those windows
  box(BoardWin, 0, 0);
  box(Board, 0, 0);

  attron(A_BOLD);
  mvwprintw(BoardWin, 0, 36, "CHECKERS"); // Gives a header for game window and
                                          // names sides of the board

  mvwprintw(BoardWin, 3, 55, "Black");
  mvwprintw(BoardWin, 23, 55, "White");

  attroff(A_BOLD);

  mvwprintw(BoardWin, 11, 53, "Select checker");
  mvwprintw(BoardWin, 12, 55, "and move it");
  mvwprintw(BoardWin, 26, 1, "a");
  mvwprintw(BoardWin, 26, 7, "b");
  mvwprintw(BoardWin, 26, 14, "c");
  mvwprintw(BoardWin, 26, 21, "d");
  mvwprintw(BoardWin, 26, 28, "e");
  mvwprintw(BoardWin, 26, 35, "f");
  mvwprintw(BoardWin, 26, 42, "g");
  mvwprintw(BoardWin, 26, 49, "h");
  mvwprintw(BoardWin, 2, 50, "8");
  mvwprintw(BoardWin, 5, 50, "7");
  mvwprintw(BoardWin, 8, 50, "6");
  mvwprintw(BoardWin, 11, 50, "5");
  mvwprintw(BoardWin, 14, 50, "4");
  mvwprintw(BoardWin, 17, 50, "3");
  mvwprintw(BoardWin, 20, 50, "2");
  mvwprintw(BoardWin, 23, 50, "1");

  refresh();
  wrefresh(BoardWin);
  wrefresh(Board); // Makes windows visible

  for (auto i = 0; i < 8; i++) // Loop creating 64 cells  //Think later about
                               // creating 16 bigger cells in a way it makes 64
  {
    for (auto j = 0; j < 8; j++) {
      auto help = std::string{"None"};
      if ((j + i) % 2 == 0) {
        if (CurrentBoard[4 * i + j / 2].color == true) {
          help = "Black";
          if (CurrentBoard[4 * i + j / 2].is_Queen == true) {
            help = "BlackQueen";
          }
        };
        if (CurrentBoard[4 * i + j / 2].color == false) {
          help = "White";
          if (CurrentBoard[4 * i + j / 2].is_Queen == true) {
            help = "WhiteQueen";
          }
        };
      }
      DrawCell(6 + i * 3, 31 + j * 6, help,
               CurrentBoard[4 * i + j / 2].is_here);
    }
  }
}

std::vector<Checker> setupBoard() // Function creating 24 Checkers from 32
                                  // playable cells (8 Checkers are imaginary)
{
  std::vector<Checker> StartBoard;
  for (auto i = 0; i < 12; i++) {
    StartBoard.push_back(
        Checker(i, true, true, false)); // Black checkers -computer
  }
  for (auto i = 12; i < 20; i++) {
    StartBoard.push_back(Checker(
        i, true, false, false)); // Non-existing (yet) checkers -empty cells
  }
  for (auto i = 18; i < 32; i++) {
    StartBoard.push_back(
        Checker(i, false, true, false)); // White checkers -playe
  }
  return StartBoard;
}

auto main() -> int {
  // plan
  // 1Draw
  // 2Wybierz pionka
  // 3Wybierz ruch
  // 4Sprawdz czy jest kolejny ruch
  // 5Sprawdz czy koniec gry
  // 6Jakis stuff
  // Setup stuff
  initscr();
  auto a = 0, b = 0, move = 0,
       NoTakeMove = 0;  // a - 1st input, b - second input,  move - move number,
                        // NoTakeMove - Number of moves without taking in a row
  bool didMove = false; // Used Later -If checker made a move
  bool didTake = false; // Used Later -If checker took another
  bool Draw = false;
  auto Winner = -1;
  auto play = Game(0, 0, setupBoard());
  WINDOW *Win = newwin(3, 12, 20, 83);

  box(Win, 0, 0);
  refresh();
  BoardDraw(play.Board);

  while (true) {
    if (play.isDraw(move) == true) {
      Draw = true;
      break;
    }
    if (play.isEnd() == true) {
      Winner = 1;
      break;
    }
    move++;
    do {   // White
      do { // Input

        a = play.GetInput(Win, true);

        b = play.GetInput(Win, false);

      } while (play.isMove(a, b, false) ==
               false); // Asks for input until move is legal

      if (play.isMove(a, b, false) == 10) {                         //Loop not ending until its nothing to take
        if (a % 8 > 3) {
          play.Board[a].is_here = false; // Plays a move with taking  (odd row)
          play.Board[b].is_here = false;
          play.Board[b - (a - b) - 1].color = false;
          play.Board[b - (a - b) - 1].is_here = true;
          play.Board[b - (a - b) - 1].is_Queen = play.Board[a].is_Queen;
          play.Board[a].is_Queen = false;
          didTake = true;
          if (b - (a - b) - 1 < 4) {
            play.Board[b - (a - b) - 1].is_Queen =
                true; // Convert into a Queen when on the last row
          }
          NoTakeMove = 0;
        } else {
          didTake = true;
          play.Board[a].is_here = false; // Plays a move with taking (even row)
          play.Board[b].is_here = false;
          play.Board[b - (a - b) + 1].color = false;
          play.Board[b - (a - b) + 1].is_here = true;
          play.Board[b - (a - b) + 1].is_Queen = play.Board[a].is_Queen;
          play.Board[a].is_Queen = false;
            if (b - (a - b) + 1 < 4) {
            play.Board[b - (a - b) + 1].is_Queen =
                true; // Convert into a Queen when on the last row
        }
          NoTakeMove = 0;
        }
      }
      if (didTake != true) {
        play.Board[a].cell_no = a;
        play.Board[a].is_here =
            false; // If player did not take, he can play a normal move
        play.Board[b].cell_no = b;
        play.Board[b].is_here = true;
        play.Board[b].color = false;
        didMove = true;
        NoTakeMove++;
        play.Board[b].is_Queen = play.Board[a].is_Queen;
        play.Board[a].is_Queen;
        if (b < 4) {
          play.Board[b].is_Queen = true; // Convert into a Queen when on last
                                         // row
        }
      }

      BoardDraw(play.Board);
      refresh();
    } while ((didTake == true &&
              play.IsAnyTakes(false) ==
                  true) && // Repeats previous steps if player took a checker
             didMove == false);

    didTake = false;
    didMove = false;
    if (play.isDraw(move) == true) {
      Draw = true;
      break;
    }
    if (play.isEnd() == true) {
      Winner = 0;
      break;
    }
    do { // Black

      do {

        a = play.GetInput(Win, true);

        b = play.GetInput(Win, false);

      } while (play.isMove(a, b, true) ==
               false); // Asks for input until move is legal

      if (play.isMove(a, b, true) == 10) // Loop not ending until its nothing to take
      {
        if (a % 8 > 3) {
          play.Board[a].is_here = false; // Plays a move with taking (odd row)
          play.Board[b].is_here = false;
          play.Board[b - (a - b) - 1].color = true;
          play.Board[b - (a - b) - 1].is_here = true;
          play.Board[b - (a - b) - 1].is_Queen = play.Board[a].is_Queen;
          play.Board[a].is_Queen = false;
          if (b - (a - b) - 1 < 4) {
            play.Board[b - (a - b) - 1].is_Queen =
            true; // Convert into a Queen when on the last row
        }
          didTake = true;
        } else {

          play.Board[a].is_Queen = false;
          didTake = true;

          play.Board[a].is_here = false; // Plays a move with taking (even row)
          play.Board[b].is_here = false;
          play.Board[b - (a - b) + 1].color = true;
          play.Board[b - (a - b) + 1].is_here = true;
          play.Board[b - (a - b) + 1].is_Queen = play.Board[a].is_Queen;
          play.Board[a].is_Queen = false;
          didTake = true;
          if (b - (a - b) + 1 > 27) {
            play.Board[b - (a - b) + 1].is_Queen =
                true; // Convert into a queen when on last row
          }
        }
      }
      if (didTake != true) {
        play.Board[a].cell_no = a;
        play.Board[a].is_here =
            false; // If a player did not take, he can play a normal move
        play.Board[b].cell_no = b;
        play.Board[b].is_here = true;
        play.Board[b].color = true;
        didMove = true;
        play.Board[b].is_Queen = play.Board[a].is_Queen;
        play.Board[a].is_Queen;
        if (b >= 28) {
          play.Board[b].is_Queen = true; // Convert into a queen when on last
                                         // row
        }
      }
      BoardDraw(play.Board);
      refresh();
    } while ((didTake == true && play.IsAnyTakes(true) == true) &&
             didMove == false);

    didTake = false;
    didMove = false;
  }
  endwin();
  if (Draw == false) {
    std::cout << "\nThe winner is ";
    if (Winner == 0) {
      std::cout << "White\n";
    }
    if (Winner == 1) {
      std::cout << "Black\n";
    }
  }
  if (Draw == true) {
    std::cout << "\nDraw.\n";
  }
  return 0;
}
