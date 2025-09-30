/*
1.Write a C program to implement a Circular Singly Linked List using First and Last
pointers.
Implement the following operations:
i. Insertion at the end of the list using First and Last pointers.
ii. Deletion from the beginning or end using First and Last pointers.
iii. Display the list after each operation.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct CNode
{
    int data;
    struct CNode* next;
}CNode;

CNode * head = NULL;
CNode * tail = NULL;


CNode* createNode(int data){
    CNode * newNode = (CNode *)malloc(sizeof(CNode));
    if (newNode == NULL){
        printf("Memory allocation failed.");
    }
    else{newNode->data = data;
    newNode->next = NULL;
    return newNode;}
}

void display(){
    CNode * temp = head;
    if (head == NULL){
        printf("The list is empty");
    }
    else{
    printf("%d->",temp->data);
    temp = temp->next;}

    while (temp != head)
    {
        printf("%d",temp->data);
        if (temp->next != head){
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
    
}

void Insertion_at_end(int data){
    CNode * newNode = createNode(data);
    if (head == NULL){
        head = newNode;
        tail = head;
        head->next = head;}
    else if (head == tail){
        head->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void Delete_at_end(){
    CNode * temp = head;
    if (head == NULL){
        printf("Empty list");
    }
    else if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    free(tail);
    temp->next = head;
    tail = temp;
    }
}
void Delete_at_begining(){
    CNode * temp = head;
    if (head == NULL){
        printf("Empty list");
    }
    else if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}
int main(){
    for (int i = 0; i < 10 ; i++)
    {
        Insertion_at_end(i+1);
    }
    display();
    Delete_at_begining();
    Delete_at_begining();
    display();
    Delete_at_end();
    Delete_at_end();
    display();
}