#include <iostream>
#include <chrono>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current ;
    }

    return current % 10;
}



long long get_fibonacci_last_digit_fast(int n) {
  int counter = 0;

  if (n <= 1)
      return n;

  long long previous = 0;
  long long current  = 1;

  for (int i = 0; i < n - 1; ++i) {
      long long tmp_previous = previous;
      previous = current;
      current = tmp_previous % 1000 + current % 1000;
      counter++;
  }

  return current % 10;
}


int main() {
    int n;

    {
      auto start_time = std::chrono::high_resolution_clock::now();
      get_fibonacci_last_digit_fast(55555);
      auto stop_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
      std::cout << "Time with n input: " << dur_ms.count() << " ms" << std::endl;
    }

    {
      auto start_time = std::chrono::high_resolution_clock::now();
      get_fibonacci_last_digit_fast(555555);
      auto stop_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
      std::cout << "Time with n*10 input: " << dur_ms.count() << " ms" << std::endl;
    }

    int c = get_fibonacci_last_digit_fast(2000);
    int d = get_fibonacci_last_digit_fast(20000);
    std::cout << d << " , " << c << '\n';
    }
