#ifndef OBJECT_INT_HPP
#define OBJECT_INT_HPP

#include "object.hpp"

#include <ostream>

class object_int : public object {
public:
  object_int(const long long int_);
  const long long int_;
private:
  std::ostream &print(std::ostream &a) const override;
  bool lt(const object &b) const override;
};

#endif
