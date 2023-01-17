#include <iostream>
#include <fstream>
const int N = 5;
int imin, jmin;
const double A = sqrt(3) / 2;

struct TPoint
{
	double x, y;
};

struct TPoint PS[N] = {{0, 0}, {0, 2}, {1, 1}, {4, 2}, {2, 4}};
struct TPoint PS1[6] = {{0.5, A}, {3, 2 + 2 * A}, {0, 0}, {1, 0}, {2, 2}, {4, 2}};
struct TPoint PS2[N] = {{6, 0}, {6, 2}, {7, 1}, {10, 2}, {8, 4}};

double Dist(TPoint a, TPoint b);
int Trngl(void);
double MaxDist(void);

int main()
{
	std::ofstream vihod("bad3.txt");

	double SMax;
	int Tqua;
	SMax = MaxDist();
	Tqua = Trngl();
	printf("I=%i J=%i S=%6.2f\n", imin, jmin, SMax);
	std::cout << "Trngls: " << Tqua << std::endl;
	system("pause");
	return 0;
}

double Dist(TPoint a, TPoint b)
{
	double temp;
	temp = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return temp;
}

double MaxDist(void)
{
	int i, j;
	double d, SMax;
	SMax = Dist(PS[0], PS2[0]);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			d = Dist(PS[i], PS2[j]);
			if (d > SMax)
			{
				SMax = d;
				imin = i;
				jmin = j;
			}
		}
	return SMax;
}

int Trngl(void)
{
	float r, r1, r2 = 0;
	int i, j, k, t = 0;
	int a = 1, b = 1, c = 1;
	for (i = 0; i < 6 - 2; i++)
		for (k = i + 1; k < 6 - 1; k++)
		{
			r = Dist(PS1[i], PS1[k]);
			for (j = k + 1; j < 6; j++)
			{
				r1 = Dist(PS1[i], PS1[j]);
				if (r == r1)
				{
					r = Dist(PS1[k], PS1[j]);
					if ((r == r1) && (r > r2))

						if (((Dist(PS1[a], PS1[i]) != 0) && (Dist(PS1[a], PS1[k]) != 0) && (Dist(PS1[a], PS1[j]) != 0))
							&& ((Dist(PS1[b], PS1[i]) != 0) && (Dist(PS1[b], PS1[k]) != 0) && (Dist(PS1[b], PS1[j]) !=
								0))
							&& ((Dist(PS1[c], PS1[i]) != 0) && (Dist(PS1[c], PS1[k]) != 0) && (Dist(PS1[c], PS1[j]) !=
								0)))
						{
							t++;
							r2 = r;
							a = i;
							b = k;
							c = j;
						}
				}
			}
		}
	return t;
}
