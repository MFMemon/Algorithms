#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <chrono>


using std::vector;

template <typename t>
std::ostream& operator<<(std::ostream & os, vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  std::unordered_map<int, int> count_map;
  int count = 0;
  for(int i=0; i<a.size(); i++){
    count_map[a[i]] += 1;
    if(count_map[a[i]] > a.size()/2) return 1;
  }

  return -1;
}

int get_majority_element_naive(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  for(int i=0; i<a.size(); i++){
    int count = 1;
    for(int j=i+1; j<a.size(); j++){
      if(a[i]==a[j]){
        count += 1;
      }
    }
    if(count > a.size()/2){
      return 1;
    }
  }

  return -1;
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);

  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';

}
