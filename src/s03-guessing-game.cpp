#include <iostream>
#include <stdlib.h>
#include <time.h>
int main()
{

srand (time(NULL));
int number=rand()%100+1;
int guess;

std::cout<<"Pick a number:";
std::cin>>guess;


while(number!=guess)
{
if(guess>number)
{std::cout<<"Try a little lower:";std::cin>>guess;}
else
{std::cout<<"Try a little higher:";std::cin>>guess;}
}
std::cout<<"Wonderful! You guessed your number!\n";



return 0;
}
