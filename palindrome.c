#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

#define MAX 21

void select_sort(int num[], int count) {
    
}

void palindrome() {
    // 回文
    char str[MAX] = "";
    scanf("%20s", str);
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    int result = 1;
    for (int i = 0, j = len-1; i<j; i++, j--) {
        if (str[i] != str[j]) {
            result = 0;
            break;
        }
    }
    if (result == 1) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
}

void min_in_array() {
    int num[5] = {0};
    srand(time(NULL));
    for (int i = 0; i<5; i++) {
        num[i] = rand() % 100;
        printf("%d\n", num[i]);
    }
    int min = num[0];
    for (int i = 0; i<5; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    printf("min = %d\n", min);
}

int main() {
    palindrome();
    return 0;
}