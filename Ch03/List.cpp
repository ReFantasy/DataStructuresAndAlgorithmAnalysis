#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

// Return true if P is the last position in list L
int IsLast(Position P, List L)
{
	Position pcur = L;
	while (pcur->Next)
		pcur = pcur->Next;
	return pcur == P;
}

// Return the first position of X in L;NULL if not found
Position Find(ElementType X, List L)
{
	Position pcur = L->Next;
	while (pcur && pcur->Element != X)
		pcur = pcur->Next;
	return pcur;
}

// Return the previous position of X in L; NULL if not fount
Position FindPrevious(ElementType X, List L)
{
	Position pcur = L;
	while (pcur->Next &&pcur->Next->Element != X)
		pcur = pcur->Next;
	return pcur->Next ? pcur : NULL;
}

// Remove the first X in L;
void Delete(ElementType X, List L)
{
	Position pre = FindPrevious(X, L);
	// X is found
	if (pre)
	{
		Position pX = pre->Next;
		pre->Next = pX->Next;
		free(pX);
	}
}

// Insert X in L after position of P; Return true if insert successful
bool Insert(ElementType X, List L, Position P)
{
	PtrToNode pNewNode = (PtrToNode)malloc(sizeof(struct Node));
	if (!pNewNode)return false;

	pNewNode->Element = X;
	pNewNode->Next = P->Next;
	P->Next = pNewNode;
	return true;
}

// Insert X after the last element in L
bool Insert(ElementType X, List L)
{
	Position pcur = L;
	while (pcur->Next)
		pcur = pcur->Next;
	return Insert(X, L, pcur);
}

// Make a empty list with a header
List MakeEmpty(List L)
{
	L = (PtrToNode)malloc(sizeof(struct Node));
	if (!L)return NULL;

	L->Element = HADERELEMENT;
	L->Next = NULL;
	return L;
}

// Delete all of list L
void DeleteList(List L)
{
	Position pcur = L;
	Position tmp = L;
	while (pcur)
	{
		tmp = pcur;
		pcur = pcur->Next;
		free(tmp);
	}
}

// Return the position of first element
Position First(List L)
{
	return L ? L->Next : NULL;
}

// Return element of the position P
ElementType Retrieve(Position P)
{
	return P->Element;
}

// Print List 
void PrintList(List L)
{
	Position pcur = L->Next;
	while (pcur)
	{
		printf("%d ", pcur->Element);
		pcur = pcur->Next;
	}
}
