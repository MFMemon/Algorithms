#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}



long long get_fibonacci_partial_sum_fast(long long from, long long to) {

  int counter;
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;
    int length = 0;
    std::vector<long long int> fib_vector;
    fib_vector.push_back(previous);
    fib_vector.push_back(current);

    for (long long i = 0; i < to + 1; ++i) {

        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        fib_vector.push_back(current);

        if(i > 0 & tmp_previous % 10 == 0 && previous % 10 == 1 && current % 10 == 1){
          length = i;
          break;
        }

    }

    if (length == 0){
      return (fib_vector[to + 2] - fib_vector[from + 1]) % 10;
    }
    else{

      int to_index = to % length;
      int from_index = from % length;

      if(to_index < from_index){
        int diff;
        diff = from_index - to_index;
        to_index = (from_index + diff + 1) % length;
        return (fib_vector[to_index + 2] - fib_vector[from_index + 1]) % 10;
      }

      else{
        return (fib_vector[to_index + 2] - fib_vector[from_index + 1]) % 10;
      }
    }

}



int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
