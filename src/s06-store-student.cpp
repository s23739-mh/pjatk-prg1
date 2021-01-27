#include "s23739/student.h"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
Student::Student(std::string fn, std::string sn, std::string in,
                 unsigned short int sms, double avg)
    : first_name{fn}, second_name{sn}, index_number{in}, semester{sms},
      avg_grades{avg} {}

auto Student::to_string() const -> std::string {
  auto out = std::ostringstream{};
  out << "Imie:" << first_name << "\nNazwisko:" << second_name
      << "\nSemestr:" << semester << "\nSrednia ocen:" << avg_grades;
  return out.str();
}
auto main() -> int {
  auto s23739 = Student("Mikolaj", "Holdakowski", "s23739", 1, 4.15);
  auto file_path = std::string{"./student.txt"};
  auto file_des = open(file_path.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  auto n =
      write(file_des, s23739.to_string().data(), s23739.to_string().size());
  if (n == -1) {
    perror("write(2)");
  };

  close(file_des);
  return 0;
}
