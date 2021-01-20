#include <iostream>
#include <string>
#include <thread>

auto print_string(std::string text)->void
{
std::cout<<("Hello,"+text+"!\n");
}
int main()
{

for(auto i=0;i<7;i++)
{
auto thr0 = std::thread{print_string,std::to_string(i*6)};
auto thr1 = std::thread{print_string,std::to_string(i*6+1)};
auto thr2 = std::thread{print_string,std::to_string(i*6+2)};
auto thr3 = std::thread{print_string,std::to_string(i*6+3)};
auto thr4 = std::thread{print_string,std::to_string(i*6+4)};
auto thr5 = std::thread{print_string,std::to_string(i*6+5)};                //I hope I'm doing it right
thr0.join();
thr1.join();
thr2.join();
thr3.join();
thr4.join();
thr5.join();
}


return 0;
}
