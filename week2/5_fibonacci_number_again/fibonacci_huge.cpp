#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
  int counter;
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;


    for (long long i = 0; i < n - 1; ++i) {

        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous % m + current % m;
        counter++;
    }

    return current % m;
}


long long get_fibonacci_huge_fast(long long n, long long m) {
  int counter;
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    int length = 0;
    std::vector<long long> fib_vector;
    fib_vector.push_back(previous);
    fib_vector.push_back(current);

    for (long long i = 0; i < n - 1; ++i) {

        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous % m + current % m;
        fib_vector.push_back(current);

        if(i > 0 & tmp_previous % m == 0 && previous % m == 1 && current % m == 1){
          length = i;
          break;
        }

    }
    if (m > n || length == 0) return fib_vector[n] % m;
    else return fib_vector[n % length] % m;

}



int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
