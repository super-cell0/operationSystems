#include <stdio.h>

#define N 10

void reverse(int nums[], int count);
void reverse2(int nums[], int count);

int main() {

    int nums[N] = {34, 82, 49, 102, 7, 94, 23, 11, 50, 31};

    reverse2(nums, N);
    
    return 0;
}

void reverse(int nums[], int count) {
    for (int i = 0; i<count; i++) {
        printf("%d, ", nums[count-1-i]);
    }
}

void reverse2(int nums[], int count) {
    int t;
    for (int i = 0; i<count/2; i++) {
        t = nums[i];
        nums[i] = nums[count-1-i];
        nums[count-1-i] = t;
    }
    for (int i = 0; i<N; i++) {
        printf("%d, ", nums[i]);
    }
}