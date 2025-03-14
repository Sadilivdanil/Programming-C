#include <stdio.h>
#define SIZE 3 // Количество комплексных чисел

int main() {
    double A[SIZE*2] = {1, 2, 2, 3, 3, 4}; // Массив A (RE0, IM0, RE1, IM1, ... )
    double B[SIZE*2] = {2, -1, 3, -2, 4, -3}; // Массив B

    double C[SIZE*2]; // Массив для суммы C
    double max_real_A = A[0]; // Максимальная реальная часть
    int count_negative_imag_B = 0; // Количество мнимых частей < 0
    double sum_C = 0.0; // Сумма для среднего

    // Сложение массивов A и B
    for (int i = 0; i < SIZE*2; i++) {
        C[i] = A[i] + B[i]; // Сложение
        sum_C += C[i]; // Суммируем для среднего
        if (i % 2 == 0 && A[i] > max_real_A) { // Поиск максимума
            max_real_A = A[i];
        }
        if (i % 2 == 1 && B[i] < 0) { // Подсчет отрицательных мнимых частей
            count_negative_imag_B++;
        }
    }

    double average_C = sum_C / (SIZE*2); // Среднее арифметическое

    // Вывод результатов
    printf("Максимальная реальная часть массива A: %.2f\n", max_real_A);
    printf("Количество мнимых частей < 0 в массиве B: %d\n", count_negative_imag_B);
    printf("Среднее арифметическое элементов массива C: %.2f\n", average_C);
