#include <iostream>
#include <sstream>
#include <string>
struct Student {

  std::string first_name;
  std::string second_name;
  std::string index_number;
  unsigned short int semester;
  double avg_grades;

  auto to_string() const -> std::string;

  Student(std::string, std::string, std::string, unsigned short int, double);
};
