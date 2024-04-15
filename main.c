#include <stdio.h>
#include <unistd.h>

char isPrime(int number) {
    for (int i = 2; i < number; i++) { // every number is divisible by 1, so start at 2
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int number = 2;

    while (number < 200) {
        if (isPrime(number)) {
            printf("%d\n", number);
            sleep(1);
        }

        number++;
    }

    return 0;
}