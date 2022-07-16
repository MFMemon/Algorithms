#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;

template <typename t>
std::ostream& operator<<(std::ostream & os, std::vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
    if((i+1)%11==0){
      os << '\n';
    }
  }
  return os;
}

int optimal_weight(int W, const vector<int> &w) {

  int current_weight = 0;

  int W_ind = W + 1;
  int weights_ind = w.size() + 1;
  vector<int> fill(W_ind*weights_ind,0);

  for(int i=1; i<weights_ind; i++){
    for(int j=1; j<W_ind; j++){
      int cur_pos = W_ind*i + j;
      int prev = fill[cur_pos - W_ind];
      fill[cur_pos] = prev;
      if(w[i-1]<=j){
        int cur_wt = fill[cur_pos - W_ind - w[i-1]];
        fill[cur_pos] = std::max(cur_wt + w[i-1], prev);
      }
    }
  }
  std::cout << fill << std::endl;

  return fill[fill.size()-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
