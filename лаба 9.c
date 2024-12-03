#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

void inputMatrix(int A[SIZE][SIZE]) {
    printf("Введите элементы матрицы %dx%d:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void fillMatrixRandom(int A[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 20; // Случайные числа от 0 до 19
        }
    }
}

void printMatrix(int A[SIZE][SIZE]) {
    printf("Матрица:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int calculateSumAndCheckZero(int A[SIZE][SIZE], int *has_zero) {
    int sum = 0;
    *has_zero = 0; // Обнуляем флаг
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (A[i][j] == 0) *has_zero = 1;
            sum += A[i][j];
        }
    }
    return sum;
}

void swapDiagonals(int A[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int temp = A[i][i];
        A[i][i] = A[i][SIZE - 1 - i];
        A[i][SIZE - 1 - i] = temp;
    }
}

int main() {
    int A[SIZE][SIZE];
    int has_zero = 0;
    int count = SIZE * SIZE;
    int choice;

    printf("1. Ввести матрицу вручную\n");
    printf("2. Заполнить матрицу случайными числами\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    if (choice == 1) {
        inputMatrix(A);
    } else {
        fillMatrixRandom(A);
        printMatrix(A);
    }

    // Подсчет суммы и проверка на нули
    int sum = calculateSumAndCheckZero(A, &has_zero);

    // Меняем местами главную и побочную диагонали
    swapDiagonals(A);

    // Вывод результатов
    printf("Среднее арифметическое: %.2f\n", (float)sum / count);
    printf("Нули в матрице: %s\n", has_zero ? "Да" : "Нет");

    return 0;
}
