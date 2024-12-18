#ifndef POINT_H
#define POINT_H

// Структура для точки в трехмерной системе
typedef struct {
    double x;
    double y;
    double z;
} Point;

// Прототип функции для вычисления расстояния между двумя точками
double distance(Point A, Point B);

#endif // POINT_H


#include <math.h>
#include "11.h"
//по теореме пифагора вычислияет растояние можду точками квадрат находит с помощью pow возводит в корень с помощью sqrt
double distance(Point A, Point B) {
    return sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2)+pow(B.z-A.z,2));
}



#include<stdio.h>
#include"11.h"
int main() {
    Point A,B;

    printf(" координаты точкиA: ");
    scanf("%lf %lf %lf", &A.x, &A.y, &A.z);

    printf("координаты точкиB: ");
    scanf("%lf %lf %lf", &B.x, &B.y, &B.z);


    double dist=distance(A, B);
    printf("Расстояние между точками A и B: %.2f\n", dist);

    return 0;
}
