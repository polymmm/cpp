#include <string.h>
#include <iostream>
#include <conio.h>
const int NS = 5, NC = 4, NSt = 15;

struct TStud
{
	unsigned SNum;
	char SName[15];
	char SGroup[4];
};

struct TCour
{
	unsigned CNum;
	char Course[20];
	unsigned Size;
};

struct TStat
{
	unsigned SNum;
	unsigned CNum;
	unsigned Score;
};

typedef TStud TStudTable[NS];
typedef TCour TCourTable[NC];
typedef TStat TStatTable[NSt];

void PrintStud(TStudTable Stud);
void PrintCour(TCourTable Cour);
void PrintStat(TStatTable Stat);
void Itog(TStudTable Stud, TCourTable Cour, TStatTable Stat);

int main()
{
	TStudTable StudTable = {
		{1, "Smith", "101"}, {2, "Brosnan", "102"}, {3, "Jason", "107"}, {4, "Hackman", "103"}, {5, "Nikolay", "109"}
	};
	TCourTable CourTable = {{1, "Maths", 36}, {2, "Physics", 58}, {3, "English", 38}, {4, "Spanish", 58}};
	TStatTable StatTable = {
		{1, 1, 5}, {1, 2, 4}, {1, 3, 3}, {1, 4, 2}, {2, 1, 5}, {2, 2, 4}, {2, 3, 3}, {3, 1, 2}, {3, 2, 5}, {3, 4, 4},
		{4, 1, 3}, {4, 2, 2}, {5, 1, 5}, {5, 2, 4}, {5, 4, 3}
	};

	PrintStud(StudTable);
	PrintCour(CourTable);
	PrintStat(StatTable);

	Itog(StudTable, CourTable, StatTable);
}

void Itog(TStudTable Stud, TCourTable Cour, TStatTable Stat)
{
	int a = 0, b = 0, c = 0, k = 0;
	double m = 0, max = 0, max1 = 0, max2 = 0;
	for (int d = 0; d < 2; d++)
		for (int i = 0; i < NC; i++)
		{
			k = 0;
			m = 0;
			for (int j = 0; j < NSt; j++)
				if (Cour[i].CNum == Stat[j].CNum)
				{
					m += Stat[j].Score;
					k++;
				}
			m = m / k;
			if (m > max)
			{
				max = m;
				a = i;
			}
			if ((m < max) && (m > max1))
			{
				max1 = m;
				b = i;
			}
			if ((m < max1) && (m > max2))
			{
				max2 = m;
				c = i;
			}
		}
	std::cout << Cour[a].Course << std::endl;
	for (int j = 0; j < NSt; j++)
		if (Stat[j].CNum == Cour[a].CNum)
			if ((Stat[j].Score == 5) || (Stat[j].Score == 4))
				std::cout << Stud[Stat[j].SNum - 1].SName << std::endl;
	std::cout << std::endl << Cour[b].Course << std::endl;
	for (int j = 0; j < NSt; j++)
		if (Stat[j].CNum == Cour[b].CNum)
			if ((Stat[j].Score == 5) || (Stat[j].Score == 4))
				std::cout << Stud[Stat[j].SNum - 1].SName << std::endl;
	std::cout << std::endl << Cour[c].Course << std::endl;
	for (int j = 0; j < NSt; j++)
		if (Stat[j].CNum == Cour[c].CNum)
			if ((Stat[j].Score == 5) || (Stat[j].Score == 4))
				std::cout << Stud[Stat[j].SNum - 1].SName << std::endl;
}

void PrintStud(TStudTable Stud)
{
	int i;
	std::cout << "            Students             " << std::endl;
	std::cout << "*********************************" << std::endl;
	std::cout << "* SNum *     SName     * SGroup *" << std::endl;
	std::cout << "*********************************" << std::endl;
	for (i = 0; i < NS; i++)
	{
		std::cout << "*   " << Stud[i].SNum << "  * ";
		std::cout.width(13);
		std::cout << Stud[i].SName << " *   " << Stud[i].SGroup << "  *" << std::endl;
	}
	std::cout << "*********************************" << std::endl << std::endl;
}

void PrintCour(TCourTable Cour)
{
	int i;
	std::cout << "            Courses            " << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << "* CNum *     Course    * Size *" << std::endl;
	std::cout << "*******************************" << std::endl;
	for (i = 0; i < NC; i++)
	{
		std::cout << "*   " << Cour[i].CNum << "  * ";
		std::cout.width(13);
		std::cout << Cour[i].Course << " *  " << Cour[i].Size << "  *" << std::endl;
	}
	std::cout << "*******************************" << std::endl << std::endl;
}

void PrintStat(TStatTable Stat)
{
	int i;
	std::cout << "      Statement       " << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "* SNum * CNum * ENum *" << std::endl;
	std::cout << "**********************" << std::endl;
	for (i = 0; i < NSt; i++)
		std::cout << "*   " << Stat[i].SNum << "  *   " << Stat[i].CNum << "  *   " << Stat[i].Score << "  *" <<
			std::endl;
	std::cout << "**********************" << std::endl;
}
