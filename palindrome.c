#include <stdbool.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

#define MAX 21
#define LENGTH_1 10

int num_fib[LENGTH_1] = {1,1,2,3,5,8,13,21,34,55};
void binary(int num) {
    int left = 0;
    int right = LENGTH_1 - 1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (num > num_fib[mid]) {
            left = mid + 1;
        } else if (num < num_fib[mid]) {
            right = mid - 1;
        } else {
            result = mid;
            break;
        }
    }
    if (result == -1) {
        printf("not found");
    } else {
        printf("%d ", result);
    }
}

void prime(int m) {
    for (int i = 2; i<m; i++) {
        bool flag = true;
        for (int j = 2; j<i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d ", i);
        }
    }
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
    
    return 0;
}

void sift_down_demo(int nums[], int count, int i) {
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int m = i;
        if (l < count && nums[l] > nums[m]) {
            m = l;
        }
        if (r<count && nums[i] > nums[m]) {
            m = r;
        }
        if (m == i) {
            break;
        }
        int t = nums[i];
        nums[i] = nums[m];
        nums[m] = t;
        i = m;
    }
}