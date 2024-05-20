#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PI 3.14

void flip2() {
    int a = 1234;
    int reversed = 0;
    while (a != 0) {
        int digit = a % 10;
        reversed = reversed * 10 + digit;
        a /= 10;
    }
    printf("%d\n", reversed);
}

void flip1() {
    // ||  && 
    // 按位非运算符 ~
    // 位异或运算符 ^ 相同为 0 不相同为 1
    int a = 5; // 0101
    int b = 6; // 0110
    a = a^b;
    b = a^b;
    a = a^b;
    printf("a = %d, b = %d\n", a, b);
}

void flip() {
    int a = 5;
    int b = 6;
    a = a + b; // a = 11
    b = a - b; // b = 5
    a = a - b;
    printf("a = %d, b = %d\n", a, b);

    // 多位运算的时候可能出错
    int c = 7;
    int d = 8;
    c = c * 10 + d;
    d = c / 10;
    c = c % 10;
    printf("c = %d, d = %d\n", c, d);
}

int circle() {
    double r = 0.0; // 半径
    printf("请输入一个半径: ");
    scanf("%lf", &r);
    printf("r = %.2f\n", r);
    double circu = 2 * PI * r;
    double area = PI * pow(r, 2);

    double surface = 4 * PI * pow(r, 2);
    double volume = (4 / 3.0) * PI * pow(r, 3);

    printf("圆的周长: %.2f\n", circu);
    printf("圆的面积: %.2f\n", area);
    printf("圆的周长: %.2f\n", circu);
    printf("圆的面积: %.2f\n", circu);

    return 0;
}

int leap_year(int year) {
    if (year % 4==0 && year % 100 != 0 || year % 400 == 0) {
        printf("leap year\n");
    } else {
        printf("not a leap year\n");
    }
    return 0;
}

int month(int month) {
        switch (month) {  
        case 1:  
            printf("January\n");  
            break;  
        case 2:  
            printf("February\n");  
            break;  
        case 3:  
            printf("March\n");  
            break;  
        case 4:  
            printf("April\n");  
            break;  
        case 5:  
            printf("May\n");  
            break;  
        case 6:  
            printf("June\n");  
            break;  
        case 7:  
            printf("July\n");  
            break;  
        case 8:  
            printf("August\n");  
            break;  
        case 9:  
            printf("September\n");  
            break;  
        case 10:  
            printf("October\n");  
            break;  
        case 11:  
            printf("November\n");  
            break;  
        case 12:  
            printf("December\n");  
            break;  
        default:    
            printf("未知的月份！\n");  
            break;  
    } 
    return 0;
}

int score(int score) {
    switch (score / 10) {
        case 9:
        case 10:
            printf("level = A");
            break;
        case 8:
            printf("level = B");
            break;
        case 7:
            printf("level = C");
            break;
        case 6:
            printf("level = D");
        default:
            printf("level = F");
            break;
    }
    return 0;
}

int loop_demo() {
    int result = 0;
    for (int i=0; i<=5; i++) {
        sleep(1);
        result = result + i;
        printf("%d\n", result);
    }
    return 0;
}

int loop_02(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<n-i; j++) {
            printf(" ");
        }
        for (int j=0; j<2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// 找数组中的最小值
void minValue(int nums[], int count) {
    int k = nums[0];
    int minIndex;
    for (int i = 0; i < count; i++) {
        if (nums[i] < k) {
            k = nums[i];
            minIndex = i;
        }
    }
    printf("min = %d, index = %d\n", k, minIndex);
}
