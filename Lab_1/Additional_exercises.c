/*1. Write a C program to compare the number of comparisons and swaps made in Bubble
Sort, Selection Sort, and Insertion Sort for the same input array.
2. Write a C program to read two matrices A & B, create and display a third matrix C
such that C (i, j) = max (A(i, j) , B(i, j))
3. Write a C program to read two matrices, A and B and perform the following operations:
(i) Multiply the two matrices (A × B)
(ii) Add the two matrices (A + B)
(iii) Read a square matrix and check whether it is a magic square or not*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapping(int *a,int *b){
    int temp = * a ; 
    * a = * b;
    * b = temp;
}

void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void bubble_sort(int arr[],int n , int *comp , int *swap){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            (*comp)++;
            if (arr[j] > arr[j+1]){
                (*swap)++;
                swapping(&arr[j],&arr[j+1]);
            }
        }
        
    }
}

void selection_sort(int arr[],int n , int *comp,int *swap){
    for (int i = 0; i < n; i++)
    {
        int key = i ;
        for (int j = i; j < n; j++)
        {
            (*comp)++;
            if (arr[key] > arr[j]){
                key = j;
            }
        }

        if (i != key)
        {
        (*swap)++;
        swapping(&arr[i],&arr[key]);
        }
    }
}

void insertion_sort(int arr[],int n,int *comp,int *swap){
    for (int i=1 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;
        
        while ( j >= 0 ){
            (*comp)++;
            if (arr[j] > key)
            {
                arr[j+1] = arr[j];
                (*swap)++;
                j = j-1;
            }
            else
            {
                break;
            }
            
            
        }
        arr[j+1] = key;
    }
}

int main(){
    int n = 10;
    int arr[] = {33,22,55,66,11,77,88,100,99,22};
    int arr_1[n],arr_2[n],arr_3[n];

    memcpy(arr_1,arr,sizeof(int)*10);
    memcpy(arr_2,arr,sizeof(int)*10);
    memcpy(arr_3,arr,sizeof(int)*10);

    int swap_1 = 0,swap_2 = 0,swap_3 = 0 ;
    int comp_1 = 0,comp_2 = 0 ,comp_3 = 0 ;

    bubble_sort(arr_1,n,&comp_1,&swap_1);
    selection_sort(arr_2,n,&comp_2,&swap_2);
    insertion_sort(arr_3,n,&comp_3,&swap_3);

    printf("Original array :\n");
    display(arr,n);
    printf("\nBubble Sort:\n");
    display(arr_1,n);
    printf("Comparison : %d\tSwapped : %d",comp_1,swap_1);
    printf("\n\nSelection Sort:\n");
    display(arr_2,n);
    printf("Comparison : %d\tSwapped : %d",comp_2,swap_2);
    printf("\n\nInsertion Sort:\n");
    display(arr_3,n);
    printf("Comparison : %d\tSwapped : %d",comp_3,swap_3);

}