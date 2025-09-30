/*Define a structure Student with the following members:
char name [50] – to store student name as a string
int roll_no – to store roll number
float marks – to store marks
Write a C program that:
i. Reads the details of ‘n’ students using a function that uses pointer to structure
as an argument.
ii. Displays the details of all students using a separate function.
iii. Finds and displays the student with the highest marks using pointer-based
access.*/

#include <stdio.h>

typedef struct{
    char name[50];
    int roll_no;
    float marks;
}Student;

void read(Student* s){
    printf("\n\nEnter name :");
    scanf("%s",s->name);
    printf("Roll number:");
    scanf("%d",&s->roll_no);
    printf("Marks :");
    scanf("%f",&s->marks);
}

void display(Student s[],int n){
    for (int i = 0 ; i < n ; i++){
        Student temp = s[i];
        printf("\n\nName:%s\nRoll Number:%d\nMarks :%f",temp.name,temp.roll_no,temp.marks);
    }
}

void find_highest(Student s[],int n){
    Student* temp = &s[0];

    for (int i = 0 ; i<n ; i++){
        if (temp->marks < s[i].marks){
            temp = &s[i];
        }
    }
    printf("\n\nName:%s\nRoll Number:%d\nMarks :%f",temp->name,temp->roll_no,temp->marks);

}

int main(){
    int choice;
    printf("Enter number of students:");
    scanf("%d",&choice);
    Student s[choice];
    for (int i = 0; i < choice; i++)
    {
       read(&s[i]);
    }
    display(s,choice);
    find_highest(s,choice);
    
}