#include <iostream>
#include <queue>

int get_change(int m) {
  int n = 0;
  int coins[3] = {1,5,10};

  while(m >= coins[0] && m <= 1000){
    n++;

    if(m >= coins[2]){
      m = m - coins[2];
    }

    else if(m >= coins[1]){
      m = m - coins[1];
    }

    else{
      m = m - coins[0];
    }

  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
