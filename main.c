#include <stdio.h>

char isPrime(int number) {
    for (int i = 2; i < number; i++) { // every number is divisible by 1, so start at 2
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int number = 20;

    if (isPrime(number)) {
        printf("%d is prime\n", number);
    } else {
        printf("%d is not prime\n", number);
    }

    return 0;
}