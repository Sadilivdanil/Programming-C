#include <stdio.h>
#define MAX_N 3 // максимальное значение N
double d2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}//считает 2x2

double d3x3(double a11, double a12, double a13,
            double a21, double a22, double a23,
            double a31, double a32, double a33) {
    return a11 * d2x2(a22, a23, a32, a33) -
           a12 * d2x2(a21, a23, a31, a33) +
           a13 * d2x2(a21, a22, a31, a32);
}//считает 3x3


void solve2x2(double A[2][2], double B[2], double X[2]) {
    double detA = d2x2(A[0][0], A[0][1], A[1][0], A[1][1]);
    if (detA == 0) {
        printf("Система не имеет решений или имеет бесконечно много решений.\n");
        return;
    }

    double detA1 = d2x2(B[0], A[0][1], B[1], A[1][1]);
    double detA2 = d2x2(A[0][0], B[0], A[1][0], B[1]);

    X[0] = detA1 / detA;
    X[1] = detA2 / detA;
}
void solve3x3(double A[3][3],double B[3],double X[3]){
    double detA = d3x3(A[0][0], A[0][1], A[0][2],
                       A[1][0], A[1][1], A[1][2],
                       A[2][0], A[2][1], A[2][2]);
     if (detA == 0) {
        printf("Система не имеет решений или имеет бесконечно много решений.\n");
        return;
    }
    double A1[3][3] = {{B[0], A[0][1], A[0][2]},//создает матрици A1 A2 A3 для вычисления значений переме
                       {B[1], A[1][1], A[1][2]},
                       {B[2], A[2][1], A[2][2]}};
    double A2[3][3] = {{A[0][0], B[0], A[0][2]},
                       {A[1][0], B[1], A[1][2]},
                       {A[2][0], B[2], A[2][2]}};
    double A3[3][3] = {{A[0][0], A[0][1], B[0]},
                       {A[1][0], A[1][1], B[1]},
                       {A[2][0], A[2][1], B[2]}};

    X[0] = d3x3(A1[0][0], A1[0][1], A1[0][2],
                A1[1][0], A1[1][1], A1[1][2],
                A1[2][0], A1[2][1], A1[2][2]) / detA;
    X[1] = d3x3(A2[0][0], A2[0][1], A2[0][2],
                A2[1][0], A2[1][1], A2[1][2],
                A2[2][0], A2[2][1], A2[2][2]) / detA;
    X[2] = d3x3(A3[0][0], A3[0][1], A3[0][2],
                A3[1][0], A3[1][1], A3[1][2],
                A3[2][0], A3[2][1], A3[2][2]) / detA;
}

int main() {
    int N;
    printf("Введите размерность системы (2 или 3): ");
    scanf("%d", &N);

    if (N == 2) {
        double A[2][2], B[2], X[2];
        printf("Введите коэффициенты матрицы A (2x2):\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &A[i][j]);
            }
        }
        printf("Введите члены:\n");
        for (int i = 0; i < 2; i++) {
            scanf("%lf", &B[i]);
        }
        solve2x2(A, B, X);

        printf("Решение системы: x1 = %.2f, x2 = %.2f\n", X[0], X[1]);
    } else if (N == 3) {
        double A[3][3], B[3], X[3];
        printf("Введите коэффициенты матрицы A (3x3):\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf", &A[i][j]);
            }
        }
        printf("Введите члены:\n");
        for (int i = 0; i < 3; i++) {
            scanf("%lf", &B[i]);
        }

        solve3x3(A, B, X);

        printf("Решение системы: x1 = %.2f, x2 = %.2f, x3 = %.2f\n", X[0], >    
    } else {
        printf("Неверный размер системы.\n");
    }

    return 0;
}
