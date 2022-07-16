#include <iostream>
#include <vector>

template <typename t>
std::ostream& operator<<(std::ostream & os, std::vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

int get_change(int m) {
  std::vector<int> coins = {1,3,4};
  std::vector<int> nofcoins(m+1, 10000);
  nofcoins[0] = 0;

  for(int i=1; i<=m;i++){
    for(int j=0; j<coins.size(); j++){
      if(i>=coins[j]){
        if(nofcoins[i-coins[j]] + 1 < nofcoins[i]){
          nofcoins[i] = nofcoins[i-coins[j]] + 1;
        }
      }
    }
  }
  return nofcoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
