#include <stdio.h>
void main(){
int n,namber=1;
printf("n:");
scanf("%d",&n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        printf("%d ",namber);
                        namber++;

                }
                printf("\n");
        }
}
