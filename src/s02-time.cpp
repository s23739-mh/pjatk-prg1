#include <iostream>
#include <s23739/time.h>

s23739::Time::Time(unsigned int TIMEH, unsigned int TIMEM, unsigned int TIMES)
    : timeh{HOUR}, timem{MINUTES}, times{SECONDS} {
  if (TIMEH > 23) {
    throw std::out_of_range{"Hour value cannot exceed 23!"};
  }
  if (TIMEM > 59) {
    throw std::out_of_range{"Minute value cannot exceed 59!"};
  }
  if (TIMES > 59) {
    throw std::out_of_range{"Second value cannot exceed 59!"};
  }
}
auto s23739::Time::what_time_is_it() -> void {
  std::cout << timeh << ":" << timem << ":" << times;
}

auto s23739::Time::increase_time() const -> Time {
  if (timeh == 23 && timem == 59 && times == 59) {
    return Time{0, 0, 0};
  }
  if (timem == 59 && times == 59) {return Time(timeh+1,0,0
  };
}
if (times == 59) {
  return Time{timeh, timem + 1, 0};
}
}

auto main() -> int {
  auto time = s23739::Time{23, 59, 55};
  time.what_time_is_it();

  return 0;
}
