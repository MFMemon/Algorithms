#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;

template <typename t>
std::ostream& operator<<(std::ostream & os, std::vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

int edit_distance(const string &str1, const string &str2) {
  size_t str1_len = str1.length() + 1;
  size_t str2_len = str2.length() + 1;
  vector<size_t> dist(str1_len*str2_len,0);
  for(size_t i=0; i<str1_len; i++) dist[i] = i;
  for(size_t i=0; i<dist.size(); i+=str1_len) dist[i] = i/str1_len;


  for(size_t j=1; j<str2_len; j++){
    for(size_t i=1; i<str1_len; i++){
      size_t cur_pos = str1_len*j + i;
      size_t ins = dist[cur_pos - str1_len];
      size_t del = dist[cur_pos - 1];
      size_t mtch = dist[cur_pos - str1_len - 1];
      if(str1[i-1]==str2[j-1]){
        dist[cur_pos] = std::min(ins + 1, del + 1);
        dist[cur_pos] = std::min(dist[cur_pos], mtch);
      }
      else{
        dist[cur_pos] = std::min(ins + 1, del + 1);
        dist[cur_pos] = std::min(dist[cur_pos], mtch + 1);
      }
    }
  }

  return (int)dist[dist.size() - 1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
