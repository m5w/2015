#include "object_int.hpp"
#include "object_list.hpp"

#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <utility>

typedef std::chrono::duration<long, std::nano> DurationType;

template <typename IntType>
object_list
getRandomList(std::size_t Size,
              std::uniform_int_distribution<IntType> &UniformIntDistribution_,
              std::default_random_engine &DefaultRandomEngine_);

template <typename AlgorithmType> long timeAlgorithm(AlgorithmType Algorithm);

template <typename IntType>
long
timeMergeSort(std::size_t Size,
              std::uniform_int_distribution<IntType> &UniformIntDistribution_,
              std::default_random_engine DefaultRandomEngine_);

template <typename IntType>
long timeSelectionSort(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_);

template <typename IntType>
long timeBinarySearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_);

template <typename IntType>
long timeLinearSearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_);

template <typename IntType>
long timeAmortizedBinarySearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_, std::size_t Iterations);

template <typename IntType>
long timeAmortizedLinearSearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_, std::size_t Iterations);

int main() {
  std::random_device RandomDevice_;
  std::default_random_engine DefaultRandomEngine_(RandomDevice_());
  std::uniform_int_distribution<int8_t> UniformIntDistribution_(
      std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max());

  for (std::size_t Size = 512; Size != 0; --Size) {
    std::array<long, 6> Durations;
    Durations.fill(0);
    std::size_t Iterations = 1000;
    Durations.at(4) += timeAmortizedBinarySearch(
        Size, UniformIntDistribution_, DefaultRandomEngine_, Iterations);
    Durations.at(5) += timeAmortizedLinearSearch(
        Size, UniformIntDistribution_, DefaultRandomEngine_, Iterations);

    for (; Iterations != 0; --Iterations) {
      Durations.at(0) +=
          timeMergeSort(Size, UniformIntDistribution_, DefaultRandomEngine_);
      Durations.at(1) += timeSelectionSort(Size, UniformIntDistribution_,
                                           DefaultRandomEngine_);
      Durations.at(2) +=
          timeBinarySearch(Size, UniformIntDistribution_, DefaultRandomEngine_);
      Durations.at(3) +=
          timeLinearSearch(Size, UniformIntDistribution_, DefaultRandomEngine_);
    }

    std::cout << std::setw(3) << Size;

    for (const auto &Duration : Durations) {
      std::cout << std::setw(11) << Duration;
    }

    std::cout << '\n';
  }
}

template <typename IntType>
object_list
getRandomList(std::size_t Size,
              std::uniform_int_distribution<IntType> &UniformIntDistribution_,
              std::default_random_engine &DefaultRandomEngine_) {
  object_list L;
  for (; Size != 0; --Size) {
    L.append(object_int(UniformIntDistribution_(DefaultRandomEngine_)));
  }

  return L;
}

template <typename AlgorithmType> long timeAlgorithm(AlgorithmType Algorithm) {
  auto StartingTime = std::chrono::steady_clock::now();
  Algorithm();
  return (std::chrono::steady_clock::now() - StartingTime).count();
}

template <typename IntType>
long
timeMergeSort(std::size_t Size,
              std::uniform_int_distribution<IntType> &UniformIntDistribution_,
              std::default_random_engine DefaultRandomEngine_) {
  auto L = getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_);
  return timeAlgorithm([&]() -> void { auto M = object_list::sort(L); });
}

template <typename IntType>
long timeSelectionSort(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_) {
  auto L = getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_);
  return timeAlgorithm([&]() -> void { L.selection_sort(); });
}

template <typename IntType>
long timeBinarySearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_) {
  auto L = object_list::mergeSort(
      getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_));
  auto x = object_int(UniformIntDistribution_(DefaultRandomEngine_));
  return timeAlgorithm([&]() -> void {
    auto M = object_list::sort(L);
    M.search(x);
  });
}

template <typename IntType>
long timeLinearSearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_) {
  auto L = getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_);
  auto x = object_int(UniformIntDistribution_(DefaultRandomEngine_));
  return timeAlgorithm([&]() -> void { L.linear_search(x); });
}

template <typename IntType>
long timeAmortizedBinarySearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_, std::size_t Iterations) {
  auto L = getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_);
  return timeAlgorithm([&]() -> void {
    auto M = object_list::sort(L);

    for (; Iterations != 0; --Iterations) {
      M.search(object_int(UniformIntDistribution_(DefaultRandomEngine_)));
    }
  });
}

template <typename IntType>
long timeAmortizedLinearSearch(
    std::size_t Size,
    std::uniform_int_distribution<IntType> &UniformIntDistribution_,
    std::default_random_engine DefaultRandomEngine_, std::size_t Iterations) {
  auto L = getRandomList(Size, UniformIntDistribution_, DefaultRandomEngine_);
  return timeAlgorithm([&]() -> void {
    L.selection_sort();

    for (; Iterations != 0; --Iterations) {
      L.linear_search(
          object_int(UniformIntDistribution_(DefaultRandomEngine_)));
    }
  });
}
