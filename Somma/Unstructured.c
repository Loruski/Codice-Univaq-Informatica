#include <stdio.h>
int main (void)
{
    int s1 = -325;
    int s2; 
    int s3=826;
    int t1;
    t1 = s1 + 22;
    int t2;
    t2 = s3 - 329;
    t1  = 2048 - t1;
    s2 = t1 + t2;
    t1 = s1 - 345;
    t2 = s1 + 9;
    s3 = s2 - t2;
    t1 -= s3;
    s1 -= t1;
    printf ("%d %d %d", s1, s2, s3);
    return 0;
}
