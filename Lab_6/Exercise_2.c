/*Add Two Polynomials Represented as Doubly Linked Lists
i) Represent each polynomial using a doubly linked list, where each node contains the
coefficient and exponent of a term.
ii) Write a function to add two polynomials by merging terms with equal exponents.
The resulting polynomial should be stored in a new doubly linked list, maintaining the
order of terms in descending powers of exponents.
iii) Display all three polynomials: the two input polynomials and their sum.
Ensure dynamic memory allocation is used for all node operations and that both prev
and next pointers are maintained correctly.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int coeff;
    int exp;
    struct poly * next;
    struct poly * prev;
}poly;

poly * create_polynomial(int coeff , int exp){
    poly* newNode = (poly *)malloc(sizeof(poly));
    if (newNode == NULL){
        printf("Memory Allocation failed");
    }
    else{
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
}

void display(poly ** head){
    poly * temp = *head;
    while (temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->exp);
        if (temp->next != NULL){printf("+");}
        temp = temp->next;
    }
    printf("\n");
    
}


void polynomials(poly ** head ,int coeff,int exp){
    poly * newNode = create_polynomial(coeff,exp);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    poly * temp = *head;

    while (temp->next != NULL)
    {
        if (temp->exp < exp || temp->exp == exp){
            break;
        }
        temp = temp->next;
    }

    if (temp->exp < exp){
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != NULL){ temp->prev->next = newNode;}
            else{*head = newNode;}
            temp->prev = newNode;
            return;}
    else if (temp->exp == exp){
        temp->coeff += coeff;
        return;
    }
    
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL){temp->next->prev = newNode;}
    temp->next = newNode;
}
    
poly ** add_poly(poly** a, poly** b){
    poly *c = NULL;
    poly ** ans = &c;
    poly * temp_a = *a;
    poly * temp_b = *b;

    while (temp_a != NULL && temp_b != NULL){
        int a_exp = temp_a->exp;
        int b_exp = temp_b->exp;

        if (a_exp == b_exp){
            polynomials(ans,temp_a->coeff+temp_b->coeff,a_exp);
            temp_a = temp_a->next;
            temp_b = temp_b->next;
        }
        else if (a_exp>b_exp){
            polynomials(ans,temp_a->coeff,a_exp);
            temp_a = temp_a->next;
        }
        else if (a_exp<b_exp){
            polynomials(ans,temp_b->coeff,b_exp);
            temp_b = temp_b->next;
        }
    }
    while (temp_a != NULL)
    {
        polynomials(ans,temp_a->coeff,temp_a->exp);
        temp_a = temp_a->next;
    }
    while (temp_b != NULL)
    {
        polynomials(ans,temp_b->coeff,temp_b->exp);
        temp_b = temp_b->next;
    }
    return ans;
}


int main(){
    poly * a = NULL;
    poly * p = NULL;
    poly **q = &p;
    poly **b = &a;

    polynomials(b,5,13);
    polynomials(b,8,13);
    polynomials(b,1,133);
    polynomials(q,5,16);
    polynomials(q,8,13);
    polynomials(q,1,13);
    poly **c = add_poly(b,q);
    display(c);


}
