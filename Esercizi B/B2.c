#include <stdio.h>
int a, b = 10, c, d;
int main( void ) {
    scanf( "%d%d", &a, &d );
    c = 5;
    a = ( a + 7 ) / ( 13 -d );
    printf( "%d %d", a + 2, c % 3);
    b = ( b * 4 ) -( c = d ) * ( d -4 + -a );
    d = -c;
    printf( " %d %d %d %d¥n", a, b, c , d );
    return 0; 
    }