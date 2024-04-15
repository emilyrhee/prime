#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void setNonCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void setCanonicalMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char isPrime(int number) {
    for (int i = 2; i < number; i++) { // every number is divisible by 1, so start at 2
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int number = 2; // 2 is the first prime number
    setNonCanonicalMode();

    while (1) {
        if (isPrime(number)) {
            printf("%-8d    Quit [y/n]? ", number);
            fflush(stdout);

            char input;
            read(STDIN_FILENO, &input, 1);
            printf("%c\n", input);
            if (input == 'y' || input == 'Y') {
                setCanonicalMode();
                return 0;
            }
        }

        number++;
    }

    setCanonicalMode();
    return 0;
}