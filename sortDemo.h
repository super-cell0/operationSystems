//
// Created by mac on 2024/5/20.
//

#ifndef OPERATINGSYSTEMS_SORTDEMO_H
#define OPERATINGSYSTEMS_SORTDEMO_H

// 打印数组元素
void printf_array(int array[], int count);

//交换两个值
void swap(int nums[], int a, int b);

// 选择排序
void select_sort(int nums[], int count);

// 冒泡排序
void bubble_sort(int nums[], int const);

// 插入排序
void insert_sort(int nums[], int count);

//快速排序-哨兵分化
int partition(int nums[], int start, int end);
//快速排序
void quick_sort(int nums[], int left, int right);


#endif //OPERATINGSYSTEMS_SORTDEMO_H
