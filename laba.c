#include <stdio.h>
#include <ctype.h>

void to_uppercase(char str[]) {
        int i = 0;
    while (str[i] != 0) {//Цикл будет выполняться до тех пор, пока текущий символ строки не будет нулевым символом ('\0'), что указывает на конец строки.
        str[i] = toupper((unsigned char)str[i]);
        i++;
    }
}

int main() {
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod               
    to_uppercase(str);
    printf("%s\n", str);
}
