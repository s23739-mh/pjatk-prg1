#include <iostream>

auto main() -> int
{
for(int i=99;i>0;i--)
{
std::cout<<i<<" bottles of beer on the wall, "<<i<<"bottles of beer.\nTake one down, pass it around, ";std::cout<<i-1<<" bottles of beer on the wall...\n";
}
std::cout<<"No more bottles of beer on the wall, no more bottles of beer.\nGo to the shore and buy some more,99 bottles of beer on the wall...";



return 0;
}
