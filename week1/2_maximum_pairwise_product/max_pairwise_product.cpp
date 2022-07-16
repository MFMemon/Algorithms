#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <chrono>


bool is_even(int val){
  if(val%2 == 0) return true;
  else return false;
}

std::ostream& operator<<(std::ostream & os, std::vector<int> &object){
  for(int i=0; i<object.size(); i++){
    os << object[i] << " ";
  }
  return os;
}

void heapify(int index, std::vector<int> & numbers){
  int left_child_index = index * 2 + 1;
  int right_child_index = index * 2 + 2;

  if(left_child_index >= numbers.size()){
    return;
  }
  else if(right_child_index >= numbers.size() && numbers[left_child_index] < numbers[index]){
    std::swap(numbers[left_child_index],numbers[index]);
    return;
  }
  else if (right_child_index < numbers.size() && left_child_index < numbers.size()){
    int min_child_index = numbers[right_child_index] < numbers[left_child_index] ?  right_child_index : left_child_index ;
    if(numbers[index] > numbers[min_child_index]){
      std::swap(numbers[index], numbers[min_child_index]);
      heapify(min_child_index, numbers);
    }
  }
  return;
}

int64_t DefaultMaxPairwiseProduct(const std::vector<int>& numbers){
  int64_t product = 0;
  int n = numbers.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        product = std::max(product, (int64_t) numbers[i] * numbers[j]);
      }
    }
  return product;
}


int64_t MaxPairwiseProduct(std::vector<int> & numbers){

  int64_t product = 0;
  int first_max = 0;
  int second_max = 0;
  int loop_iter = numbers.size();


  if(numbers.size() == 2){
    product = (int64_t) numbers[0] * numbers[1];
  }

  else{

    if(!is_even(numbers.size())) {
      first_max = numbers.back();
      loop_iter--;
    }

    for(int i=0; i<loop_iter; i=i+2){

      if(numbers[i] >= numbers[i+1] && numbers[i] >= first_max && first_max >= numbers[i+1]){
        second_max = first_max;
        first_max = numbers[i];
      }
      else if(numbers[i] >= numbers[i+1] && numbers[i] >= first_max && numbers[i+1] > second_max){
        second_max = numbers[i+1];
        first_max = numbers[i];
      }
      else if(numbers[i+1] >= numbers[i] && numbers[i+1] >= first_max && first_max >= numbers[i]){
          second_max = first_max;
          first_max = numbers[i+1];
      }
      else if(numbers[i+1] >= numbers[i] && numbers[i+1] >= first_max && numbers[i] > second_max){
        second_max = numbers[i];
        first_max = numbers[i+1];
      }
      else if(numbers[i+1] < first_max && numbers[i] < first_max && numbers[i] >= numbers[i+1] & numbers[i] > second_max){
          second_max = numbers[i];
      }
      else if(numbers[i+1] < first_max && numbers[i] < first_max && numbers[i+1] >= numbers[i] & numbers[i+1] > second_max){
        second_max = numbers[i+1];
      }
    }

    product = (int64_t) first_max * second_max;
  }
return product;
}




int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        numbers[i] = rand()*rand() % 66632145;
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    std::cout << DefaultMaxPairwiseProduct(numbers) << "\n";

    return 0;
}
