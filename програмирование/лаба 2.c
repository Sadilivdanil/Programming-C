  GNU nano 6.2                                     hello.c                                              #include <stdio.h>
#include <stdio.h>
void main(){
int d;
int a ;
printf("type years:");

scanf("%d",&a);
if (a%400==0){
        printf("YES");
} else if((a%100==0))
{
printf("NO");
}
else if(a%4==0){printf("YS");}
else{printf("YES");}
}
 



 GNU nano 6.2                                                               hello.c *                                                                      #include <stdio.h>
void main(){
float a;
char d;
printf("Input Temperature:");
scanf("%f %c",&a,&d);
if (d=='f'||d=='F'){
a=(a-32)*5/9;
printf("Output Temperature:%fC\n",a);
}else if (d=='c'||d=='c'){
a=(a*9/5)+32;
printf("Output Temperature:%fF\n",a);
}else printf("Output Erorr\n");
}
