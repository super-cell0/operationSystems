#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/_types/_null.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.14

int fib(int n) {
    if (n == 1 || n == 2) {
        return n-1;
    }
    int result = fib(n-1) + fib(n-2);
    return result;
}

int narcissus(int n) {
    int first = pow(10, n-1);
    int end = pow(10, n);
    for (int i = first; i<end; i++) {
        int num = i;
        int sum = 0;
        do {
            int d = num % 10;
            sum = sum+pow(d, n);
            num = num/10;
        }while (num > 0);
        if (sum == i) {
            printf("%d\n", i);
        }
    }
    return 0;
}

void log_func() {
    int x;
    int result = 0;
    x = 128;
    int t = x;
    while (x > 1) {
        x = x / 2;
        printf("%d ", x);
        result++;
    }
    printf("log2 of %d is %d", t, result);
}

int guess_number() {
    srand(time(NULL));
    int reward = rand()%100;
    printf("%d\n", reward);
    int number_try = 7;
    bool flag = false;
    while (number_try > 0 && !flag) {
        printf("input your guess number:\n");
        int guess;
        scanf("%d", &guess);
        if (guess == reward) {
            printf("win\n");
            flag = true;
        } else if (guess > reward) {
            printf("guess > reward try again\n");
        } else {
            printf("guess < reward try again\n");
        }
        number_try = number_try - 1;
    }
    if (!flag) {
        printf("lose");
    }
    return 0;
}

void piecewise() {
    int x;
    scanf("%d", &x);
    int result;
    if (x < 0) {
        result = -1;
    } else if (x == 0) {
        result = 0;
    } else {
        result = (2 * x);
    }
    printf("%d\n", result);
}

void digit() {
    int digit;
    printf("请输入一串数字：\n");
    scanf("%d", &digit);
    //digit/10->drop
    //digit%10->get
    int count = 0;
    if (digit == 0) {
        count = 1;
    } else {
        while (digit > 0) {
            digit = digit / 10;
            count++;
        }
    }
    printf("num: %d 位数\n", count);
}

void multiplication_table() {
    const int N = 9;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            printf("%d*%d=%-4d ", j, i, i *  j);
        }
        printf("\n");
    }
}

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

void leap_year(int year) {
    if ((year % 4==0 && year % 100 != 0) || year % 400 == 0) {
        printf("leap year\n");
    } else {
        printf("not a leap year\n");
    }
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
    printf("value= %d, index= %d\n", k, minIndex);
}
