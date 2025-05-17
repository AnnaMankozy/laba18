#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

double sum(double x, double y);
double sub(double x, double y);
double mult(double x, double y);
double divide(double x, double y);
double power(double x, double y);

int main() {
    system("chcp 65001");

    double a, b, results[5];
    int i;
    const char *operation_names[5] = {"додавання", "віднімання", "множення", "ділення","піднесення до степеня"};

    double (*operations[5])(double, double) = { sum, sub, mult, divide, power };

    printf("Введіть два числа (a і b):\n");
    scanf("%lf %lf", &a, &b);

    for (i = 0; i < 5; i+=1) {
        results[i] = operations[i](a, b);
        printf("Результат операції %s: %.4lf\n", operation_names[i], results[i]);
    }
    return 0;
}

double sum(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mult(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y != 0){
        return x / y;
    }
    else {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
}

double power(double x, double y) {
    return pow(x, y);
}