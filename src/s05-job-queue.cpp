#include <iostream>
#include <thread>
#include <queue>
#include <mutex>

std::mutex mtx;

auto fill_queue( std::queue <unsigned int> &q) -> void
{for(int i=0;i<10;i++)
{q.push(i*17+2);}   }

auto get_from_queue( std::queue <unsigned int> &q, int thread_ID ) -> void
{
std::lock_guard<std::mutex> locker (mtx);

if(q.empty()==false){ 

std::cout<<"from thread"<<thread_ID<<": "<<q.front()<<"\n";
q.pop();}
}

auto main() ->int
{

static std::queue <unsigned int> Q;
fill_queue(Q);
while(Q.empty()==false)
{
auto thread1 = std::thread{get_from_queue,&Q, 401};
auto thread2 = std::thread{get_from_queue,&Q, 402};
auto thread3 = std::thread{get_from_queue,&Q, 403};
auto thread4 = std::thread{get_from_queue,&Q, 404};
thread1.detach();
thread2.detach();
thread3.detach();
thread4.detach();
}
return 0;
}
