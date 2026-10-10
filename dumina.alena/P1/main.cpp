#include <cstdlib>
#include <iostream>
#include <stdexcept>

constexpr int invalid_data_exit_code = 1;
int main()
{
  try {
    int prev_el = 0;
    int cur_el = 0;
    int next_el = 0;
    int suit_el_count = 0;

    if (!(std::cin >> prev_el)) {
      if (std::cin.eof()) {
        std::cout << "0\n";
        return 0;
      }
      throw std::invalid_argument("Invalid input\n");
    }

    if (prev_el == 0) {
      std::cout << "0\n";
      return 0;
    }

    if (!(std::cin >> cur_el)) {
      if (std::cin.eof()) {
        std::cout << "0\n";
        return 0;
      }
      throw std::invalid_argument("Invalid input\n");
    }

    if (cur_el == 0) {
      std::cout << "0\n";
      return 0;
    }

    while (true) {
      if (!(std::cin >> next_el)) {
        if (std::cin.eof()) {
          break;
        }
        throw std::invalid_argument("Invalid input\n");
      }

      if (next_el == 0) {
        break;
      }
      if (cur_el < prev_el && cur_el > next_el) {
        suit_el_count++;
      }
      prev_el = cur_el;
      cur_el = next_el;
    }
    std::cout << suit_el_count << '\n';
  } catch (const std::invalid_argument &ex) {
    std::cerr << "Invalid_argument: " << ex.what() << '\n';
    std::exit(invalid_data_exit_code);
  }
  return 0;
}
