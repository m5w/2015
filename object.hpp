#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <ostream>

class object {
public:
  friend std::ostream &operator<<(std::ostream &a, const object &b);
  friend bool operator<(const object &a, const object &b);
  virtual ~object() = default;
protected:
  virtual std::ostream &print(std::ostream &a) const = 0;
  virtual bool lt(const object &b) const = 0;
};

#endif
