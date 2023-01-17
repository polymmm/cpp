#include <iostream>
typedef std::string TItem;
std::string a("ptr1");
std::string b("ptr2");

struct TNode
{
	TItem Info;
	TNode* Left;
	TNode* Right;
};

typedef TNode* PNode;

PNode InitTree(void)
{
	return 0;
};

void SearchInsert(TItem Item, PNode& P)
{
	if (P == 0)
	{
		P = new TNode;
		P->Info = Item;
		P->Left = 0;
		P->Right = 0;
	}
	else if (Item <= P->Info)
		SearchInsert(Item, P->Left);
	else if (Item > P->Info)
		SearchInsert(Item, P->Right);
};
PNode Q;

void SearchTerm(PNode& R)
{
	if (R->Right != NULL)
		SearchTerm(R->Right);
	else
	{
		Q->Info = R->Info;
		Q = R;
		R = R->Left;
	}
};

void DeleteNode(TItem X, PNode& P)
{
	if (P != NULL)
		if (X < P->Info)
			DeleteNode(X, P->Left);
		else if (X > P->Info)
			DeleteNode(X, P->Right);
		else
		{
			Q = P;
			if (Q->Right == NULL)
				P = Q->Left;
			else if (Q->Left == NULL)
				P = Q->Right;
			else
				SearchTerm(Q->Left);
			delete Q;
		}
	else std::cout << "Not found " << X;
};

void DeleteTree(PNode& P)
{
	if (P != NULL)
	{
		if (P->Left != NULL)
			DeleteTree(P->Left);
		if (P->Right != NULL)
			DeleteTree(P->Right);
		delete P;
		P = NULL;
	};
};

void PrintTree(PNode t, int h)
{
	if (t != NULL)
	{
		PrintTree(t->Right, h + 2);
		for (int i = 1; i <= h; i++) printf(" ");
		std::cout << t->Info;
		PrintTree(t->Left, h + 2);
	};
};

int main()
{
	PNode root;
	root = InitTree();
	SearchInsert(a, root);
	SearchInsert(b, root);
	PrintTree(root, 0);
	DeleteTree(root);
}
