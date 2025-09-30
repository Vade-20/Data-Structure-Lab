/*Write a menu-driven C program using structures to implement the following operations on a
singly linked list:
➢ Insert an element before another specified element in the list
(Example: Insert 10 before 25)
➢ Insert an element after another specified element in the list
(Example: Insert 40 after 25)
➢ Delete a specified element from the list
(Example: Delete node containing 15)
➢ Traverse the list and display all elements
➢ Reverse the linked list
(Modify the links such that the list is reversed)
➢ Sort the list in ascending order
(Using Bubble Sort or any appropriate algorithm on linked list)
➢ Delete every alternate node in the list
(Starting from the second node)
➢ Insert an element into a sorted linked list while maintaining the sorted order
(Example: Insert 28 into a list that is already sorted)*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    if (NewNode==NULL){
        printf("Memory Allocation failed");
        return;
    }
    NewNode->data = data;
    NewNode->next = NULL;
    if (head == NULL){
        head = NewNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}
void insert_before(int data_in,int data_before){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data_in;
    struct Node * temp = head;
    if (head->data == data_before){
        NewNode->next = head;
        head = NewNode;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == data_before){
            NewNode->next = temp->next;
            temp->next = NewNode;
            return;
        }
        temp = temp->next;
    }
    printf("Node not found");
    
}

void display(){
    if (head == NULL){
        printf("The list is empty");
    }
    else{
        struct Node* temp = head;
        while (temp != NULL)
        {
            printf("%d,",temp->data);
            temp = temp->next;
        }
        
    }
}
void sort_(){
    struct Node* prev = NULL;
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        
    }
    

}
int main(){
    create(10);
    create(6);
    insert_before(11,10);
    create(5);
    create(9);
    create(88);

    display();
}