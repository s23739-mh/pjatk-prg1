
#include <iostream>
auto main() -> int
{
    std::string haslo="brak";
    std::string wejscie="brak";
    std::cout << "Nadaj haslo:";
    std::getline(std::cin,haslo);
    do
{
std::cout<<"Podaj haslo:";
std::getline(std::cin,wejscie);
} while(haslo!=wejscie);
    
    return 0;
}
