#include "object_list.hpp"

#include "object.hpp"

#include <algorithm>
#include <memory>
#include <ostream>
#include <utility>
#include <vector>

decltype(object_list::list_)::const_iterator object_list::binary_search(
    const std::vector<std::shared_ptr<object>>::const_iterator::difference_type
        minimum,
    decltype(minimum) maximum, const object &x) const {
  const auto average = (minimum + maximum) / 2;

  if (average == minimum)
    return list_.cend();

  const auto &average_iterator = list_.cbegin() + average;

  if (**average_iterator < x)
    return binary_search(average, maximum, x);
  else if (**average_iterator == x)
    return average_iterator;
  else
    return binary_search(minimum, average, x);
}

decltype(object_list::list_)::const_iterator
object_list::linear_search(const object &x) const {
  const auto list_end = list_.cend();

  for (auto list_iterator = list_.cbegin(); list_iterator != list_end;
       ++list_iterator) {
    if (**list_iterator == x)
      return list_iterator;
  }

  return list_end;
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

void object_list::selection_sort() {
  const auto list_end = list_.cend();
  for (auto suffix_begin = list_.begin(); suffix_begin != list_end;
       ++suffix_begin) {
    auto selected = suffix_begin;

    for (auto suffix_iterator = suffix_begin + 1; suffix_iterator != list_end;
         ++suffix_iterator) {
      if (**suffix_iterator < **selected)
        selected = suffix_iterator;
    }

    std::swap(*suffix_begin, *selected);
  }
}

std::vector<std::shared_ptr<object>>::const_iterator
object_list::search(const object &x) const {
  return binary_search(list_.cbegin() - list_.cbegin(),
                       list_.cend() - list_.cbegin(), x);
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
  return list_ < dynamic_cast<const object_list &>(b).list_;
}
