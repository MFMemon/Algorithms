#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;

template <typename t>
std::ostream& operator<<(std::ostream & os, std::vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
    if((i+1)==0){
      os << '\n';
    }
  }
  return os;
}


bool sort_func(int i, int j) {return i > j ;}


int partition3(vector<int> &A) {

  int sum_A = 0;
  for(int i=0; i<A.size(); i++) sum_A += A[i];

  std::cout << "sum: " << sum_A%3 << std::endl;

  if(A.size() < 3 || sum_A % 3 != 0) return 0;

  std::sort(A.begin(),A.end(),sort_func);

  int part_sum = (sum_A/3) + 1;

  for(int k=1; k<=3; k++){
    int A_ind = A.size() + 1;
    vector<int> part(A_ind*part_sum,0);
    for(int i=1; i<A_ind; i++){
      for(int j=1; j<part_sum; j++){
        int cur_pos = part_sum*i + j;
        int prev = part[cur_pos - part_sum];
        part[cur_pos] = prev;
        if(A[i-1]<=j){
          int cur_sum = part[cur_pos - part_sum - A[i-1]];
          part[cur_pos] = std::max(cur_sum + A[i-1], prev);
        }
      }
    }

    int chk_ind = part.size() - 1;
    int rem_ind = A.size() - 1;
    vector<int> used_elem;

    while(chk_ind>0 && rem_ind>=0){
      int chk_elem = A[rem_ind];
      if(part[chk_ind] > part[chk_ind - part_sum]){
        used_elem.push_back(A[rem_ind]);
        A[rem_ind] = 0;
        chk_ind = chk_ind - chk_elem - part_sum;
      }
      else{
        chk_ind = chk_ind - part_sum;
      }
      rem_ind--;
    }
    std::cout << used_elem << std::endl;
    if(part[part.size()-1]!=(part_sum-1)){
      return 0;
    }

  }

  return 1;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << "A: " << A << std::endl;
  std::cout << partition3(A) << '\n';
}
