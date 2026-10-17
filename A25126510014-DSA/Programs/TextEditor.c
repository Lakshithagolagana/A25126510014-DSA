
#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 200

char stack[MAX][SIZE];
int top = -1;

void addText()
{
    if(top == MAX - 1)
    {
        printf("Text history is full!\n");
        return;
    }

    printf("Enter text: ");
    scanf(" %199[^\n]", stack[++top]);

    printf("Text added successfully!\n");
}

void undo()
{
    if(top == -1)
    {
        printf("Nothing to undo!\n");
        return;
    }

    printf("Undoing: \"%s\"\n", stack[top]);
    top--;

    printf("Last entry removed successfully!\n");
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("\n----- YOUR DOCUMENT -----\n");

    for(i = 0; i <= top; i++)
        printf("%s ", stack[i]);

    printf("\n-------------------------\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== MINI TEXT EDITOR =====\n");
        printf("1. Add Text\n");
        printf("2. Undo Last Entry\n");
        printf("3. View Document\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addText();
                break;

            case 2:
                undo();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Text Editor...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
