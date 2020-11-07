
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string haslo="brak";
    string wejscie="brak";
    cout << "Nadaj haslo:";
    cin >> haslo;
    do
{
cout<<"Podaj haslo:";
cin>>wejscie;
} while(haslo!=wejscie);
    
    return 0;
}
