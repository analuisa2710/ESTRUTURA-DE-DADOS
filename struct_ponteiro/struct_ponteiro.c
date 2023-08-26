#include <stdio.h>
#include <stdlib.h>

typedef struct P{
    int x;
    int y;
    
}P;


int main (int argc, char*argv[]){

    int a = 3;
    int b = a;
    int* p = &a;

    //printf("a %d\n", a);
    //printf("a %d\n", *p);
    //printf("p = %p\n", p);
   // printf("&a = %p\n", &a);

    int* p1;

    p1 = malloc (sizeof(int)*3);
    //printf ("p1 = %p\n", p1);
    //printf ("*p1 = %d\n", p1);
    *p1 = 2;
    //printf ("p1 = %d\n", p1);

    p1++;
    *p1 =5;
    //printf ("p1 = %p\n", p1);
   // printf ("*p1 = %d\n", p1);

    p1[1] = 7;
    //printf ("p1 = %p\n", &p1[1]);
   // printf ("*p1 = %d\n", p1[1]);

   P ponto;
   ponto.x = 1;
   ponto.y = 2;
   printf ("(%d, %d)", ponto.x, ponto.y);



     return 0;


}
