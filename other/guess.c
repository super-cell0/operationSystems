#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int limit = 100;
    int number_of_try = 7;
    int guess;

    srand(time(NULL));
    int reward = (rand() % 100 + 1);
    printf("reward: %d\n", reward);

    while (number_of_try > 0) {
        printf("[%d] please enter your guess: ", number_of_try);
        scanf("%d", &guess);
        printf("your guess number: %d\n", guess);
        if (guess == reward) {
            printf("you win\n");
            break;
        } else if (guess > reward) {
            printf("guess > reward\n");
        } else {
            printf("guess < reward\n");
        }
        number_of_try --;
    }

    if (number_of_try == 0) {
        printf("you lose");
    }
    
    return 0;
}