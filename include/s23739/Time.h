#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
enum class Time_of_day { rano = 6, dzien = 12, wieczor = 20, noc = 24 };

struct Time {

  unsigned short hour;
  unsigned short minute;
  unsigned short second;

  auto to_string() const -> std::string;
  auto next_hour() -> void;
  auto next_minute() -> void;
  auto next_second() -> void;
  auto time_of_day() const -> void;
  auto count_seconds() const -> uint64_t;
  auto count_minutes() const -> uint64_t;
  auto time_to_midnight() const -> Time;
  auto operator+(Time const &) const -> Time;
  auto operator-(Time const &) const -> Time;
  auto operator<(Time const &) const -> bool;
  auto operator>(Time const &) const -> bool;
  auto operator==(Time const &) const -> bool;
  auto operator!=(Time const &) const -> bool;
  Time(unsigned short, unsigned short, unsigned short);
};
