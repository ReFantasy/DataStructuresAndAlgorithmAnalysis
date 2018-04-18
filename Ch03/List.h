#ifndef __LIST_H__
#define __LIST_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;
#define HADERELEMENT INT_MAX

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
bool Insert(ElementType X, List L, Position P);
bool Insert(ElementType X, List L);

List MakeEmpty(List L = List());
void DeleteList(List L);
Position First(List L);
ElementType Retrieve(Position P);

void PrintList(List L);

#endif
