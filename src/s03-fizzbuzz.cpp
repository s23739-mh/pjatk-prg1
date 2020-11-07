#include <iostream>
auto main() ->int
{
std::string a;
std::cout<<"Enter a number:";
std::getline(std::cin,a);
for(int n=0;n<=std::stoi(a);n++)
{
if(n%(3*5)==0)
{std::cout<<"Fizzbuzz\n";}
else
{
if(n%3==0)
{std::cout<<"Fizz\n";}
if(n%5==0)
{std::cout<<"Buzz\n";}
}
}


return 0;
}
