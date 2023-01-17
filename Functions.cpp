#include <cmath>
#include <iostream>

void table(int b, int n, float (*f)(float));
float f6(float i);
float f24(float i);
float f16(float i);

int main()
{
	table(1, 25, f6);
	printf("\n");
	table(0, 25, f24);
	printf("\n");
	table(0, 25, f16);
	printf("\n");
	return (0);
}

void table(int b, int n, float (*f)(float))
{
	float min, max, mid, k = 0, e = 40;
	int i, n_min, n_max, n_mid;

	if (b == 1)
	{
		for (i = 1; i <= n; i++) k = k + f(i);
		mid = k / n;
		for (i = 1; i <= n; i++)
		{
			if (fabs(mid - f(i)) < e)
			{
				mid = f(i);
				n_mid = i;
			}
		}
		printf("mid = %12f n_mid= %i\n", mid, n_mid);
	}

	min = f(1);
	max = f(1);
	for (i = 1; i <= n + 1; i++)
	{
		if (f(i) <= min)
		{
			min = f(i);
			n_min = i;
		}
		if (f(i) >= max)
		{
			max = f(i);
			n_max = i;
		}
	}
	printf("min=%12 n_min=%i\n", min, n_min);
	printf("max=%12 n_max=%i\n", max, n_max);
	printf("\n");
}

float f6(float i)
{
	float a;
	a = 10 * sqrt(i) / (1 + 0.1 * i * sqrt(i));
	return a;
}

float f24(float i)
{
	float a;
	a = 8 * i / (1 + 0.05 * i * sqrt(i));
	return a;
}

float f16(float i)
{
	float a;
	a = 5 * sqrt(i) * exp(-0.03 * i);
	return a;
}
