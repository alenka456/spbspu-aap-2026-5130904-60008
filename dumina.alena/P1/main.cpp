#include <iostream>
#include <stdexcept>

constexpr int INVALID_DATA_EXIT_CODE = 1;
const char INVALID_INPUT_MESSAGE[] = "INVALID INPUT";

int calc_suit_elem_count();

int main()
{
  try {
    std::cout << calc_suit_elem_count() << '\n';
  } catch (const std::invalid_argument &ex) {
    std::cerr << ex.what() << '\n';
    return INVALID_DATA_EXIT_CODE;
  }
  return 0;
}

int calc_suit_elem_count()
{
  int prev_el = 0;
  int cur_el = 0;
  int next_el = 0;
  int suit_el_count = 0;

  if (!(std::cin >> prev_el)) {
    throw std::invalid_argument(INVALID_INPUT_MESSAGE);
  }

  if (prev_el == 0) {
    return 0;
  }

  if (!(std::cin >> cur_el)) {
    throw std::invalid_argument(INVALID_INPUT_MESSAGE);
  }

  if (cur_el == 0) {
    return 0;
  }

  while (true) {
    if (!(std::cin >> next_el)) {
      throw std::invalid_argument(INVALID_INPUT_MESSAGE);
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
  return suit_el_count;
}
