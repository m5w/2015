#include "object_int.hpp"

#include <iostream>
#include <limits>

int main() {
  std::cout << std::numeric_limits<decltype(object_int::int_)>::max() << '\n';
}
