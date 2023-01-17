#include <stdlib.h>
#include <iostream>

struct TItem
{
	int a;
};

struct TNode
{
	TItem Info;
	TNode* Next;
};

typedef TNode* PNode;
void PrintList(PNode P);
void InsertToHead(TItem AItem, PNode& Head);
void InsertAndSort(TItem Item, PNode& Head);
void DeleteList(PNode& Head);
void WriteList(PNode P, FILE* f);

int main()
{
	PNode Head = NULL;
	FILE* f;
	FILE* t;
	TItem P;
	if ((t = fopen("input.bin", "rb")) == NULL)
	{
		std::cout << "File not open";
		exit(1);
	}
	if ((f = fopen("output.txt", "w")) == NULL)
	{
		std::cout << "File not open";
		exit(1);
	}
	PrintList(Head);
	while (fread(&P, sizeof(TItem), 1, t))
		InsertAndSort(P, Head);
	PrintList(Head);
	WriteList(Head, f);
	DeleteList(Head);
	fclose(f);
	fclose(t);
	return 7;
}

void PrintList(PNode P)
{
	if (P == NULL)
		std::cout << "List empty" << std::endl;
	else
	{
		while (P != NULL)
		{
			std::cout << ' ' << P->Info.a;
			P = P->Next;
		}
		std::cout << std::endl;
	}
}

void InsertAndSort(TItem Item, PNode& Head)
{
	PNode P, Q, R;
	if ((Head == NULL) || Head->Info.a > Item.a)
		InsertToHead(Item, Head);
	else
	{
		R = Head;
		P = Head->Next;
		while ((P != NULL) && (P->Info.a <= Item.a))
		{
			R = P;
			P = P->Next;
		};
		Q = (PNode)malloc(sizeof(TNode));
		Q->Info = Item;
		Q->Next = R->Next;
		R->Next = Q;
	}
}

void InsertToHead(TItem AItem, PNode& Head)
{
	PNode Q;
	Q = (PNode)malloc(sizeof(TNode));
	Q->Next = Head;
	Q->Info = AItem;
	Head = Q;
}

void DeleteList(PNode& Head)
{
	PNode P, Q;
	P = Head;
	while (P != NULL)
	{
		Q = P->Next;
		free(P);
		P = Q;
	}
	Head = P;
	PrintList(Head);
}

void WriteList(PNode P, FILE* f)
{
	while (P != NULL)
	{
		fprintf(f, "%i ", P->Info.a);
		P = P->Next;
	}
}
