#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>

volatile sig_atomic_t stop = 0;
int number = 2;

void setNonCanonicalMode(struct termios term) {
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void setCanonicalMode(struct termios term) {
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

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("%d\n", number);
        stop = 1;
    }
}

int main() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);

    setNonCanonicalMode(term);

    signal(SIGINT, handle_signal);

    while (number < 200) {
        if (isPrime(number)) {
            sleep(1);
        }

        number++;
    }

    setCanonicalMode(term);
    return 0;
}

