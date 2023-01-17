#include <stdlib.h>
#include <iostream>

int main()
{
	struct TItem
	{
		int a;
	};
	FILE* f;
	FILE* t;
	TItem i;
	if ((t = fopen("dat.txt", "r")) == NULL)
	{
		std::cout << "File not open";
		exit(1);
	}
	if ((f = fopen("input.bin", "wb")) == NULL)
	{
		std::cout << "File not open";
		exit(1);
	}
	while (fscanf(t, "%i", &i.a) > 0)
	{
		fwrite(&i, sizeof(i), 1, f);
	}
	fclose(t);
	fclose(f);
}
