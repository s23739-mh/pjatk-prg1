
#include <array>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>

auto main() -> int {
  auto file_path = std::string{"./student.txt"};
  auto file_des = open(file_path.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  std::array<char, 4096> buf{0};
  auto const n = read(file_des, buf.data(), buf.size());
  if (n == -1) {
    perror("read(2)");
  } else {
    std::cout << std::string{buf.data(), static_cast<size_t>(n)};
  }

  close(file_des);
  return 0;
}
