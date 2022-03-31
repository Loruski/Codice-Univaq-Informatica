#include <stdio.h>

int a, b = 10, c, d;
int main( void ) 
{
    c = b -5;
    scanf( "%d", &d );
    b *= 3;
    a = ( d -20 ) / c -2;
    c = ( b -13 ) -( d % 4 );
    printf( "%d %d %d %d\n", a, b, c, d );
    return 0; 
    }
