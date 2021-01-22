#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

auto fill_queue(std::queue<unsigned int> &q) -> void {
  for (int i = 0; i < 10; i++) {
    q.push(i * 17 + 2);
  }
}

auto get_from_queue(std::mutex &mtx, std::queue<unsigned int> &q, int thread_ID)
    -> void {
  std::lock_guard<std::mutex> locker(mtx);
  if (q.empty() == false) {

    std::cout << "from thread" << thread_ID << ": " << q.front() << "\n";
    q.pop();
  }
}

auto main() -> int {
  std::queue<unsigned int> Q;
  fill_queue(Q);
  std::mutex mtx;
  while (true) {
    auto thread1 = std::thread{get_from_queue, std::ref(mtx), std::ref(Q), 401};
    auto thread2 = std::thread{get_from_queue, std::ref(mtx), std::ref(Q), 402};
    auto thread3 = std::thread{get_from_queue, std::ref(mtx), std::ref(Q), 403};
    auto thread4 = std::thread{get_from_queue, std::ref(mtx), std::ref(Q), 404};
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    std::lock_guard<std::mutex> locker(mtx);
    if (Q.empty() == true) {
      break;
    }
  }
  return 0;
}
