#include <iostream>
#include <string.h>

int main()
{
	int a[80];
	char s[82];
	char s1[2] = {' ', '\0'};
	int b = 0, b1 = 0, q, p = 1;
	int n = 0;
	int i = 0, j, k = 0;
	std::cout << "Enter the string (max 80 symbols)" << std::endl;
	gets_s(s);
	strcat_s(s, s1);

	while (i < strlen(s))
	{
		if (s[i] != 32)
			k++;
		else
		{
			a[n] = k;
			n++;
			k = 0;
		}
		i++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			q = a[j] / a[j - 1];
			if (a[i] * pow(q, p) == a[j])
			{
				b++;
				p++;
			}
			else
			{
				if (b > b1) b1 = b;
				b = 0;
				p = 1;
				break;
			}
		}
		if ((b > b1) && (n > 1)) b1 = b;
		b = 0;
	}
	b = 1;
	for (i = n - 1; i >= 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			q = a[j - 1] / a[j];
			if (a[i] * pow(q, p) == a[j])
			{
				b++;
				p++;
			}
			else
			{
				if (b > b1) b1 = b;
				b = 0;
				p = 1;
				break;
			}
		}
		if ((b > b1) && (n > 1)) b1 = b;
		b = 0;
	}
	std::cout << b1 + 1 << std::endl;
	return 0;
}
