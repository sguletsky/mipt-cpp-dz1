#include <iomanip>
#include <iostream>
#include <utility>

int less_then_zero(const int* temperatures, int array_size) {
  int counter = 0;
  for (int i = 0; i < array_size; i++) {
    if (temperatures[i] < 0) {
      counter += 1;
    }
  }
  return counter;
}

std::pair<int, int> the_most_the_min(const int* temperatures, int array_size) {
  int maximum = temperatures[0];
  int minimum = temperatures[0];
  for (int i = 1; i < array_size; i++) {
    if (temperatures[i] > maximum) {
      maximum = temperatures[i];
    } else if (temperatures[i] < minimum) {
      minimum = temperatures[i];
    }
  }
  return {minimum, maximum};
}

double average_temperature(const int* temperatures, int array_size) {
  long long sum = 0;

  for (int i = 0; i < array_size; ++i) {
    sum += temperatures[i];
  }
  return static_cast<double>(sum) / array_size;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int number;
  std::cin >> number;
  int* temperatures = new int[number];
  for (int i = 0; i < number; i++) {
    std::cin >> temperatures[i];
  }
  std::pair<int, int> extremes = the_most_the_min(temperatures, number);

  std::cout << std::fixed << std::setprecision(1)
            << average_temperature(temperatures, number) << '\n';
  std::cout << extremes.first << ' ' << extremes.second << '\n';
  std::cout << less_then_zero(temperatures, number) << '\n';

  delete[] temperatures;
}