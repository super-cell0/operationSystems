#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <time.h>

int randomAccess(int *nums, int count) {
    
    return 0;
}

void insert(int nums[], int *count, int number, int index) {
    if (index < 0 || index > *count) {
        printf("index无效");
        return;
    }
    for (int i = *count; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = number;
    (*count)++;
}


int main() {

    return 0;
}