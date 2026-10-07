#include <iostream>
#include <cstdlib>
#include <stdexcept>

constexpr int invalid_data_exit_code = 1;
int main(){
  try{
    int prevEl = 0; int curEl = 0; int nextEl = 0; int suitElCount = 0;

    if(!(std::cin >> prevEl)){
      throw std::invalid_argument("Invalid input\n");
    }

    if (prevEl == 0){
      std::cout << "0\n";
      return 0;
    }

    if (!(std::cin >> curEl)){
      std::cout << 0;
      return 0;
    };

    if (curEl == 0){
      std::cout << 0;
      return 0;
    }


    while(true){
    if(!(std::cin >> nextEl)){
      throw std::invalid_argument("Invalid input\n");
    }

      if (nextEl == 0){
        break;
      }
      if (curEl < prevEl && curEl > nextEl){
        suitElCount++;
      }
      prevEl = curEl;
      curEl = nextEl;
    }
    std::cout << suitElCount;
  }
  catch(const std::invalid_argument& ex){
    std::cerr << "Invalid_argument: " << ex.what() << "\n";
    std::exit(invalid_data_exit_code);
  }
  return 0;
}
