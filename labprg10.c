#include <stdio.h>
#define MAX 100
int hashTable[MAX];
int m;
void initHashTable() {
    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }
}
int hashFunction(int key) {
    return key % m;
}
void insert(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        while (hashTable[(index + i) % m] != -1) {
            i++;
        }
        hashTable[(index + i) % m] = key;
    }
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}
int main() {
    int n, key;
    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);
    printf("Enter number of employee records (n): ");
    scanf("%d", &n);
    initHashTable();
    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
