#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // For boolean type

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Correct NULL spelling

// Function to insert a node at the end
void insert(int value) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node)); // Add sizeof
    ptr->data = value;
    ptr->next = NULL;
    
    if(head == NULL) {
        head = ptr;
    } else {
        struct Node *current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
    }
    printf("Value %d inserted successfully!\n", value);
}

// Function to traverse and display list
void traverse() {
    struct Node *current = head;
    if(current == NULL) {
        printf("List is empty!\n");
    } else {
        printf("List elements: ");
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to search for a value
void search(int value) {
    struct Node *current = head;
    bool status = false; // lowercase false
    
    if(current == NULL) {
        printf("List is empty!\n");
    } else {
        while(current != NULL) {
            if(current->data == value) {
                status = true;
                break;
            }
            current = current->next;
        }
        
        if(status) {
            printf("Value %d found in list!\n", value);
        } else {
            printf("Value %d not found!\n", value);
        }
    }
}

// Function to delete a node
void delete(int value) {
    struct Node *current = head;
    struct Node *prev = NULL;
    bool found = false;

    if(current == NULL) {
        printf("List is empty!\n");
        return;
    }

    while(current != NULL) {
        if(current->data == value) {
            found = true;
            if(prev == NULL) { // Deleting head node
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Value %d deleted successfully!\n", value);
            return;
        }
        prev = current;
        current = current->next;
    }

    if(!found) {
        printf("Value %d not found for deletion!\n", value);
    }
}

int main() {
    int choice, value;
    
    while(1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Traverse\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
                
            case 2:
                traverse();
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
                
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}