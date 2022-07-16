#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>

int naive_counter=0;
int fast_counter=0;


int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }naive_counter++;
  }
  return current_gcd;
}


int gcd_fast(int a, int b) {
  fast_counter++;
  int gcd;
  if(a + b == fabs(a - b)) return std::max(a,b);
  bool a_is_large = a > b ;
  if(a % b == 0) return b;
  if(b % a == 0) return a;
  if(a_is_large){
    gcd = gcd_fast(b , a % b);
    return gcd;
  }
  else if(!a_is_large){
    gcd = gcd_fast(a , b % a);
    return gcd;
  }
  return 0;
}


int main() {
  int a, b, fast, naive;
  std::cin >> a >> b;

  {
    auto start_time = std::chrono::high_resolution_clock::now();
    fast = gcd_fast(a,b);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> dur_ms = stop_time - start_time;
    std::cout << "Fast runs in: " << dur_ms.count() << " ms" << " and returns " << fast << std::endl;
  }

  {
    auto start_time = std::chrono::high_resolution_clock::now();
    naive = gcd_naive(a,b);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> dur_ms = stop_time - start_time;
    std::cout << "Naive runs in: " << dur_ms.count() << " ms" << " and returns " << naive << std::endl;
  }

  std::cout << naive_counter << std::endl;

  std::cout << fast_counter << std::endl;

  return 0;
}
