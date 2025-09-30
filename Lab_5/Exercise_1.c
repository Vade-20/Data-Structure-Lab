/*1. Write a menu-driven C program using structures to implement the following operations
on a Doubly Linked List.
➢ Insert an element at the rear end of the list
(Append a new node to the end of the list)
➢ Delete an element from the rear end of the list
(Remove the last node in the list)
➢ Insert an element at a given position in the list
(e.g., Insert at position 3. Positioning starts from 1.)
➢ Delete an element from a given position in the list
➢ Insert an element after a node containing a specific value
(e.g., Insert 40 after 25)
➢ Insert an element before a node containing a specific value
(e.g., Insert 10 before 25)
➢ Traverse the list in forward direction
(From head to tail)
➢ Traverse the list in reverse direction
(From tail to head – i.e., reverse traversal)*/

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode{
    int data;
    struct DNode* prev;
    struct DNode* forw;
}DNode;

DNode* head = NULL;
DNode* tail = NULL;

DNode * display_forw(){
    if (head == NULL){
        printf("The list is empty");
    }
    else{
        DNode* temp = head;
        while (temp != NULL)
        {
            printf("%d",temp->data);
            if (temp->forw != NULL){
                printf("->");
            }
            temp = temp->forw;
        }
        printf("\n");
        
    }
}

DNode* create_list(int data){
    DNode* temp = (DNode*) malloc(sizeof(DNode));
    if (temp == NULL){
        printf("Memeory allocation failed\n");
    }
    else{
        temp->data = data;
        temp->prev = NULL;
        temp->forw = NULL;
    }
    return temp;
}

void Add_element_at_the_end(int data){
    DNode* newNode = create_list(data);
    if (head == NULL){
        head = newNode;
        tail = head;
        return;
    }
    else if (tail == head){
        head->forw = newNode;
        newNode->prev = head;
        tail = newNode;
    }
    else
    {
        tail->forw = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}

void Delete_element_at_the_end(){
    if (head == NULL){
        printf("The list is empty\n");
        return;
    }
    DNode* temp = tail;
    tail = tail->prev;
    tail->forw = NULL;
    free(temp);
}

void Insert_at_specific_pos(int data, int pos){
    DNode* newNode = create_list(data);
    DNode* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
       if (temp == NULL){
        printf("Position exceeds the range of the list\n");
        return;}
        temp = temp->forw;
    }
    newNode->forw = temp;
    newNode->prev = temp->prev;
    temp->prev->forw = newNode;
    temp->prev = newNode;
    
}

void Delete_at_specific_pos(int pos){
    DNode* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
       if (temp == NULL){
        printf("The position exceeds the list range");
        return;
       }
       temp = temp->forw;
    }
    temp->prev->forw = temp->forw;
    if (temp->forw != NULL){temp->forw->prev = temp->prev;}
    free(temp);
}

void Insert_after_value(int data,int key){
    DNode * newNode = create_list(data);
    DNode * temp = head;
    
    while (temp != NULL)
    {
        if (temp->data == key){break;}
        temp = temp->forw;
    }

    if (temp == NULL){
        printf("The value is not in the list");
    }
    else {
        newNode->forw = temp->forw;
        newNode->prev = temp;
        temp->forw->prev = newNode;
        temp->forw = newNode;
    }
}

void Insert_before_value(int data , int key){
    DNode* NewNode = create_list(data);
    DNode* temp = head;

    while (temp != NULL)
    {
        if (temp->data == key){break;}
        temp = temp->forw;
    }
    if (temp == NULL){
        printf("The value is not in the list");
    }
    else{NewNode->forw = temp;
    NewNode->prev = temp->prev;
    temp->prev->forw = NewNode;
    temp->prev = NewNode;}
}

void display_prev(){
    if (head == NULL){
        printf("The list is empty");
    }
    else{
        while (tail != NULL)
        {
            printf("%d",tail->data);
            if (tail->prev != NULL){
                printf("<-");
            }
            tail = tail->prev;
        }
        printf("\n");
        
    }
}
int main(){
    Delete_element_at_the_end();
    int a[10] = {11,22,33,44,55,66,77,88,99,100};
    for (int i = 0 ; i < 10; i++){
        Add_element_at_the_end(a[i]);
    }
    printf("All the element in the list :\n");
    display_forw();
    printf("\nList after deleting the last 2 element:\n");
    Delete_element_at_the_end();
    Delete_element_at_the_end();
    display_forw();

    printf("\nInserting 30 at position at 3\n");
    Insert_at_specific_pos(30,3);
    display_forw();

    printf("\nDeleting element at position 9\n");
    Delete_at_specific_pos(5);
    display_forw();

    printf("\nInsert 12 element after value 77\n");
    Insert_after_value(12,77);
    display_forw();

    printf("\nInsert 45 element before value 55\n");
    Insert_before_value(45,55);
    display_forw();

    printf("\nThe list in reverse direction\n");
    display_prev();

}