/* LINLIST 

#include <stddef.h>
#include <stdlib.h>
#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode; 
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty( List L );
int IsEmpty( List L);
int IsLast (Position P, List L);
Position Find(int X, List L); 
void Delete( int X, List L ); 
Position FindPrevious ( int X, List L); 
void Insert( int X, List L, Position P ); 
void DeleteList( List L);
Position Header( List L); 
Position First( List L);
Position Advance( Position P); 
int Retrieve( Position P);

#endif /* _List_H */


/* Place in the implementation file */ 
struct Node
{
   int Element; 
   Position  Next;
};


/* Return true if L is empty */
int
IsEmpty( List L)
{
   return L->Next==NULL;
}


/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int
IsLast (Position P, List L ) 
{
return P->Next == NULL;
}


/* Return Position of X in L; NULL if not found */
Position
Find (int X, List L )
{
Position P;

P = L->Next;
while( P != NULL && P->Element != X ) 
   P = P->Next;
return P;
}


/* Delete first occurrence of X from a list */ 
/*Assume use of a header node*/
void 
Delete( int X, List L )
{
Position P, TmpCell;
P = FindPrevious ( X, L);
if(!IsLast( P, L)) /* Assumption of header use */
{                  /* X is found; delete it */
TmpCell = P->Next; 
P->Next = TmpCell->Next; /*Bypass deleted cell*/
free(TmpCell);
}
}


/*If X is not found, then next field of returned*/
/*position is NULL*/
/*Assume a header*/
Position
FindPrevious(int X,List L)
{
Position P;
P=L;
while (P->Next != NULL && P->Next->Element !=X)
   P=P->Next;
return P;
}


/*Insert (after legal position P)*/
/*Header implementation assumed*/
/*parameter L is unused in this implementation*/
void
Insert(int X, List L, Position P)
{
Position TempCell;
TempCell = malloc(sizeof(struct Node));
if(TempCell == NULL)
  FatalError("out of Space!!!");
TempCell->Element = X;
TempCell->Next = P->Next;
P->Next = TempCell;
}
