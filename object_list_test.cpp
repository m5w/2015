#include "object_list.hpp"

#include "object_int.hpp"

#include <iostream>

int main() {
  object_list L;
  L.append(object_int(2));
  L.append(object_int(3));
  object_list M;
  M.append(object_int(5));
  M.append(L);
  std::cout << M << '\n';
}
