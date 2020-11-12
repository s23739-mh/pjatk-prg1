#include <iostream>
#include <vector>

auto casen(std::vector<std::string> input)
    -> void // Wypisuje tablice w zwyczajny sposob (niezakonczony "\n")
{
  for (unsigned int i = 0; i < input.size(); i++) {
    std::cout << input[i] << " ";
  }
}

auto casel(std::vector<std::string> input)
    -> void // Wypisuje jako tablice jako liste
{
  for (unsigned int i = 0; i < input.size(); i++) {
    std::cout << input[i] << "\n";
  }
}

auto caser(std::vector<std::string> input, std::string option) -> void {
  std::string help = "";
  for (unsigned int i = 0; i <= (input.size() - 1) / 2;
       i++) // Zamienia kolejnosc liczb (dziala do polowy tablicy zeby nie
            // zamienic dwukrotnie)
  {
    help = input[input.size() - i - 1];
    input[input.size() - i - 1] = input[i];
    input[i] = help;
  }
  if (option == "-l") {
    casel(input);
  }
  if (option == "-n") {
    casen(input);
  }
  if (option == "-x") {
    casen(input);
    std::cout << "\n";
  } // Sprawdza czy opcja -r wystepuje sama i wywoluje odpowiednia funkcje
}

auto main() -> int {
  std::string line;
  std::cout << "If you would like to end, type and enter 'break'\n";
  std::vector<std::string> input;

  while (true) {
    std::cout << "Input:";
    std::getline(std::cin, line);
    if (line == "break") {
      break;
    } // Wpisanie elementow do tablicy o nieokreslonej dlugosci
    input.push_back(line);
  }

  if (input.size() > 1) {
    // Wywolanie funkcji zaleznie od wybranej opcji
    if (input[0] == "-n") {
      casen(input);
    } else

        if (input[0] == "-r") {
      caser(input, "-x");
    } else

        if (input[0] == "-l") {
      casel(input);
    } else

        if (input[0] == "-r -n") {
      caser(input, "-n");
    } else

        if (input[0] == "-r -l") {
      caser(input, "-l");
    } else

    {
      casen(input);
      std::cout << "\n";
    }
  } else
    std::cerr << "Za malo danych!\n";
  return 0;
}
