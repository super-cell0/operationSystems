#include <stdio.h>
#include <stdbool.h>

// 冒泡排序
void bubble_sort(int nums[], int count);
// 选择排序
void select_sort(int nums[], int count);
// 插入排序
void insert_sort(int nums[], int count);

int main() {
    int nums[11] = { 16, 34, 7, 5, 1, 2, 4, 4, 6, 12,9};
    int count = sizeof(nums) / sizeof(nums[0]);

    select_sort(nums, count);
    for (int i = 0; i < count; i++) {
      printf("%d ", nums[i]);
    }

  return 0;
}

void insert_sort(int nums[], int count) {
  for (int i = 1; i < count; i++) {
    int base = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > base) {
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = base;
  }
}

void select_sort(int nums[], int count) {
  for (int i = 0; i < count - 1; i++) {
    int min = i;
    for (int j = i + 1; j < count; j++) {
      if (nums[j] < nums[min]) {
        min = j;
      }
    }
    if (min != i) {
      int t = nums[i];
      nums[i] = nums[min];
      nums[min] = t;
    }
  }
}

void bubble_sort(int nums[], int count) {
  for(int i = count - 1; i > 0; i--) {
    bool flag = false;
    for (int j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        int t = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = t; 
        flag = true;
        for (int k = 0; k < count; k++) {  
          if (k == j) {  
            printf("\033[47;31m%d\033[0m ", nums[k]);
          } else if (k == j + 1) {  
            printf("\033[47;34m%d\033[0m ", nums[k]); 
          } else {  
            printf("%d ", nums[k]);  
          }  
        }  
        printf("\n");
      }
    }
    if (!flag) {
      break;
    }
  }
}