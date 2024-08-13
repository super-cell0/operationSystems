#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int max = 100;
    for (int i = 2; i<max; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}

bool is_prime(int num) {
    bool result = true;
    for (int j = 2; j<num; j++) {
        if (num % j == 0) {
            result = false;
            break;
        }
    }
    return result;
}