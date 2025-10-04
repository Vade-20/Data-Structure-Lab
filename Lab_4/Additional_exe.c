/*Additional Exercises
1. Recursive functions:
i) Create a linked list recursively
ii) Traverse a linked list recursively
2. Merge two sorted linked lists (X and Y in non-decreasing order) into a new sorted
list Z. After merge, X and Y should not exist separately. Do not use new nodes.
3. Interleave two lists:
Merge list1 = (x1, x2…..xn) and list2 = (y1, y2…..ym) into list3 such that:
o list3 = (x1, y1, x2, y2….xm, ym, xm+1…xn) if m ≤ n
o list3 = (x1, y1, x2, y2…xn, yn, xn+1…ym) if m > n*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node * head = NULL;

Node * create_list(int data){
    Node * newNode = (Node *)malloc(sizeof(newNode));
    if (newNode == NULL){
        printf("Memory Allocation failed");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

void Add_element(int data){
    Node* newNode = create_list(data);
    
}
