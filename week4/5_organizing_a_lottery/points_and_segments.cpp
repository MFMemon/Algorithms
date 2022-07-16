#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>


using std::vector;
using std::pair;

typedef long long A;

template <typename a, typename b>
std::ostream& operator<<(std::ostream & os, pair<a,b> &object){
  os << "[" << object.first << "," << object.second << "]";
  return os;
}

template <typename t>
std::ostream& operator<<(std::ostream & os, vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

bool sort_function(A i, A j){
  return i < j;
}

vector<int> fast_count_segments(vector<A> &starts, vector<A> &ends, vector<A> &points) {
  vector<int> cnt(points.size(),0);
  std::sort(starts.begin(), starts.end(), sort_function);
  std::sort(ends.begin(), ends.end(), sort_function);


  for (size_t i = 0; i < points.size(); i++){
    int right_starts = starts.size()-1;
    int left_starts = 0, mid_starts = 0;
    while(right_starts>=left_starts){
      mid_starts = left_starts + (right_starts-left_starts)/2;
      if(starts[mid_starts]<=points[i]){
        left_starts = mid_starts+1;
      }
      else if(starts[mid_starts]>points[i]){
        right_starts = mid_starts-1;
      }
      mid_starts = left_starts < right_starts ? left_starts : right_starts;
    }
    int right_ends = ends.size()-1;
    int left_ends = 0, mid_ends = 0;
    while(right_ends>=left_ends){
      mid_ends = left_ends + (right_ends-left_ends)/2;
      if(ends[mid_ends]>=points[i]){
        right_ends = mid_ends-1;
      }
      else if(ends[mid_ends]<points[i]){
        left_ends = mid_ends+1;
      }
      mid_ends = left_ends > right_ends ? left_ends : right_ends;
    }
    cnt[i] = mid_starts - (mid_ends-1);
  }

  return cnt;
}

vector<int> naive_count_segments(vector<A> &starts, vector<A> &ends, vector<A> &points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<A> starts(n,0), ends(n,0);
  vector<A> points(m,0);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }

  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }

}
