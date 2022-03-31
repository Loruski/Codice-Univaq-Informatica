#include <stdio.h>
int a, b = 10, c, d;
int main(void)
{
    scanf("%d%d", &a, &d);
    c = 5;
    {
        int t1;
        t1 = a +7;
        int t2;
        t2 = 13 -d;
        a = t1/t2;
        t1 = a + 2;
        t2 = c %3 ;
        printf("%d %d", t1, t2);
        t1 = b * 4;
        c =d;
        t2 = d - 4;
        t2 -= a;
        t1 -= c;
        b = t1 * t2;
        d = -c;
    }
    printf(" %d %d %d %d\n", a, b, c, d);
    return 0;
}