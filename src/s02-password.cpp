#include <iostream>
#include <string>
auto main(int argc, char *argv[]) -> int {
  std::string password;
  if (argc > 1) {
    password = argv[1];
  } else {
    std::cerr << "No password!";
    return 0;
  }
  std::string input = "-";
  do {
    std::cout << "Enter your password:";
    std::getline(std::cin, input);
  } while (password != input);

  return 0;
}
