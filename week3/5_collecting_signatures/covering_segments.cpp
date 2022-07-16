#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  long long start, end;
};


std::ostream& operator<<(std::ostream & os, Segment &object){
  os << "[" << object.start << "," << object.end << "]";
  return os;
}

template <typename t>
std::ostream& operator<<(std::ostream & os, vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

bool operator==(Segment &left,Segment &right){
  if(left.start==right.start && left.end==right.end) return true;
  else return false;
}

bool operator!=(Segment &left,Segment &right){
  return !(left==right);
}

bool sort_function(Segment i, Segment j){
  return i.end > j.end;
}


vector<long long> optimal_points(vector<Segment> &segments) {

  int nxt = 0, size = segments.size();
  long long temp_point = 0;
  vector<long long> points;

  Segment init;
  init.start = 0;
  init.end = 0;

  vector<Segment> visited(size, init);

  std::sort(segments.begin(), segments.end(), sort_function);

  for(int i=0; i<size; i++){
    if(visited[i]!=segments[i]){
      visited[i] = segments[i];
      points.push_back(segments[i].start);
      nxt = i + 1;
      while(nxt < size && segments[nxt].end >= points.back()){
        visited[nxt] = segments[nxt];
        temp_point = segments[nxt].start;
        if(temp_point > points.back()){
          points.pop_back();
          points.push_back(temp_point);
        }
        nxt++;
      }
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<long long> points = optimal_points(segments);

  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }

}
