#ifndef OBJECT_LIST_HPP
#define OBJECT_LIST_HPP

#include "object.hpp"

#include <memory>
#include <ostream>
#include <utility>
#include <vector>

class object_list : public object {
public:
  static std::pair<object_list, object_list> splice(const object_list &a);
  static object_list merge(const object_list &a,const object_list &b);
  static object_list mergeSort(const object_list &a);
  static object_list sort(const object_list &a);
  template <typename object_type> void append(object_type x);
  void extend(object_list L);
  template <typename object_type>
  void insert(
      std::vector<std::shared_ptr<object>>::const_iterator::difference_type i,
      object_type x);
  std::shared_ptr<object> pop();
  std::shared_ptr<object>
  pop(std::vector<std::shared_ptr<object>>::const_iterator::difference_type i);
  void reverse();
  std::vector<std::shared_ptr<object>>::size_type len() const;
  std::shared_ptr<object> deepcopy() const override;

private:
  std::vector<std::shared_ptr<object>> list_;
  std::ostream &print(std::ostream &a) const override;
  bool lt(const object &b) const override;
};

template <typename object_type> void object_list::append(object_type x) {
  list_.emplace_back(std::static_pointer_cast<object>(
      std::shared_ptr<object_type>(new object_type(x))));
}

template <typename object_type>
void object_list::insert(
    std::vector<std::shared_ptr<object>>::const_iterator::difference_type i,
    object_type x) {
  list_.emplace(list_.cbegin() + i,
                std::static_pointer_cast<object>(
                    std::shared_ptr<object_type>(new object_type(x))));
}

#endif
