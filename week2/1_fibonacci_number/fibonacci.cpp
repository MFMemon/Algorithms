#include <iostream>
#include <cassert>
#include <unordered_map>
#include <chrono>

std::unordered_map<long long, unsigned int64_t> memo;

int fibonacci_naive(int n) {
    if (n <= 2)
        return 1;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

unsigned long long int fibonacci_fast(long long n) {

  unsigned long long int fib;

  if(n==1 || n==2) {
    memo[n] = 1;
    return 1;
  }

  if(n==0) {
    memo[n] = 0;
    return 0;
  }

  if(memo.count(n)) return memo[n];

  fib = fibonacci_fast(n-1) + fibonacci_fast(n-2);
  memo[n] = fib;

return fib;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';

    return 0;
}
