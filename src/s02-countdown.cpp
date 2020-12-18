#include <iostream>

auto main(int argc, char *argv[]) -> int {
  if (argc > 1) {
    auto number = 0;
    number = std::stoi(argv[1]);
    for (int i = 0; i <= number; i++) {
      std::cout << number - i << "\n";
    }
  }
  return 0;
}
