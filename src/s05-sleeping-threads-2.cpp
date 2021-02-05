#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include <thread>
#include <unistd.h>
auto fill_queue(std::queue<std::string> &text, std::mutex &mtx,
                std::condition_variable &cv) -> void {
  std::string help = " ";
  auto i = 0;
  while (i < 4) {
    std::getline(std::cin, help);
    std::unique_lock<std::mutex> locker(mtx);
    if (help == " " || help[0] == 0 || help[0] == 10) {
      i++;
    }
    text.push(help);
    mtx.unlock();
    cv.notify_one();
  }
  return;
}

auto get_from_queue(std::mutex &mtx, std::queue<std::string> &q, int thread_ID,
                    std::condition_variable &cv) -> void {
  std::unique_lock<std::mutex> locker(mtx);
  cv.wait(locker);
  if (q.empty() == false) {
    if (q.front()[0] != 0 && q.front()[0] != 10) {
      std::cout << "from thread" << thread_ID << ": " << q.front() << "\n";
    } else {
      std::cout << "thread " << thread_ID << " exiting\n";
    }
    q.pop();
    cv.notify_one();
  }

  return;
}

auto main() -> int {
  std::queue<std::string> q;
  std::mutex mtx;
  std::condition_variable cv;
  fill_queue(std::ref(q), std::ref(mtx), std::ref(cv));
  while (true) {

    auto thread1 = std::thread{get_from_queue, std::ref(mtx), std::ref(q), 401,
                               std::ref(cv)};
    auto thread2 = std::thread{get_from_queue, std::ref(mtx), std::ref(q), 402,
                               std::ref(cv)};
    auto thread3 = std::thread{get_from_queue, std::ref(mtx), std::ref(q), 403,
                               std::ref(cv)};
    auto thread4 = std::thread{get_from_queue, std::ref(mtx), std::ref(q), 404,
                               std::ref(cv)};
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    if (q.empty() == true) {
      break;
    }
  }

  return 0;
}
