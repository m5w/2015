#include "object.hpp"

#include <ostream>

std::ostream &operator<<(std::ostream &a, const object &b) {
  return b.print(a);
}

bool operator<(const object &a, const object &b) {
  return a.lt(b);
}
