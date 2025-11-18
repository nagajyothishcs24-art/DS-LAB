#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertEnd(struct Node* list, int data) {
    struct Node* newNode = createNode(data);
    if (list == NULL) {
        return newNode;
    }
    struct Node* temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return list;
}
void display(struct Node* list) {
    if (list == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node* temp = list;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int* listToArray(struct Node* list, int* size) {
    *size = 0;
    struct Node* temp = list;
    while (temp != NULL) {
        (*size)++;
        temp = temp->next;
    }
    int* arr = (int*)malloc(*size * sizeof(int));
    temp = list;
    for (int i = 0; i < *size; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    return arr;
}
struct Node* arrayToList(int* arr, int size) {
    struct Node* newList = NULL;
    for (int i = 0; i < size; i++) {
        newList = insertEnd(newList, arr[i]);
    }
    return newList;
}
int compareInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
struct Node* sortList(struct Node* list) {
    if (list == NULL) return list;
    int size;
    int* arr = listToArray(list, &size);
    qsort(arr, size, sizeof(int), compareInt);
    struct Node* sortedList = arrayToList(arr, size);
    free(arr);
    return sortedList;
}
struct Node* reverseList(struct Node* list) {
    if (list == NULL) return list;
    int size;
    int* arr = listToArray(list, &size);
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    struct Node* reversedList = arrayToList(arr, size);
    free(arr);
    return reversedList;
}
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    list1 = insertEnd(list1, 5);
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 9);
    printf("List 1: ");
    display(list1);
    list1 = sortList(list1);
    printf("Sorted List: ");
    display(list1);
    list1 = reverseList(list1);
    printf("Reversed List: ");
    display(list1);
    list2 = insertEnd(list2, 8);
    list2 = insertEnd(list2, 2);
    printf("List 2: ");
    display(list2);
    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);
    return 0;
}
