#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

using std::vector;

long long binary_search(const vector<long long> &a, long long first, long long last, long long &x) {
  long long result = 0, mid = first + (last - first)/2;
  if(last < first || first > last) return -1;
  if(a[mid] == x){
    return mid;
  }
  if(x > a[mid]){
    result = binary_search(a, mid+1, last, x);
  }
  else if(x < a[mid]){
    result = binary_search(a, first, mid-1, x);
  }
  else{
    return -1;
  }
  return result;
}

long long linear_search(const vector<long long> &a, long long x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  a[0] = 1;
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  long long m;
  std::cin >> m;
  vector<long long> b(m);
  b[0] = 0;
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  std::cout << "Linear Search: " << std::endl;
  for (long long i = 0; i < m; ++i) {
    std::cout << linear_search(a, b[i]) << ' ';
  }

  std::cout << std::endl;
  std::cout << "Binary Search: " << std::endl;
  for (long long i = 0; i < m; ++i) {
    std::cout << binary_search(a, 0, n-1, b[i]) << ' ';
  }

/*

{
  auto start_time = std::chrono::high_resolution_clock::now();
  for (long long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    linear_search(a, b[i]);
  }
  auto stop_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
  std::cout << "Linear Search: " << dur_ms.count() << " ms" << std::endl;
}

{
  auto start_time = std::chrono::high_resolution_clock::now();
  for (long long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    binary_search(a, 0, n, b[i]);
  }
  auto stop_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
  std::cout << "Binary Search: " << dur_ms.count() << " ms" << std::endl;
}
*/

}
