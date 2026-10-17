
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char song[100];
    struct Node *next;
};

struct Node *head = NULL;

void addSong()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter song name: ");
    scanf(" %99[^\n]", newNode->song);

    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Song added successfully!\n");
}

void deleteSong()
{
    struct Node *temp = head, *prev = NULL;
    char name[100];

    printf("Enter song to delete: ");
    scanf(" %99[^\n]", name);

    while(temp != NULL &&
          strcmp(temp->song, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Song not found!\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Song deleted successfully!\n");
}

void searchSong()
{
    struct Node *temp = head;
    char name[100];
    int position = 1;

    printf("Enter song to search: ");
    scanf(" %99[^\n]", name);

    while(temp != NULL)
    {
        if(strcmp(temp->song, name) == 0)
        {
            printf("Song found at position %d\n",
                   position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Song not found!\n");
}

void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\n----- YOUR PLAYLIST -----\n");

    while(temp != NULL)
    {
        printf("%s\n", temp->song);
        temp = temp->next;
    }

    printf("-------------------------\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== MUSIC PLAYLIST =====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display Playlist\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: searchSong(); break;
            case 4: display(); break;
            case 5:
                printf("Exiting Playlist...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
