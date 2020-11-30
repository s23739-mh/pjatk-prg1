#include <iostream>
#include <sstream>
#include <string>
struct Student {

  std::string first_name;
  std::string second_name;
  std::string index_number;
  std::string semester;
  std::string avg_grades;

  auto to_string() const -> std::string;

  Student(std::string, std::string, std::string, std::string, std::string);
};
