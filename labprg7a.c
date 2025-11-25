#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;

void create(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertLeft(int target, int val) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL) {
        printf("Target not found\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;
    temp->prev = newNode;
}
void deleteValue(int val) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != val)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
void display() {
    struct Node *temp = head;
    printf("Doubly List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int ch, val, target;
    printf("1.Create\n2.Insert left of a node\n3.Delete value\n4.Display\n5-Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            create(val);break;
        case 2:
            printf("Insert value: ");
            scanf("%d", &val);
            printf("Left of value: ");
            scanf("%d", &target);
            insertLeft(target, val);break;
        case 3:
            printf("Value to delete: ");
            scanf("%d", &val);
            deleteValue(val);break;
        case 4:display();break;
        case 5:exit(0);
        default:printf("Invalid choice\n");
        }
    }
    return 0;
}
