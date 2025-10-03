/*2. Linked List-Based Stack:
i. Write a program to input an infix expression and convert into its equivalent
post fix form and display. Operands can be single characters.

ii. Evaluate a postfix expression using stack.
➤ Push operands, pop two for operator, and push result back*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    char data;
    struct Node * next;
}Node;

Node * head = NULL;
Node * tail = NULL;

void push(char data){
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
        tail = head;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

char pop(){
    char ans ;
    if (head == NULL){
        printf("Stack underflow");
        return '\0';}
    
    ans = tail->data;
    if (head->next == NULL){
        head = NULL;
        tail = NULL;
    }
    else{   
        Node * temp = head;
        Node * prev = NULL;
        while (temp->next != tail){
            temp = temp->next;}
        temp->next = NULL;
        free(tail);
        tail = temp;
    } 
    return ans;
}

int check_sign(char sign){
    char signs[6] = {'+','-','*','/','^','('};
    for (int  i = 0; i < 6; i++)
    {
        if (signs[i] == sign)
            return 1;
    }
    return 0 ;  
}

void emptying_stacks(char arr[],int* index,int check){
    int temp = *index;
    while (tail != NULL)
    {
        if (tail->data == '(' && check == 1){
            pop();
            break;
        }
        if (tail->data == '(' && check == 0){
            break;
        }
        arr[temp] = pop();
        temp ++;
    }
    *index = temp;
}


int get_preference(char sign){
    switch (sign)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    }
}

void infix_to_postfix(char str[])
{
    int len = strlen(str);
    char arr[len+1];
    int index = 0;
    for (int i = 0 ; i < len ; i++)
    {
        char temp = str[i];
        if ((temp < 123 && temp > 96) || (temp < 91 && temp > 64) )
        {
            arr[index++] = temp;
        }
        else if (temp == ')')
        {
            emptying_stacks(arr,&index,1);
        }
        else if (check_sign(temp))
        {
            if (head == NULL || tail->data == '(' || temp  =='(')
            {
                push(temp);
            }
            else if (get_preference(temp) > get_preference(tail->data))
            {
                push(temp);
            }
            else
            {
                emptying_stacks(arr,&index,0);
                push(temp);
            }   
        }        
    }
    emptying_stacks(arr,&index,0);
    printf("Infix : %s\nPostfix : ",str);
    int i = 0 ; 
    while (arr[i] != '\0')
    {
        printf("%c",arr[i]);
        i++;
    } 
}



int main(){
    char str[100];
    printf("Please enter the equation: ");
    fgets(str,40,stdin);
    infix_to_postfix(str);
    printf("\n");
}