#include <iostream>
auto main(int argc, char *argv[]) -> int {
  if (argc > 1) {
    auto a = std::stoi(argv[1]);
    for (int n = 1; n <= a; n++) {
      std::cout << n << " ";
      if (n % 3 == 0) {
        std::cout << "Fizz";
      }
      if (n % 5 == 0) {
        std::cout << "Buzz";
      }
      std::cout << "\n";
    }
  }
  return 0;
}
