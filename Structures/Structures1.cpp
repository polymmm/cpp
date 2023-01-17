#include <iostream>
const int N = 6;
int imin, jmin;

struct TPoint
{
	double x, y;
};

struct TPoint PS[N] = {{0, 0}, {1, 1}, {2, 1}, {3, 1}, {2, 2}, {-1, 0}};
void MinDist();

int main()
{
	MinDist();
	return 0;
}

void MinDist()
{
	int B = N;
	int i, j, k;
	int a = 0, b = 0, min;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			if (PS[i].x == PS[j].x)
			{
				a = 0;
				b = 0;
				for (k = 0; k < N; k++)
				{
					if (PS[k].x < PS[j].x)
						a++;
					else if (PS[k].x != PS[j].x)
						b++;
				}
				if (abs(a - b) < B)
				{
					printf("(%.0F,%.0F) (%.0F,%.0F)\n", PS[i].x, PS[i].y, PS[j].x, PS[j].y);
					B = abs(a - b);
				}
			}
			else if (PS[i].y == PS[j].y)
			{
				a = 0;
				b = 0;
				for (k = 0; k < N; k++)
				{
					if (PS[k].y < PS[j].y)
						a++;
					else if (PS[k].y != PS[j].y)
						b++;
				}
				if (abs(a - b) < B)
				{
					printf("(%.0F,%.0F) (%.0F,%.0F)\n", PS[i].x, PS[i].y, PS[j].x, PS[j].y);
					B = abs(a - b);
				}
			}
			else if (((PS[i].x > PS[j].x) && (PS[i].y > PS[j].y)) || ((PS[i].x < PS[j].x) && (PS[i].y < PS[j].y)))
			{
				a = 0;
				b = 0;
				for (k = 0; k < N; k++)
				{
					if (((PS[k].x - PS[i].x) / (PS[j].x - PS[i].x)) != ((PS[k].y - PS[i].y) / (PS[j].y - PS[i].y)))
					{
						if (((PS[k].x - PS[i].x) / (PS[j].x - PS[i].x)) > ((PS[k].y - PS[i].y) / (PS[j].y - PS[i].y)))
							a++;
						else b++;
					}
				}
				if (abs(a - b) < B)
				{
					printf("(%.0F,%.0F) (%.0F,%.0F)\n", PS[i].x, PS[i].y, PS[j].x, PS[j].y);
					B = abs(a - b);
				}
			}
			else
			{
				a = 0;
				b = 0;
				for (k = 0; k < N; k++)
				{
					if (((PS[k].x - PS[i].x) / (PS[j].x - PS[i].x)) != ((PS[k].y - PS[i].y) / (PS[j].y - PS[i].y)))
					{
						if (((PS[k].x - PS[i].x) / (PS[j].x - PS[i].x)) > ((PS[k].y - PS[i].y) / (PS[j].y - PS[i].y)))
							a++;
						else b++;
					}
				}
				if (abs(a - b) < B)
				{
					printf("(%.0F,%.0F) (%.0F,%.0F)\n", PS[i].x, PS[i].y, PS[j].x, PS[j].y);
					B = abs(a - b);
				}
			}
		}
}
