/*Write a C program to sort a given list of elements using
i.) Bubble Sort
ii.) Selection Sort
iii.) Insertion Sort*/

#include <stdio.h>

void swapped(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[],int n){
    for(int i =0 ; i < n ; i++){
        printf("%d\t",arr[i]);
    }
}

void bubble_sort(int arr[],int n){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n-i-1 ; j++){
            if (arr[j]>arr[j+1]){
                swapped(&arr[j],&arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[],int n){
    for (int i = 0 ; i < n ; i++){
        int* smallest = &arr[i];
        for (int j = i ; j < n ; j++){
            if (*smallest > arr[j]){
                smallest = &arr[j];
            }
        }
        swapped(smallest,&arr[i]);
    }
}

void insertion_sort(int arr[],int n){
    for (int i=1 ; i < n ; i++){
        int key = arr[i];
        int j = i-1;
        
        while ( j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


int main(){
    int arr[12] = {12,14,15,6,112,4,50,10,53,202,33,10};
    insertion_sort(arr,12);
    display(arr,12);
}