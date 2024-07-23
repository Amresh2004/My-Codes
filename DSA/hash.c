#include <stdio.h>

#define max 100

int hashtable[max]; // Hash table array

void insert(int key)
{
    int index = key % max; // Calculate hash index
    int start = index;     // Store the initial index for full table check

    do
    {
        if (hashtable[index] == -1)
        {
            hashtable[index] = key; // Insert the key at the determined index
            printf("Key %d inserted at index %d\n", key, index);
            return;
        }
        index = (index + 1) % max; // Move to the next slot
    } while (index != start);

    printf("Hash table is full, cannot insert %d\n", key);
}

int search(int key)
{
    int index = key % max; // Calculate hash index
    int start = index;     // Store the initial index for full table check

    do
    {
        if (hashtable[index] == key)
        {
            return index; // Key found at this index
        }
        index = (index + 1) % max; // Move to the next slot
    } while (index != start);

    return -1; // Key not found after full table check
}

void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < max; i++)
    {
        printf("%d: ", i); // Print index
        if (hashtable[i] != -1)
        {
            printf("%d", hashtable[i]);
        }
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < max; i++)
    {
        hashtable[i] = -1;
    } // Initialize the hash table

    int choice, key;

    while (1)
    {
        printf("\nHash Table Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(key) == -1)
            {
                printf("Key %d not found\n", key);
            }
            else
            {
                printf("Key %d found\n", key);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}