#include <iostream>

auto main(int argc, char *argv[]) -> int {
  if (argc > 1) {

    for (int i = std::stoi(argv[1]); i > 0; i--) {
      std::cout << i << " bottles of beer on the wall, " << i
                << "bottles of beer.\nTake one down, pass it around, ";
      std::cout << i - 1 << " bottles of beer on the wall...\n";
    }
    std::cout << "No more bottles of beer on the wall, no more bottles of "
                 "beer.\nGo to "
                 "the shore and buy some more, "
              << argv[1] << " bottles of beer on the wall...";
  }
  return 0;
}
