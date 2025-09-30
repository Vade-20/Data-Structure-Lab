/*1. Write a small function to find the smallest element in an array using pointers.
In the main function, create a dynamically allocated array, read the values from the
keyboard, and pass the array to the function.
Display the result (smallest element) in the main function.*/
#include <stdio.h>
#include <stdlib.h>

int* find_smallest(int * arr ,int n){
    int* small = arr;
    for (int i = 0 ; i<n ; i++){
        if (*small > *(arr+i)){
            small = arr+i;
        }
    }
    return small;
}

int main(){
    int* p = (int *)malloc(sizeof(int)*5);
    for (int i = 0 ; i< 5 ; i++){
        printf("Enter the numbers %d: ",i+1);
        scanf("%d",p+i);
    }
    printf("Find the smallest : %d",*find_smallest(p,5));
}