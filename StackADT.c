/*Type declaration for linked list implementation of the stack ADT */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef _Stack_h
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty (Stack S);
Stack CreateStack (void);
void DisposeStack (Stack S);
void MakeEmpty (Stack S);
void Push (int X, Stack S);
int Top (Stack S);
void Pop (Stack S);

#endif	 /*_stack_h*/

/*place in implementation file*/
/*Stack implementation is a linked list with a header */
struct Node
{
  int Element;
  PtrToNode Next;
};

/*Routinr to test whether a stack is empty - linked list implementation*/
int
IsEmpty (Stack S)
{
  return S->Next == NULL;
}


/*Routine to create an empty stack - linked lis implementation*/

Stack
CreateStack (void)
{
  Stack S;
  S = malloc (sizeof (struct Node));
  if (S == NULL)
    perror ("Out of space");
  MakeEmpty (S);
  return S;
}

void
MakeEmpty (Stack S)
{
  if (S == NULL)
    perror ("Must use CreateStack first");
  else
    while (!IsEmpty (S))
      Pop (S);
}

/*Routine to push onto a stack-linked list implementation*/

void
Push (int X, Stack S)
{
  PtrToNode TmpCell;
  TmpCell = malloc (sizeof (struct Node));
  if (TmpCell == NULL)
    perror ("Out of space");
  else
    {
      TmpCell->Element = X;
      TmpCell->Next = S->Next;
      S->Next = TmpCell;
    }
}

/*Routine t return top element in a stack - Linked list implementation*/
int
Top (Stack S)
{
  if (!IsEmpty (S))
    return S->Next->Element;
  perror ("Empty Stack");
  return 0;
}

/*Routine to pop from a stack-linked list implementation*/
void
Pop (Stack S)
{
  PtrToNode FirstCell;
  if (IsEmpty (S))
    perror ("Empty");
  else
    {
      FirstCell = S->Next;
      S->Next = S->Next->Next;
      free (FirstCell);
    }
}

int
main ()
{
  Stack stack = CreateStack ();	// Create a new stack

  /* Push some elements onto the stack */
  Push (10, stack);
  Push (20, stack);
  Push (30, stack);

  /* Retrieve and print the top element */
  int topElement = Top (stack);
  printf ("Top element: %d\n", topElement);

  /* Pop elements from the stack until it becomes empty */
  while (!IsEmpty (stack))
    {
      int poppedElement = Top (stack);
      printf ("Popped element: %d\n", poppedElement);
      Pop (stack);
    }

  // Free the memory occupied by the stack

  return 0;
}

/*The provided code snippet consists of a type declaration for the linked list implementation of the stack abstract data type (ADT) and an accompanying struct definition.*/

