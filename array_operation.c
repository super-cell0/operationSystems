#include <stdio.h>

//给定一个index在数组中插入一个元素
void insert_on(int on_array[], int *array_count, int insert_number, int index) {
    //检查插入位置
    if (index < 0 || index > *array_count) {
        printf("插入索引无效!");
        return;
    }
    for (int i = *array_count; i > index; i--) {
        on_array[i] = on_array[i - 1];
    }
    on_array[index] = insert_number;
    //更新数组大小
    (*array_count)++;
}

int main(int argc, char *argv[]) {
    int on_array[5] = { 100, 200, 300, 400, 500};
    int array_count = sizeof(on_array) / sizeof(on_array[0]);

    printf("初始数组:\n");
    for (int i = 0; i < array_count; i++) {
        printf("%d, ", on_array[i]);
    }
    printf("\n");
    
    insert_on(on_array, &array_count, 888, 5);

    printf("插入后的数组:\n");
    for (int i = 0; i < array_count; i++) {
        printf("%d, ", on_array[i]);
    }
    printf("\n");

    return 0;
}