#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int key;
    char name[50];
    int is_occupied; // 0: Empty, 1: Occupied
} HashTable;

void initialize_table(HashTable table[], int m) {
    for (int i = 0; i < m; i++) {
        table[i].is_occupied = 0;
    }
}

int hash_function(int key, int m) {
    return key % m;
}

void insert(HashTable table[], int m, int key, const char* name) {
    int address = hash_function(key, m);
    int original_address = address;
    while (table[address].is_occupied) {
        address = (address + 1) % m; // Linear probing
        if (address == original_address) {
            printf("Hash table is full. Cannot insert key %d.\n", key);
            return;
        }
    }

    table[address].key = key;
    table[address].is_occupied = 1;
    snprintf(table[address].name, sizeof(table[address].name), "%s", name);
    printf("Key %d inserted at address %d.\n", key, address);
}

void search(HashTable table[], int m, int key) {
    int address = hash_function(key, m);
    int original_address = address;
    while (table[address].is_occupied) {
        if (table[address].key == key) {
            printf("Key %d found at address %d with name %s.\n", key, address, table[address].name);
            return;
        }
        address = (address + 1) % m; // Linear probing
        if (address == original_address) {
            break;
        }
    }
    printf("Key %d not found in the hash table.\n", key);
}

void display(HashTable table[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (table[i].is_occupied) {
            printf("Address %d: Key %d, Name: %s\n", i, table[i].key, table[i].name);
        } else {
            printf("Address %d: Empty\n", i);
        }
    }
}

int main() {
    int m, n;
    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    HashTable table[m];
    initialize_table(table, m);

    printf("Enter the number of employee records to insert (n): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int key;
        char name[50];
        printf("Enter key (4-digit integer) and name for employee %d: ", i + 1);
        scanf("%d %s", &key, name);
        insert(table, m, key, name);
    }

    display(table, m);

    int search_key;
    printf("\nEnter a key to search: ");
    scanf("%d", &search_key);
    search(table, m, search_key);

    return 0;
}
