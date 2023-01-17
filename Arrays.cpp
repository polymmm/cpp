#include <iostream>
#include <math.h>

typedef double TMatrix[10][10];
typedef double TVector[10];
const int N = 10;
void FillMatrix(TMatrix A);
void PrintMatrix(TMatrix A);
void GetVector(TVector V, TMatrix A);
void PrintVector(TVector V);
double G(TVector V);

int main()
{
	double u;
	TMatrix A;
	TVector X;
	FillMatrix(A);
	PrintMatrix(A);
	GetVector(X, A);
	PrintVector(X);
	u = G(X);
	printf("G= %9.5f\n", u);
	system("pause");
	return 0;
}

void FillMatrix(TMatrix A)
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = sin(0.5 * j - 0.2 * i);
}

void PrintMatrix(TMatrix A)
{
	int i, j, m[10];
	double p[10];
	printf("Matrix\n");
	for (i = 0; i < N; i++)
		p[i] = i;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%7.2f ", A[i][j]);
		printf("\n");
	}
	for (i = 0; i < N; i++)
	{
		p[i] = fabs(A[i][0]);
		for (j = 1; j < N; j++)
		{
			if (fabs(A[i][j]) > p[i])
				p[i] = fabs(A[i][j]);
			m[i] = i;
		}
	}
	printf("\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				std::swap(p[j], p[j + 1]);
				std::swap(m[j], m[j + 1]);
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			A[i][j] = A[m[i]][j];
			printf("%7.2f ", A[i][j]);
		}
		printf("\n");
	}
}

void GetVector(TVector V, TMatrix A)
{
	int i;
	for (i = 0; i < N; i++)
		V[i] = A[i][N - 1 - i];
}

void PrintVector(TVector V)
{
	int i;
	printf("Vector\n");
	for (i = 0; i < N; i++)
		printf("%5.2f ", V[i]);
	printf("\n");
}

double G(TVector V)
{
	int i;
	double s;
	s = 0;
	for (i = 0; i < N - 1; i++)
		s = s + 1.0 / (1.0 + fabs(V[i]));
	return s;
}
