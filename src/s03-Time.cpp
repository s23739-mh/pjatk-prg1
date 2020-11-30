#include "s23739/Time.h"

Time::Time(unsigned short h, unsigned short m, unsigned short s) {
  if (h > 23) {
    throw std::out_of_range("Hour cannot exceed 23");
  }
  hour = h;
  if (m > 59) {
    throw std::out_of_range("Minute cannot exceed 59");
  }
  minute = m;
  if (s > 59) {
    throw std::out_of_range("Second cannot exceed 59");
  }
  second = s;
}

auto Time::to_string() const -> std::string {
  auto out = std::ostringstream{};
  if (hour < 10) {
    out << "0" << hour << ":";
  } else if (hour > 9) {
    out << hour << ":";
  }
  if (minute < 10) {
    out << "0" << minute << ":";
  } else if (minute > 9) {
    out << minute << ":";
  }
  if (second < 10) {
    out << "0" << second;
  } else if (second > 9) {
    out << second;
  }
  return out.str();
}

auto Time::next_hour() -> void {
  if (hour < 23) {
    hour++;
  } else {
    hour = 0;
  }
}

auto Time::next_minute() -> void {
  if (minute < 59) {
    minute++;
  } else {
    minute = 0;
    Time::next_hour();
  }
}

auto Time::next_second() -> void {
  if (second < 59) {
    second++;
  } else {
    second = 0;
    Time::next_minute();
  }
}

auto Time::time_of_day() const -> void {
  if (hour < (static_cast<int>(Time_of_day::rano)))
    std::cout << "Night..\n";
  else if (hour < (static_cast<int>(Time_of_day::rano)))
    std::cout << "Morning!\n";
  else if (hour < (static_cast<int>(Time_of_day::rano)))
    std::cout << "Daay\n";
  else
    std::cout << "Evening\n";
}

auto Time::count_seconds() const -> uint64_t {
  return (hour * 3600 + minute * 60 + second);
}

auto Time::count_minutes() const -> uint64_t { return (hour * 60 + minute); }
auto Time::time_to_midnight() const -> Time {
  unsigned short a, b, c;
  if (second == 0) {
    c = 0;
  }
  if (second != 0) {
    c = 60 - second;
  }
  if (c == 0) {
    b = 60 - minute;
  }
  if (c != 0) {
    b = 59 - minute;
  }
  if (minute == 0) {
    a = 24 - hour;
  }
  if (minute != 0) {
    a = 23 - hour;
  }
  if (b == 60) {
    b = 0;
    c++;
  }
  return Time{a, b, c};
}
auto main() -> int {
  auto time = Time(11, 59, 39);
  std::cout << "Time now:" << time.to_string() << "\n";
  time.next_second();
  std::cout << "Time second later:" << time.to_string() << "\n";
  std::cout << "Right now we have ";
  time.time_of_day();
  auto time2 = time.time_to_midnight();
  std::cout << "Time to midnight:" << time2.to_string()
            << "\nMinutes and seconds:" << time.count_minutes() << " and "
            << time.count_seconds() << "\n";
  return 0;
}
