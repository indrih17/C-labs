// Calculate the sum of the squares of the prime numbers in the interval [M, N].

#include <iostream>

bool isPrime(int x) {
    for (int i = 2; i < x/2 + 1; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    std::cout << x << " is a prime\n";
    return true;
}

int nextPrimeNumber(int x) {
    int i = x + 1;
    while (!isPrime(i)) { 
        i++;
    }
    return i;
}

long sumOfSquaresOfPrimeNumbersInInterval(int first, int last) {
    long sum = 0;
    if (isPrime(first)) {
        sum += first * first;
    }
    int i = nextPrimeNumber(first);
    while (i <= last) {
        sum += i * i;
        i = nextPrimeNumber(i);
    }
    return sum;
}

int main() {
    int first, last;
    std::cout << "Enter the first element: ";
    std::cin >> first;
    std::cout << "Enter the last element: ";
    std::cin >> last;

    long sum = sumOfSquaresOfPrimeNumbersInInterval(first, last);
    std::cout << "The sum of the squares of the prime numbers in the interval [";
    std::cout << first << ", " << last << "] = " << sum << std::endl;
}