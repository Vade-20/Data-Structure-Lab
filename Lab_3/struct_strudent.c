/*Write a C program to define a student structure with the data members to store name,
roll no and grade of the student. Also write the required functions to read, display, and
sort student information according to the roll number of the student. All the member
functions will have array of objects as arguments*/

#include <stdio.h>
typedef struct{
    char name[100];
    int roll_num;
    char grade;
}Student;

void display(Student s){
    printf("Name: %s",s.name);
    printf("\nRoll Number: %d",s.roll_num);
    printf("\nGrade: %c",s.grade);
}  

void read(Student* s){
    printf("\nPlease enter the name:");
    fgets(s->name,sizeof(s->name),stdin);
    printf("Please enter the roll number:");
    scanf("%d",&s->roll_num);
    printf("Please enter the grade:");
    scanf(" %c",&s->grade);
} 


void display_ascending_order(Student s[],int n){
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            if (s[j].roll_num > s[j+1].roll_num){
                Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    for (int i = 0 ; i < n ; i++){
        display(s[i]);
        printf("\n\n");
    }
}
int main(){
    Student s[6] = {
        {"Vednt",5,'A'},
        {"Saxena",1,'B'},
        {"Setu",4,'C'},
        {"Ray",3,'D'},
        {"JUly",2,'E'},
    };
    read(&s[5]);
    display_ascending_order(s,6);
}