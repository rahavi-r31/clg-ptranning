#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define EmptyTOS -1
#define MinStackSize 5

#ifndef _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty (Stack S);
int IsFull (Stack S);
Stack CreateStack (int MaxElements);
void DisposeStack (Stack S);
void MakeEmpty (Stack S);
void Push (int X, Stack S);
int Top (Stack S);
void Pop (Stack S);
int TopAndPop (Stack S);

#endif /*_Stack_h*/

struct StackRecord
{
  int Capacity;
  int TopOfStack;
  int *Array;
};

Stack
CreateStack (int MaxElements)
{
  Stack S;
  if (MaxElements < MinStackSize)
    perror ("Stack size is too small");
  S = malloc (sizeof (struct StackRecord));
  if (S == NULL)
    perror ("Out of space");
  S->Array = malloc (sizeof (int) * MaxElements);
  if (S->Array == NULL)
    perror ("out of space");
  S->Capacity = MaxElements;
  MakeEmpty (S);
  return S;
}


void
DisposeStack (Stack S)
{
  if (S != NULL)
    {
      free (S->Array);
      free (S);
    }
}


int
IsEmpty (Stack S)
{
  return S->TopOfStack == EmptyTOS;
}


void
MakeEmpty (Stack S)
{
  S->TopOfStack = EmptyTOS;
}

int
IsFull (Stack S)
{
  return S->TopOfStack == S->Capacity - 1;
}


void
Push (int X, Stack S)
{
  if (IsFull (S))
    perror ("full stack");
  else
    S->Array[++S->TopOfStack] = X;
}


int
Top (Stack S)
{
  if (!IsEmpty (S))
    return S->Array[S->TopOfStack];
  perror ("empty stack");
  return 0;
}


void
Pop (Stack S)
{
  if (IsEmpty (S))
    perror ("empty stack");
  else
    S->TopOfStack--;
}


int
TopAndPop (Stack S)
{
  if (!IsEmpty (S))
    return S->Array[S->TopOfStack--];
  perror ("empty stack");
  return 0;
}



int
main ()
{
  Stack stack = CreateStack (5);	// Create a stack with a capacity of 5

  Push (10, stack);
  Push (20, stack);
  Push (30, stack);
  Push (40, stack);
  Push (50, stack);

  printf ("Top element: %d\n", Top (stack));

  while (!IsEmpty (stack))
    {
      int poppedElement = TopAndPop (stack);
      printf ("Popped element: %d\n", poppedElement);
    }

  DisposeStack (stack);
  return 0;
}
