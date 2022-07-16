#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  vector<int> opt_move(n+1,0);

  opt_move[0] = 0;
  opt_move[1] = 0;
  opt_move[2] = 1;
  opt_move[3] = 1;

  for(int i=4; i<=n; i++){
    int x = 1000001;
    if(i%2==0){
      x = std::min(x,(opt_move[i/2]) + 1);
    }
    if(i%3==0){
      x = std::min(x,(opt_move[i/3]) + 1);
    }
    x = std::min(x, (opt_move[i-1]) + 1);
    opt_move[i] = x;
  }

  sequence.push_back(n);
  int back = sequence.back();

  while (back > 1) {
    int divby2 = 1000001, divby3 = 1000002;
    int prev = 0, opt = 0;

    if(back%2==0){
      divby2 = opt_move[back/2];
    }
    if(back%3==0){
      divby3 = opt_move[back/3];
    }
    prev = opt_move[back-1];
    if(divby2 < divby3){
      if(prev <= divby2){
        opt = back - 1;
      }
      else{
        opt = back/2;
      }
    }
    else if(divby3 <= divby2){
      if(prev <= divby3){
        opt = back - 1;
      }
      else{
        opt = back/3;
      }
    }
    sequence.push_back(opt);
    back = sequence.back();
  }

  reverse(sequence.begin(),sequence.end());
  return sequence;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }

}
