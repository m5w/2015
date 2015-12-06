#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

#include "object.hpp"

#include <memory>
#include <ostream>
#include <vector>

class object_list : public object {
public:
  template<typename object_type> void append(object_type x);
  void extend(object_list L);
  template<typename object_type> void insert(std::vector<std::shared_ptr<object> >::const_iterator::difference_type i, object_type x);
  std::shared_ptr<object> pop();
  std::shared_ptr<object> pop(std::vector<std::shared_ptr<object> >::const_iterator::difference_type i);
  void reverse();
private:
  std::ostream &print(std::ostream &a) const override;
  bool lt(const object &b) const override;
  std::vector<std::shared_ptr<object> > list_;
};

template<typename object_type> void object_list::append(object_type x) {
  list_.emplace_back(new object_type(x));
}

template<typename object_type> void object_list::insert(std::vector<std::shared_ptr<object> >::const_iterator::difference_type i, object_type x) {
  list_.emplace(list_.cbegin() + i, std::make_shared(new object_type(x)));
}

#endif
