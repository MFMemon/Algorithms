#include <iostream>
#include <vector>


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}


int fibonacci_sum_squares_fast(long long n) {
  int counter;
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int length = 0;
    std::vector<long long> fib_vector;
    fib_vector.push_back(previous);
    fib_vector.push_back(current);

    for (long long i = 0; i < n; ++i) {

        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        fib_vector.push_back(current);

        if(i > 0 & tmp_previous % 10 == 0 && previous % 10 == 1 && current % 10 == 1){
          length = i;
          break;
        }

    }
    if (length == 0) return fib_vector[n] % 10 * fib_vector[n + 1] % 10;
    else return fib_vector[n % length] % 10 * fib_vector[n % length + 1] % 10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
