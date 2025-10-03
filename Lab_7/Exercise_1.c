/*
Array Based Stack
i. Check whether a given string is a palindrome using stack.
➤ Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
➤ Push opening brackets, pop for matching closing brackets.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}
int check_bracket(char str[]){
    int len_str = strlen(str);
    
    for (int i = 0 ; i < len_str ; i++){
        if (str[i] == '[' || str[i] == '(' || str[i] == '{'){
            push(str[i]);
        }
        else if (str[i] == ']' || str[i] == ')' || str[i] == '}')
        {
            char rev = pop();
            if (rev == '[' && str[i] == ']' || 
                rev == '(' && str[i] == ')' || 
                rev == '{' && str[i] == '}'){
                    continue;
                }
            else
            {
                return 0 ;
            }
            
        }   
    }
    return 1;
}
int isPalindrome(char str[]) {
    int len = strlen(str);
    char rev[MAX];

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        rev[i] = pop();
    }
    rev[len] = '\0';

    if (strcmp(str, rev) == 0)
        return 1;
    else
        return 0;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)){
        printf("%s is a palindrome.\n", str);}
    else{
        printf("%s is NOT a palindrome.\n", str);}

    int i = 0 ;
    while (stack[i] != '\0')
    {
        stack[i] = ' ';
        i++;
    }

    char str1[MAX] = "(a+B+c+{D+(E)})";
    if (check_bracket(str1)){
        printf("Brackets are correct");
    }
    else{
        printf("Brackets are not corrct");
    }
    return 0;
}
