#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("%d\n%f\n%lf\n", a, b, c);
	return 0;
}
