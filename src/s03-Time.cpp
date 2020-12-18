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
  out << std::setw(2) << std::setfill('0') << hour << ":";
  out << std::setw(2) << std::setfill('0') << minute << ":";
  out << std::setw(2) << std::setfill('0') << second;
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
auto Time::operator+(Time const &time_i) const -> Time {
  short unsigned int s = 0;
  short unsigned int m = 0;
  short unsigned int h = 0;
  if (second + time_i.second > 59) {
    s = second + time_i.second - 60;
  } else {
    s = second + time_i.second;
  }
  if (minute + time_i.minute > 59) {
    m = minute + time_i.minute - 60;
  } else {
    m = minute + time_i.minute;
  }
  if (hour + time_i.hour > 23) {
    h = hour + time_i.hour - 24;
  } else {
    h = hour + time_i.hour;
  }
  return Time{h, m, s};
}
auto Time::operator-(Time const &time_i) const -> Time {
  auto h = hour;
  auto m = minute;
  auto s = second;
  if (s - time_i.second < 0) {
    m--;
    s += 60 - time_i.second;
  } else {
    s -= time_i.second;
  }
  if (m - time_i.minute < 0) {
    h--;
    m += 60 - time_i.minute;
  } else {
    m -= time_i.minute;
  }
  if (h - time_i.hour < 0) {
    h += 24 - time_i.hour;
  } else {
    h -= time_i.hour;
  }
  return Time{h, m, s};
} // This definetly needs some work, Had no idea how to bite that

auto Time::operator!=(Time const &time_i) const -> bool {
  if (time_i.hour == hour && time_i.minute == minute &&
      time_i.second == second) {
    return false;
  } else {
    return true;
  }
}
auto Time::operator==(Time const &time_i) const -> bool {
  if (time_i.hour != hour && time_i.minute != minute &&
      time_i.second != second) {
    return false;
  } else {
    return true;
  }
}
auto Time::operator<(Time const &time_i) const -> bool {
  if (hour < time_i.hour && minute < time_i.minute && second < time_i.second) {
    return true;
  } else
    return false;
}
auto Time::operator>(Time const &time_i) const -> bool {
  if (hour < time_i.hour && minute < time_i.minute && second < time_i.second) {
    return false;
  } else
    return true;
}
auto main() -> int {
  std::string operation;
  auto time = Time(11, 59, 39);
  auto time2 = Time(3, 50, 10);
  std::cout << "Time now:" << time.to_string() << "\n";
  time.next_second();
  std::cout << "Time second later:" << time.to_string() << "\n";
  std::cout << "Right now we have ";
  time.time_of_day();
  auto t_midnight = time.time_to_midnight();
  std::cout << "Time to midnight:" << t_midnight.to_string()
            << "\nMinutes and seconds:" << time.count_minutes() << " and "
            << time.count_seconds() << "\n";
  std::cout
      << "Enter a sign for chosen operation:\n'+'For adding time\n'-'For "
         "removing time\n'<'For checking if lesser\n'>'For checking if "
         "greater\n'=='For checking if equal\n'!='For checking if not equal\n";
  std::cout << "Time1:" << time.to_string() << "\n";
  std::cout << "Time2:" << time2.to_string() << "\n";
  std::getline(std::cin, operation);
  ;
  if (operation == "+") {
    std::cout << time.operator+(time2).to_string() << "\n";
  } else if (operation == "-") {
    std::cout << time.operator-(time2).to_string() << "\n";
  } else if (operation == "<") {
    if (time.operator<(time2) == true) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  } else if (operation == ">") {
    if (time.operator>(time2) == true) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  } else if (operation == "==") {
    if (time.operator==(time2) == true) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  } else if (operation == "!=") {
    if (time.operator!=(time2) == true) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  } else

    return 0;
}
