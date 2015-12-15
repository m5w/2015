#include "object_int.hpp"

#include "object.hpp"

#include <memory>
#include <ostream>

object_int::object_int(const long long int_) : int_(int_) {}

std::shared_ptr<object> object_int::deepcopy() const {
  return std::static_pointer_cast<object>(
      std::shared_ptr<object_int>(new object_int(*this)));
}

std::ostream &object_int::print(std::ostream &a) const {
  a << int_;
  return a;
}

bool object_int::eq(const object &b) const {
  return int_ == dynamic_cast<const object_int &>(b).int_;
}

bool object_int::lt(const object &b) const {
  return int_ < dynamic_cast<const object_int &>(b).int_;
}
