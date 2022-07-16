#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <chrono>

using std::vector;

template <typename t, typename T>
std::ostream& operator<<(std::ostream & os, std::pair<t,T> &object){
  os << "{" << object.first << "," << object.second << "}";
  return os;
}

template <typename t>
std::ostream& operator<<(std::ostream & os, std::vector<t> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

void heapify(int index, vector<std::pair<double,int>> & max_heap){
  int left_child_index = index * 2 + 1;
  int right_child_index = index * 2 + 2;

  if(left_child_index >= max_heap.size()){
    return;
  }
  else if(right_child_index >= max_heap.size() && max_heap[left_child_index].first > max_heap[index].first){
    std::swap(max_heap[left_child_index],max_heap[index]);
    return;
  }
  else if (right_child_index < max_heap.size() && left_child_index < max_heap.size()){
    int max_child_index = max_heap[right_child_index].first > max_heap[left_child_index].first ?  right_child_index : left_child_index ;
    if(max_heap[index].first < max_heap[max_child_index].first){
      std::swap(max_heap[index], max_heap[max_child_index]);
      heapify(max_child_index, max_heap);
    }
  }
  return;
}


double get_optimal_value_fast(int capacity, vector<int> weights, vector<int> values) {

  if(capacity == 0) return 0;

  vector<std::pair<double,int>> max_heap(values.size());
  vector<std::pair<double,int>> sorted_values(values.size());

  double value = 0.0 ;
  int a = 0, item_wt = 0, rem_cap = capacity;

  for(int i=0; i<values.size(); i++){
    max_heap[i].first = (double)values[i] / weights[i];
    max_heap[i].second = weights[i];
  }

  for(int i=max_heap.size()/2; i>=0; i--){
    heapify(i,max_heap);
  }

  for(int i=0; i<values.size(); i++){
    sorted_values[i] = max_heap[0];
    std::swap(max_heap[0],max_heap[max_heap.size() - 1]);
    max_heap.pop_back();
    heapify(0,max_heap);
  }

  while(rem_cap>0){
    item_wt = std::min(rem_cap,sorted_values[a].second);
    value = value + sorted_values[a].first * item_wt;
    rem_cap = rem_cap - item_wt;
    a++;
  }

  return value;
}


double get_optimal_value_naive(int capacity, vector<int> weights, vector<int> values) {

  if(capacity == 0) return 0;


  double value = 0.0, v_t_w_ratio = 0.0 ;
  int item_wt = 0, max_index = 0, rem_cap = capacity;

  while(rem_cap>0){
    double max_v_t_w_ratio = 0.0 ;

    for(int i=0; i<values.size();i++){

      if (weights[i] > 0){
        v_t_w_ratio = (double) values[i] / weights[i];

        if(v_t_w_ratio > max_v_t_w_ratio){
          max_v_t_w_ratio = v_t_w_ratio;
          max_index = i;
        }
      }
    }

    item_wt = std::min(rem_cap,weights[max_index]);

    value = value + max_v_t_w_ratio * item_wt;
    rem_cap = rem_cap - item_wt;
    weights[max_index] = weights[max_index] - item_wt;

  }

  return value;
}


int main() {
  int n_small, n_large;
  int capacity_small, capacity_large;
  std::cin >> n_small >> capacity_small;
  std::cin >> n_large >> capacity_large;


  std::uniform_int_distribution<int> values_dist(0,200000);
  std::uniform_int_distribution<int> weights_dist(0,200000);
  std::default_random_engine generator;

  vector<int> values_small(n_small);
  vector<int> weights_small(n_small);
  for (int i = 0; i < n_small; i++) {
    values_small[i] = values_dist(generator);
    weights_small[i] = weights_dist(generator);
  }

  vector<int> values_large(n_large);
  vector<int> weights_large(n_large);
  for (int i = 0; i < n_large; i++) {
    values_large[i] = values_dist(generator);
    weights_large[i] = weights_dist(generator);
  }


  {
    auto start_time = std::chrono::high_resolution_clock::now();
    get_optimal_value_naive(capacity_small, weights_small, values_small);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
    std::cout << "Naive runs for n in: " << dur_ms.count() << " ms" << std::endl;
  }

  {
    auto start_time = std::chrono::high_resolution_clock::now();
    get_optimal_value_naive(capacity_large, weights_large, values_large);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
    std::cout << "Naive runs for n x 10 in: " << dur_ms.count() << " ms" << std::endl;
  }

  {
    auto start_time = std::chrono::high_resolution_clock::now();
    get_optimal_value_fast(capacity_small, weights_small, values_small);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
    std::cout << "Fast runs for n in: " << dur_ms.count() << " ms" << std::endl;
  }

  {
    auto start_time = std::chrono::high_resolution_clock::now();
    get_optimal_value_fast(capacity_large, weights_large, values_large);
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> dur_ms = stop_time - start_time;
    std::cout << "Fast runs for n x 10 in: " << dur_ms.count() << " ms" << std::endl;
  }


  return 0;
}
