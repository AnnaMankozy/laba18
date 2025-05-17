#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3
#define M 5

void vvod(float x[], int n, char q);
float sum(float a[], int n);
float product(float a[], int n);
float sum_fx(float a[], int n, double f(double));
float weighted_sum(float a[], int n, double f(double));

int main() {
    system("chcp 65001");
    float x[N], y[M];
    float sx, px, sy, py;
    float A, B, C, D, E, F, gamma;

    vvod(x, N, 'x');
    vvod(y, M, 'y');

    sx = sum(x, N);
    px = product(x, N);
    sy = sum(y, M);
    py = product(y, M);

    A = sx * sum_fx(x, N, sin);
    B = px * sum_fx(x, N, cos);
    C = (sx + px) * sum_fx(x, N, tan);

    D = sy * sum_fx(y, M, tan);
    E = py * sum_fx(y, M, exp);
    F = (sy + py) * sum_fx(y, M, cos);

    float denominator = D + E * sin(F);
    if (denominator != 0) {
        gamma = (A + B * cos(C)) / denominator;
        printf("Результат γ = %f\n", gamma);
    } else {
        printf("ПОМИЛКА! Ділити на нуль не можна\n");
    }

    return 0;
}

void vvod(float x[], int n, char q) {
    for (int i = 0; i < n; i+=1) {
        printf("Ввести %c[%d]: ", q, i + 1);
        scanf("%f", &x[i]);
    }
}

float sum(float a[], int n) {
    float s = 0;
    for (int i = 0; i < n; i+=1){
        s += a[i];
    }
    return s;
}

float product(float a[], int n) {
    float p = 1;
    for (int i = 0; i < n; i+=1){
        p *= a[i];
    }
    return p;
}

float sum_fx(float a[], int n, double f(double)) {
    float s = 0;
    for (int i = 0; i < n; i+=1){
        s += a[i] * f(a[i]);
    }
    return s;
    return 0;
} 