/*ii. Evaluate a postfix expression using stack.
➤ Push operands, pop two for operator, and push result back*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node* next;  
}Node;

Node * head = NULL;
Node * tail = NULL;

int check_sign(char sign)
{
    char signs[5] = {'+','-','*','/','^'};
    for (int  i = 0; i < 5; i++)
    {
        if (signs[i] == sign){
            return 1;
        }
    }
    return 0 ;  
}

void push(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
        tail = head;}
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int pop(){
    if (head == NULL){
        return 0;
    }
    int ans = tail->data;
    if (head == tail){
        head = tail = NULL;
    }
    else{   
        Node * temp = head;
        while (temp->next != tail){
            temp = temp->next;}
        temp->next = NULL;
        free(tail);
        tail = temp;
    } 
    return ans;
}


int evaluation(char str[]){

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] > 47 && str[i] < 58)
        {
            int temp =  str[i] - '0';
            push(temp);
        }
        else if (check_sign(str[i])){
            int val_2 = pop();
            int val_1 = pop();
            printf("%d %c %d\n",val_1,str[i],val_2);
            switch (str[i])
            {
            case '+':
                push(val_1+val_2);
                break;
            case '-':
                push(val_1-val_2);
                break;
            case '*':
                push(val_1*val_2);
                break;
            case '/':
                push(val_1/val_2);
                break;
            case '^':
                push(pow(val_1,val_2));
                break;
            }
        }
    }
    return pop();
}

int main(){
    char str[20] = "23*54*+9-1+";
    printf("%d",evaluation(str));
}