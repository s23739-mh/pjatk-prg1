#include <iostream>
auto main() -> int {
  std::string number;
  std::cout << "Enter a number:";
  std::getline(std::cin, number);
  for (int i = 0; i <= std::stoi(number); i++) {
    std::cout << std::stoi(number) - i << "\n";
  }
  return 0;
}
