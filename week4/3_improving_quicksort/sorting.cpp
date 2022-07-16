#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using std::vector;
using std::swap;

int counter = 0;

template <typename t>
std::ostream& operator<<(std::ostream & os, vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}


int partition2(vector<long long> &a, int l, int r) {
  long long x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

std::pair<int,int> partition3(vector<long long> &a, int l, int r) {
  long long x = a[l];
  int m1 = l, m2 = l, temp = 0;

  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m1++;
      m2++;
      swap(a[m1],a[i]);
      if(m2 > m1){
        swap(a[m2], a[i]);
      }
    }
    else if (a[i] == x) {
      m2++;
      swap(a[m2],a[i]);
    }
  }
  swap(a[l], a[m1]);
  std::pair<int, int> result = std::make_pair(m1,m2);
  return result;
}

void randomized_quick_sort(vector<long long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  std::pair<int, int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  randomized_quick_sort(a, 0, a.size() - 1);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }

  return 0;
}
