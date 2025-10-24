#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Table_size 10

typedef struct Book {
    char title[100];
    char author[100];
    struct Book * next;
}Book;

Book* hashmap[Table_size];

Book * createBook(char title[],char author []){
    Book * newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->title,title);
    strcpy(newBook->author,author);
    newBook->next = NULL;
}

int hash_function(char title[]){
    int hash = 10;
    int i = 0;
    while (title[i] != '\0')
    {
        hash = hash + title[i];
        i++;
    }
    return hash % Table_size;
}

void insert_book()
{
    char title [100];
    char author [100];
    printf("Enter the book title :");
    gets(title);
    printf("Enter the Author Name :");
    gets(author);
    
    int index = hash_function(title);
    Book * newBook = createBook(title,author);
    if (hashmap[index] == NULL)
    {
        hashmap[index] = newBook;
    }
    else
    {
        newBook->next = hashmap[index];
        hashmap[index] = newBook;
    }
    printf("\n%s by %s successfully added to the library",title,author);
}

void search()
{
    char title[100];
    printf("Enter the book title :");
    gets(title);
    int index = hash_function(title);
    Book * temp = hashmap[index];

    while (temp != NULL)
    {
        if (strcmp(temp->title,title) == 0){
            printf("Book Found\nIndex : %d\n\t%s\t%s",index,temp->title,temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book '%s' not found in the library.\n", title);

}

void display()
{
    printf("Books in the library are :-\n");
    for (int i = 0; i < Table_size; i++)
    {
        Book * temp = hashmap[i];
        while (temp != NULL)
        {
            printf("\nIndex : %d\n\t%s\t%s",i,temp->title,temp->author);
            temp = temp->next;
        }
        
    }
}


int main(){
    int choice;
    while (1) {
            printf("\n\n\n==== Library HashMap Simulation ====\n");
            printf("1. Add Book\n");
            printf("2. Search Book\n");
            printf("3. Display All Books\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); 

            switch (choice) {
                case 1:
                    insert_book();
                    break;

                case 2:
                    search();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    printf("Exiting the program.\n");
                    exit(0);

                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
        return 0;
}