#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using std::vector;
using std::string;


bool str_chk(const int & nxt_front, string a, string b){
  int last_a, last_b;

  while(!a.empty() || !b.empty()){

    if(a.empty()){
      if(((int)(b[0] - '0')) > nxt_front){
        return true;
      }
      last_b = b[0] - '0';
      b.erase(0,1);
    }
    else if(b.empty()){
      if(((int)(a[0] - '0')) < nxt_front) {
        return true;
      }
      last_a = a[0] - '0';
      a.erase(0,1);
    }
    else{
      if(((int)(b[0] - '0')) > ((int)(a[0] - '0'))){
        return true;
      }
      last_a = a[0] - '0';
      last_b = b[0] - '0';
      a.erase(0,1);
      b.erase(0,1);
    }
  }

  if(last_b > last_a){
    return true;
  }
  else{
    return false;
  }

}

string largest_number(vector<string> a) {

  std::stringstream ret;
  string out, result;

  while(!a.empty()){

    int max_dig = 0, max_num = 0;

    for (size_t i = 0; i < a.size(); i++) {
      int nxt_front = a[i].front() - '0';
      int nxt_num = std::stoi(a[i]);

      if(nxt_front > max_dig) {
        max_dig = nxt_front;
        out = a[i];
        max_num = nxt_num;
        std::swap(a[i],a[0]);
      }
      else if(nxt_front == max_dig){
        bool chk = str_chk(nxt_front, out, a[i]);
        if(chk){
          out = a[i];
          max_num = nxt_num;
          std::swap(a[i],a[0]);
        }
      }
    }
    ret << out;
    a.erase(a.begin());
  }

  ret >> result;
  return result;
}



int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << std::endl;;
  return 0;
}
