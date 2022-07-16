#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum = 0, cur_diff = 0, nxt_diff = 0, last = 0, nxt = 0;

  while(sum < n){
    cur_diff = n - sum ;
    nxt = last + 1;
    sum += nxt ;
    nxt_diff = n - sum;
    if(nxt_diff > nxt || nxt_diff == 0){
      summands.push_back(nxt);
    }
    else{
      summands.push_back(cur_diff);
      sum += cur_diff;
    }
    last = summands.back();
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';

  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }

}
