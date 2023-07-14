/*Type declaration for linked list implementation of the stack ADT */
#indef _Stack_h
struct Node;
typedef struct Node *ptrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack( Void ):
void DisposeStack( Stack S);
void MakeEmpty( Stack S);
void Push( ElementType X,Stack S);
Elementtype Top( Stack S);
void Pop(Stack S);

#endif   /*_stack_h*/

/*place in implementation file*/
/*Stack implementation is a linked list with a header */
struct Node
{
ElementType Element;
PtrToNode Next;
};

/*Routinr to test whether a stack is empty - linked list implementation*/
int
IsEmpty(Stack S)
{
return S->Next == NULL:
}


/*Routine to create an empty stack - linked lis implementation*/

Stack
CreateStack(void)
{
Stack S;
S=malloc(sizeof(struct Node));
if (S==NULL)
	FatalError("Out of space");
MakeEmpty(S);
return S;
}

void
MakeEmpty(Stack S)
{
if (S == NULL)
	Error("Must use CreateStack first");
else
	while (!IsEMpty(S))
		Pop(S);
}

/*Routine to push onto a stack-linked list implementation*/

void 
Push(ElementType X, Stack S)
{
PtrToNode TmpCell;
TmpCell = malloc(sizeof(struct Node));
if(tmpCell == NULL)
	FatalError("Out of space");
else
{
	TmpCell->Element = X
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
}
}

/*Routine t return top element in a stack - Linked list implementation*/
ELementType
Top(Stack S)
{
if(!IsEmpty(S))
	return S->Next->Element;
Error("Empty Stack");
return 0;
}

/*Routine to pop from a stack-linked list implementation*/
void
Pop(Stack S)
{
PtrToNode FirstCell;
if(IsEmpty(S))
	Error("Empty");
else
{
	FirstCell =S->Next;
	S->Next =S->Next->Next;
	free(FirstCell);
}
}
