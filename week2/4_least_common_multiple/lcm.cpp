#include <iostream>
#include <algorithm>
#include <chrono>
#include <cmath>

long long lcm_naive(int a, int b) {
  for (long long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}


int gcd_fast(int a, int b) {

  int gcd;
  if(a + b == fabs(a - b)) return std::max(a,b);
  bool a_is_large = a > b ;
  if(a % b == 0) return b;
  if(b % a == 0) return a;
  if(a > b){
    gcd = gcd_fast(b , a % b);
    return gcd;
  }
  else if(b > a){
    gcd = gcd_fast(a , b % a);
    return gcd;
  }
  return 0;
}


long long lcm_fast(int a, int b){
  long long lcm;
  int gcd, first_mul, second_mul;

  gcd = gcd_fast(a,b);
  first_mul = a / gcd;
  second_mul = b / gcd ;
  lcm = (long long) gcd * first_mul * second_mul;
  return lcm;
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
