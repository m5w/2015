#include "object_list.hpp"

#include "object.hpp"

#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

std::vector<std::shared_ptr<object>>::size_type object_list::binary_search(
    const std::vector<std::shared_ptr<object>>::size_type minimum,
    decltype(minimum) maximum, const object &x) {
  const auto average = (minimum + maximum) / 2;

  const auto &average_object = *list_.at(average);

  if (average_object < x)
    return binary_search(average, maximum, x);
  else if (average_object == x)
    return average;
  else
    return binary_search(minimum, average, x);
}

std::pair<object_list, object_list> object_list::splice(const object_list &a) {
  std::pair<object_list, object_list> Spliced;
  auto Middle = a.list_.cbegin() + a.list_.size() / 2;
  Spliced.first.list_ =
      std::vector<std::shared_ptr<object>>(a.list_.cbegin(), Middle);
  Spliced.second.list_ =
      std::vector<std::shared_ptr<object>>(Middle, a.list_.cend());
  return Spliced;
}

object_list object_list::merge(const object_list &a, const object_list &b) {
  object_list Merged;

  {
    auto a_iterator = a.list_.cbegin();
    auto b_iterator = b.list_.cbegin();

    {
      const auto a_end = a.list_.cend();
      const auto b_end = b.list_.cend();

      while (a_iterator != a_end && b_iterator != b_end) {
        if (**a_iterator < **b_iterator) {
          Merged.list_.push_back(*a_iterator);
          ++a_iterator;
        } else {
          Merged.list_.push_back(*b_iterator);
          ++b_iterator;
        }
      }

      while (a_iterator != a_end) {
        Merged.list_.push_back(*a_iterator);
        ++a_iterator;
      }

      while (b_iterator != b_end) {
        Merged.list_.push_back(*b_iterator);
        ++b_iterator;
      }
    }
  }

  return Merged;
}

object_list object_list::mergeSort(const object_list &a) {
  if (a.len() <= 1) {
    return a;
  }

  auto Spliced = splice(a);
  return merge(mergeSort(Spliced.first), mergeSort(Spliced.second));
}

std::vector<std::shared_ptr<object>>::size_type
object_list::search(const object &x) {
  return binary_search(0, list_.size() - 1, x);
}

object_list object_list::sort(const object_list &a) { return mergeSort(a); }

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

std::vector<std::shared_ptr<object>>::size_type object_list::len() const {
  return list_.size();
}

std::shared_ptr<object> object_list::deepcopy() const {
  std::shared_ptr<object_list> b(new object_list);

  for (const auto &item : list_) {
    b->list_.push_back(std::move(item->deepcopy()));
  }

  return std::static_pointer_cast<object>(std::move(b));
}

std::ostream &object_list::print(std::ostream &a) const {
  a << '[' << *(list_.front());
  std::for_each(
      ++list_.cbegin(), list_.cend(),
      [&](const std::shared_ptr<object> &b) -> void { a << ", " << *b; });
  a << ']';
  return a;
}

bool object_list::eq(const object &b) const {
  return list_ == dynamic_cast<const object_list &>(b).list_;
}

bool object_list::lt(const object &b) const {
  auto b_list = dynamic_cast<const object_list &>(b);
  return std::lexicographical_compare(
      list_.cbegin(), list_.cend(), b_list.list_.cbegin(), b_list.list_.cend());
}
