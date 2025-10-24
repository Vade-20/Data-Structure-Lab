#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  


typedef struct Book {
    char title[50];
    char author[50];
    int id;
    struct Book* next; 
} Book;


Book* hashTable[TABLE_SIZE];

int hashFunction(char* title) {
    int hash = 0;
    for (int i = 0; title[i] != '\0'; i++) {
        hash = (hash + title[i]) % TABLE_SIZE;
    }
    return hash;
}

Book* createBook(int id, char* title, char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = NULL;
    return newBook;
}

void insertBook(int id, char* title, char* author) {
    int index = hashFunction(title);
    Book* newBook = createBook(id, title, author);

    if (hashTable[index] == NULL) {
        hashTable[index] = newBook;
    } else {
        newBook->next = hashTable[index];
        hashTable[index] = newBook;
    }
    printf("Book '%s' by %s added successfully!\n", title, author);
}

void searchBook(char* title) {
    int index = hashFunction(title);
    Book* temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Book Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("Book '%s' not found in the library.\n", title);
}

void displayLibrary() {
    printf("\n--- Library Catalog ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Book* temp = hashTable[i];
        if (temp != NULL) {
            printf("Index %d:\n", i);
            while (temp != NULL) {
                printf("  [ID: %d] %s by %s\n", temp->id, temp->title, temp->author);
                temp = temp->next;
            }
        }
    }
}

int main() {
    int choice, id;
    char title[50], author[50];

    while (1) {
        printf("\n==== Library HashMap Simulation ====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear newline

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter Book Title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // remove newline
                printf("Enter Author Name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';
                insertBook(id, title, author);
                break;

            case 2:
                printf("Enter Book Title to Search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0';
                searchBook(title);
                break;

            case 3:
                displayLibrary();
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
