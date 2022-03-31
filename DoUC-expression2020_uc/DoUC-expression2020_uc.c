#include <stdio.h>

int a = 4, b, c = -19;
float x, y = 3, z = 2.8f;

int f2020( float par ) {

	float h;
	
	z += 1;
	h = y + z;
	h /= 2;

	float t1, t2;
	t1 = 3.5f;
	t2 = par / 2;
	t1 = t1 - t2;
	t1 = t1 + z;
	y += t1;

    int t3;

	t3 = 2 + h;
	t1 = par * 2;
	t3 /= t1;

	return t3;
}
