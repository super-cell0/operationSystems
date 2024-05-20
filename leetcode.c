#include <stdio.h>
#include "leetcode.h"

void singleNumber(int nums[], int count) {
    for (int i = 0; i < count; i++) {
        int current = 0;
        for (int j = 0; j < count; j++) {
            if (nums[i] == nums[j]) {
                current++;
            }
        }
        if (current == 1) {
            printf("%d\n", nums[i]);
        }
    }
}