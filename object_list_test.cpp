#include "object_list.hpp"

#include "object_int.hpp"

#include <iostream>

int main() {
  object_list L;
  L.append(object_int(2));
  // L.append(object_int(3));
  L.append(object_int(8)); //
  L.append(object_int(5));
  L.append(object_int(7));
  L.append(object_int(1));
  L.append(object_int(9));
  std::cout << "L = " << L << '\n';
  object_list M;
  M.append(object_int(6));
  M.append(object_int(8));
  M.append(object_int(4));
  M.append(object_int(0));
  M.append(object_int(9)); //
  std::cout << "M = " << M << '\n';

  L.extend(M);
  std::cout << "L = " << L << '\n';

  L.insert(1, object_int(3));
  std::cout << "L = " << L << '\n';

  L.pop();
  std::cout << "L = " << L << '\n';

  L.pop(2);
  std::cout << "L = " << L << '\n';

  auto N = object_list::sort(L);
  std::cout << "N = " << N << '\n';

  L.selection_sort();
  std::cout << "L = " << L << '\n';

  N.reverse();
  std::cout << "N = " << N << '\n';
}
