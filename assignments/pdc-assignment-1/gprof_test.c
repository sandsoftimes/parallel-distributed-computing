#include <stdio.h>

void add(int a, int b) {
    int result = a + b;
    printf("Addition Result: %d\n", result);
}

void subtract(int a, int b) {
    int result = a - b;
    printf("Subtraction Result: %d\n", result);
}

void multiply(int a, int b) {
    int result = a * b;
    printf("Multiplication Result: %d\n", result);
}

void divide(int a, int b) {
    if (b != 0) {
        int result = a / b;
        printf("Division Result: %d\n", result);
    } else {
        printf("Cannot divide by zero!\n");
    }
}

int main() {
    int num1 = 10, num2 = 5;

    add(num1, num2);
    subtract(num1, num2);
    multiply(num1, num2);
    divide(num1, num2);

    return 0;
}
