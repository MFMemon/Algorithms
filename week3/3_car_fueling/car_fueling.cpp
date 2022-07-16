#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {

  int refills = 0;

  if(stops[0] > tank) return -1;

  int dist_cov = 0;
  int stops_index = 0;
  int start_dist = 0;

  while(stops_index < stops.size() && dist_cov < dist){

    dist_cov = stops[stops_index];

    if(stops_index == stops.size() - 1){
      if(dist - dist_cov > tank ){
        return -1;
      }
      else if(dist - start_dist > tank){
        refills++;
      }
    }
    else{
      if(stops[stops_index+1] - dist_cov > tank){
        return -1;
      }
      else if(stops[stops_index+1] - start_dist > tank){
        refills++;
        start_dist = stops[stops_index];
      }
    }
    stops_index++;
  }

  return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
