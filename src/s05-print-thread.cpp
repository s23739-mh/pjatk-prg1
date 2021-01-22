#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
auto print_string(std::string text) -> void {
  std::cout << ("Hello," + text + "!\n");
}
int main() {

  for (auto i = 0; i < 42; i++) {
    auto thr = std::thread{print_string, std::to_string(i)};
    thr.detach();
  }
  usleep(500000); // Waiting for all of the threads to end. This is not a good
                  // solution. I don't know if it is expected from the program
                  // to print everything

  return 0;
}
