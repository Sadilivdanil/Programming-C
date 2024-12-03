#include <stdio.h>
int main() {
    unsigned int a;
    int k;
    printf("Введите целое число a: ");
    scanf("%u", &a);
    printf("Введите количество позиций для сдвига k: ");
    scanf("%d", &k);
    a =  (a >> (8 - k))|(a << k);

    printf("Результат циклического сдвига: %u\n", a);

}
