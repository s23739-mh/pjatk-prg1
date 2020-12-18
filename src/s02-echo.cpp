#include <algorithm>
#include <iostream>
#include <vector>
auto casen(std::vector<std::string> input)
    -> void // Wypisuje tablice w zwyczajny sposob (niezakonczony "\n")
{
  for (unsigned int i = 0; i < input.size(); i++) {
    if (input[i] != "-r" && input[i] != "-n" && input[i] != "-l") {
      std::cout << input[i] << " ";
    }
  }
}

auto casel(std::vector<std::string> input)
    -> void // Wypisuje tablice jako liste
{
  for (unsigned int i = 0; i < input.size(); i++) {
    if (input[i] != "-r" && input[i] != "-n" && input[i] != "-l") {
      std::cout << input[i] << "\n";
    }
  }
}

auto caser(std::vector<std::string> input, std::string option) -> void {
  std::reverse(std::begin(input), std::end(input));
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

auto main(int argc, char *argv[]) -> int {
  std::vector<std::string> input;
  if (argc > 1) {
    for (auto i = 1; i < argc; i++) {
      input.push_back(argv[i]);
    }
    if ((input[0] == "-r" && input[1] == "-n") ||
        (input[0] == "-n" && input[1] == "-r")) {
      caser(input, "-n");
      return 0;
    }

    if ((input[0] == "-r" && input[1] == "-l") ||
        (input[0] == "-l" && input[1] == "-r")) {
      caser(input, "-l");
      return 0;
    }

    if (input[0] == "-n") {
      casen(input);
      return 0;
    }

    if (input[0] == "-r") {
      caser(input, "-x");
      return 0;
    }

    if (input[0] == "-l") {
      casel(input);
      return 0;
    }

    {
      casen(input);
      std::cout << "\n";
      return 0;
    }
  } else {
    std::cerr << "Za malo danych!\n";
    return 0;
  }
}
