#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (utility for building initial list)
void insertEnd(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Traverse and display
void displayList() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    Node* current = head;
    printf("Linked list elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Insert before a specified element
void insertBefore(int key, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->data == key) { // insert before first element
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Element %d not found!\n", key);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Insert after a specified element
void insertAfter(int key, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a specified element
void deleteElement(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Element %d not found!\n", key);
    } else {
        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

// Reverse the linked list
void reverseList() {
    Node* prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Sort linked list (Bubble Sort)
void sortList() {
    if (head == NULL) return;
    int swapped;
    Node *ptr1, *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Delete every alternate node
void deleteAlternate() {
    if (head == NULL) return;
    Node* prev = head;
    Node* curr = head->next;
    while (prev != NULL && curr != NULL) {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev != NULL)
            curr = prev->next;
    }
}

// Insert into sorted list
void insertSorted(int data) {
    Node* newNode = createNode(data);
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data < data)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Insert Before Element\n");
        printf("4. Insert After Element\n");
        printf("5. Delete Element\n");
        printf("6. Reverse List\n");
        printf("7. Sort List\n");
        printf("8. Delete Alternate Nodes\n");
        printf("9. Insert in Sorted List\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter key element: ");
                scanf("%d", &key);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertBefore(key, data);
                break;
            case 4:
                printf("Enter key element: ");
                scanf("%d", &key);
                printf("Enter new data: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                deleteElement(key);
                break;
            case 6:
                reverseList();
                printf("List reversed.\n");
                break;
            case 7:
                sortList();
                printf("List sorted.\n");
                break;
            case 8:
                deleteAlternate();
                printf("Alternate nodes deleted.\n");
                break;
            case 9:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertSorted(data);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
