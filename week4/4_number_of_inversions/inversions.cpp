#include <iostream>
#include <vector>
#include <utility>

using std::vector;
long long number_of_inversions = 0;
template <typename t>
std::ostream& operator<<(std::ostream & os, vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}


vector<long long> mergesort(vector<long long> &a, vector<long long>d, size_t left, size_t right, long long & number_of_inversions){

  if(right<=left){
    return {a[left]};
  }
  long long mid = left + (right-left)/2;
  vector<long long> b = mergesort(a, d, left, mid, number_of_inversions);
  vector<long long> c = mergesort(a, d, mid+1, right, number_of_inversions);

  while(!b.empty() && !c.empty()){
    long long x = b.front();
    long long y = c.front();
    if(x<=y){
      d.push_back(x);
      b.erase(b.begin());
    }
    else{
      d.push_back(y);
      number_of_inversions += b.size();
      c.erase(c.begin());
    }
  }

  if(!b.empty()){
    d.insert(d.end(),b.begin(),b.end());
  }
  else if(!c.empty()){
    d.insert(d.end(),c.begin(),c.end());
  }

  return d;
}


long long get_number_of_inversions(vector<long long> &a, vector<long long> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  mergesort(a,b,0,a.size()-1,number_of_inversions);
  return number_of_inversions;
}

int main() {

  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<long long> b;

  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
