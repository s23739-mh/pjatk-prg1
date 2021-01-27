#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <unistd.h>
auto fill_queue(std::queue<std::string> &text) -> void {
 std::string help=" "; auto i=0;
while(i<4)
{
std::getline(std::cin,help);
if(help[0]==0||help[0]==10)
{i++;}
    text.push(help);
  }
}

auto get_from_queue(std::mutex &mtx, std::queue<std::string> &q, int thread_ID)
    -> void {
  std::lock_guard<std::mutex> locker(mtx);
  if (q.empty() == false) {
    if (q.front()[0]!=0 && q.front()[0]!=10) {
      std::cout << "from thread" << thread_ID << ": " << q.front() << "\n";
    } else {
      std::cout << "thread " << thread_ID << " exiting\n";
    }
    q.pop();
  } else {
    mtx.unlock();
    std::random_device rn;
    std::uniform_int_distribution<int> d(10, 100);
    usleep(d(rn) * 1000);
  }
}

auto main() -> int {
  std::queue<std::string> vc;
  fill_queue(vc);
  std::mutex mtx;
  while (true) {
    auto thread1 =
        std::thread{get_from_queue, std::ref(mtx), std::ref(vc), 401};
    auto thread2 =
        std::thread{get_from_queue, std::ref(mtx), std::ref(vc), 402};
    auto thread3 =
        std::thread{get_from_queue, std::ref(mtx), std::ref(vc), 403};
    auto thread4 =
        std::thread{get_from_queue, std::ref(mtx), std::ref(vc), 404};
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    std::lock_guard<std::mutex> locker(mtx);
    if (vc.empty() == true) {
      break;
    }
  }

  return 0;
}
