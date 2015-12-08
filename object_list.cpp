#include "object_list.hpp"

#include "object.hpp"

#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

std::shared_ptr<object> object_list::deepcopy() const {
  std::shared_ptr<object_list> b(new object_list);

  for (const auto &item : list_) {
    b->list_.push_back(std::move(item->deepcopy()));
  }

  return std::static_pointer_cast<object>(std::move(b));
}

void object_list::extend(object_list L) {
  list_.reserve(list_.size() + L.list_.size());

  for (auto &item : L.list_) {
    list_.push_back(std::move(item));
  }
}

std::shared_ptr<object> object_list::pop() {
  std::shared_ptr<object> item = std::move(list_.back());
  list_.pop_back();
  return item;
}

std::shared_ptr<object> object_list::pop(
    std::vector<std::shared_ptr<object>>::iterator::difference_type i) {
  auto index = list_.begin() + i;
  std::shared_ptr<object> item = std::move(*index);
  list_.erase(index);
  return item;
}

void object_list::reverse() { std::reverse(list_.begin(), list_.end()); }

std::ostream &object_list::print(std::ostream &a) const {
  a << '[' << *(list_.front());
  std::for_each(
      ++list_.cbegin(), list_.cend(),
      [&](const std::shared_ptr<object> &b) -> void { a << ", " << *b; });
  a << ']';
  return a;
}

bool object_list::lt(const object &b) const {
  auto b_list = dynamic_cast<const object_list &>(b);
  return std::lexicographical_compare(
      list_.cbegin(), list_.cend(), b_list.list_.cbegin(), b_list.list_.cend());
}
