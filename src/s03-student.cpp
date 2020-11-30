#include "s23739/student.h"
#include <iostream>

Student::Student(std::string fn, std::string sn, std::string in,
                 std::string sms, std::string avg) {
  first_name = fn;
  second_name = sn;
  index_number = in;
  semester = sms;
  avg_grades = avg;
}

auto Student::to_string() const -> std::string {
  auto out = std::ostringstream{};
  out << "Imie:" << first_name << "\nNazwisko:" << second_name
      << "\nSemestr:" << semester << "\nSrednia ocen:" << avg_grades;
  return out.str();
}
auto main() -> int {
  auto s23739 = Student("Mikolaj", "Holdakowski", "s23739", "1", "None");
  std::cout << s23739.to_string() << "\n";

  return 0;
}
