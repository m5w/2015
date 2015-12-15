#include "object_int.hpp"
#include "object_list.hpp"

#include <chrono>
#include <iostream>
#include <limits>
#include <random>

int main() {
  std::random_device RandomDevice_;
  std::default_random_engine RandomEngine_(RandomDevice_());
  std::uniform_int_distribution<int8_t> UniformDistribution_(
      std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max());
  object_list L;
  for (auto Remaining =
           static_cast<size_t>(std::numeric_limits<int16_t>::max());
       Remaining != 0; --Remaining) {
    L.append(object_int(UniformDistribution_(RandomEngine_)));
  }

  std::chrono::time_point<std::chrono::steady_clock> MergeSortBegin,
      MergeSortEnd, SelectionSortBegin, SelectionSortEnd;
  MergeSortBegin = std::chrono::steady_clock::now();
  object_list::sort(L);
  MergeSortEnd = std::chrono::steady_clock::now();
  SelectionSortBegin = std::chrono::steady_clock::now();
  L.selection_sort();
  SelectionSortEnd = std::chrono::steady_clock::now();
  std::cout << "mergeSort:     "
            << std::chrono::duration<long double>(MergeSortEnd - MergeSortBegin)
                   .count() << "\nselectionSort: "
            << std::chrono::duration<long double>(
                   SelectionSortEnd - SelectionSortBegin).count() << '\n';
}
