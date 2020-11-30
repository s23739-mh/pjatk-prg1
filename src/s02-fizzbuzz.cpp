#include <iostream>
auto main() -> int {
  std::string a;
  std::cout << "Enter a number:";
  std::getline(std::cin, a);
  for (int n = 1; n <= std::stoi(a); n++) {
    std::cout << n << " ";
    if (n % (3 * 5) == 0) {
      std::cout << "Fizzbuzz";
    } else {
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
