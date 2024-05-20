//
// Created by mac on 2024/5/18.
//

#ifndef OPERATINGSYSTEMS_MAINHEADER_H
#define OPERATINGSYSTEMS_MAINHEADER_H

// 随机取出数组的一个元素
int random_element(int *nums, int count);

// 如果想在数组中间插入一个元素则需要将该元素之后的所有元素都向后移动一位之后再把元素赋值给该索引
void insert(int nums[], int *count, int number, int index);

// 若想删除索引处的元素，则需要把索引之后的元素都向前移动一位
void remove_element(int *nums, int *count, int index);

// 查找元素
// int *num
// 这种方式将数组的第一个元素的地址作为参数传递给函数
// 函数内部使用指针来访问数组的元素
int find(int *num, int count, int target);

// 找数组中的最小值
void minValue(int nums[], int count);

#endif //OPERATINGSYSTEMS_MAINHEADER_H
