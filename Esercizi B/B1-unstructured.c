#include <stdio.h>
int a, b = 10, c, d;
int main( void ) 
{
    c = b -5;
    scanf( "%d", &d );
    b *= 3;
    {
        int t1;
        t1 = d -20;
        int t2;
        t2 = t1/c;
        a = t2-2;

        t1 = b- 13;
        t2 = d % 4;
        c = t1 - t2;
    }
    printf( "%d %d %d %d\n", a, b, c, d );
    return 0; 
    }
