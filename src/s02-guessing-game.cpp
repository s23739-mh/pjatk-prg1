#include <iostream>
#include <stdlib.h>
#include <time.h>
auto main() -> int {

  srand(time(NULL));
  int number = rand() % 100 + 1;
  std::string guess;

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