/*The type declaration starts with an `#ifndef _Stack_h` directive, which is a conditional compilation statement that checks if the `_Stack_h` macro is not defined. This is typically used to prevent multiple inclusions of the same header file to avoid duplicate declarations.

Following that, the code declares a forward declaration of a struct named `Node` using `struct Node;`. This forward declaration is necessary because the struct definition includes a self-referential pointer to `struct Node`, which requires a prior declaration.

The code then provides three type definitions using `typedef`:

1. `typedef struct Node *ptrToNode;`: This line creates a new type `ptrToNode` as a pointer to a struct of type `Node`. It allows for more convenient usage of pointers to `Node` structs throughout the code.

2. `typedef PtrToNode Stack;`: This line creates a new type `Stack` as an alias for `PtrToNode`. This means that `Stack` is equivalent to `struct Node *`, representing a pointer to a `Node` struct. This typedef is used to represent the stack data structure in the code.

3. `typedef struct Node *PtrToNode;`: This line creates a new type `PtrToNode` as a pointer to a struct of type `Node`. It provides an alternative name for pointers to `Node` structs.

After the type declarations, the code includes function prototypes for the stack operations, such as `IsEmpty`, `CreateStack`, `DisposeStack`, `MakeEmpty`, `Push`, `Top`, and `Pop`. These function prototypes describe the signatures of the functions without providing their implementations.

Finally, the code ends with the `#endif /*_stack_h*/` directive, which closes the conditional compilation block.*/

/*The last part of the code snippet provides the struct definition for `Node`. This struct has two members:*/

/*1. `ElementType Element;`: This member represents the element stored in a stack node. The specific data type for `ElementType` is not defined in the given code snippet, but it represents the type of elements that can be stored in the stack.*/

/*2. `PtrToNode Next;`: This member is a pointer to the next node in the stack. It forms the linked list structure by connecting nodes together.*/

/*In summary, the code snippet includes type declarations for the stack ADT using a linked list implementation. It also provides a struct definition for the `Node` struct, which forms the individual nodes of the linked list.*/

/This code snippet represents a basic implementation of a stack data structure in C. It includes two functions: `CreateStack` and `MakeEmpty`.*/

/*The `CreateStack` function is responsible for creating a new stack. It first declares a variable `S` of type `Stack`, which is a pointer to a structure representing a stack. Then, it allocates memory for a new stack node using the `malloc` function and assigns the address of the allocated memory to `S`.*/

/*Next, the code checks if the allocation was successful by verifying if `S` is `NULL`. If `S` is indeed `NULL`, it means that the memory allocation failed, so the program calls a function called `FatalError` to handle the error.*/

/*If the allocation was successful, the `MakeEmpty` function is called to initialize the stack by clearing any existing elements. Finally, the function returns the created stack `S`.*/

/*The `MakeEmpty` function is responsible for clearing the stack by removing all its elements. It takes a parameter `S`, which represents the stack to be emptied. The function first checks if `S` is `NULL`, indicating that no stack has been created yet. If `S` is `NULL`, an error is raised with the `Error` function stating that `CreateStack` must be called first.*/

/*If `S` is not `NULL`, indicating a valid stack, the function enters a loop that continues until the stack is empty. In each iteration, the `Pop` function is called to remove the top element of the stack. This process continues until the stack becomes empty.*/

/*Overall, these functions provide the basic functionality to create a stack, allocate memory for it, and empty the stack by removing its elements.*/
The provided code snippet includes two functions: `Push` and `Top`. These functions are used in a linked list implementation of a stack data structure.*/

/*The `Push` function is responsible for adding an element to the top of the stack. It takes two parameters: `ElementType X`, which represents the value of the element to be added, and `Stack S`, which represents the stack.*/

/*Inside the function, a new node for the element is created using `malloc`. The `malloc` function allocates memory for a new node, and the address of the allocated memory is stored in the `TmpCell` pointer.*/

/*Next, the code checks if the memory allocation was successful by verifying if `TmpCell` is `NULL`. If `TmpCell` is indeed `NULL`, it means that the memory allocation failed, so the program calls the `FatalError` function to handle the error.*/

/*If the allocation was successful, the code proceeds to assign the element value to the newly created node by setting `TmpCell->Element = X`. Then, it links the new node to the rest of the stack by adjusting the pointers. `TmpCell->Next` is set to the current top of the stack `S->Next`, and `S->Next` is updated to point to the newly added node `TmpCell`. This way, the new node becomes the new top of the stack.*/

/*The `Top` function is used to retrieve the value of the top element in the stack. It takes one parameter, `Stack S`, which represents the stack.*/

/*The function first checks if the stack is empty by calling the `IsEmpty` function (not shown in the provided code snippet). If the stack is not empty, it returns the value of the element stored in the node pointed to by `S->Next`. This is the top element of the stack.*/

/*If the stack is empty, an error is raised using the `Error` function, indicating that the stack is empty. In this case, the function returns a default value of 0.*/

/*Overall, these functions allow elements to be added to the top of the stack using the `Push` function and retrieve the value of the top element using the `Top` function in a linked list implementation of a stack.*/
The provided code snippet includes a function named `Pop`, which is used to remove the top element from a stack implemented as a linked list.

The `Pop` function takes one parameter, `Stack S`, representing the stack from which the element is to be popped.

Inside the function, a pointer `FirstCell` of type `PtrToNode` is declared. This pointer will be used to temporarily store the address of the node representing the top element of the stack.

The code first checks if the stack is empty by calling the `IsEmpty` function (not shown in the provided code snippet). If the stack is indeed empty, an error is raised using the `Error` function, indicating that the stack is empty.

If the stack is not empty, the code proceeds to remove the top element. The pointer `FirstCell` is assigned the address of the node that represents the current top element of the stack, which is obtained by `S->Next`. 

Next, the code updates the `S->Next` pointer to point to the node that comes after the current top element. This is achieved by assigning `S->Next` with `S->Next->Next`. By doing so, the node directly below the current top element becomes the new top of the stack.

Finally, the memory occupied by the node representing the popped element is freed using the `free` function. This ensures that the memory is properly deallocated, avoiding memory leaks.

In summary, the `Pop` function removes the top element from the stack by adjusting the necessary pointers and freeing the memory of the popped element.
