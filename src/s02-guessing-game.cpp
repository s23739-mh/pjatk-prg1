#include <iostream>
#include <random>
#include <string>
auto main() -> int {
  std::string guess;
  std::random_device ran_dev;
  std::uniform_int_distribution<int> d100(1, 100);
  auto number = d100(ran_dev);
  std::cout << "Pick a number:";
  std::getline(std::cin, guess);

  while (number != std::stoi(guess)) {
    if (std::stoi(guess) > number) {
      std::cout << "Try a little lower:";
      std::getline(std::cin, guess);
    } else {
      std::cout << "Try a little higher:";
      std::getline(std::cin, guess);
    }
  }
  std::cout << "Wonderful! You guessed your number!\n";

  return 0;
}
