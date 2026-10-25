#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;

void insert_front()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
    {
        head = last = newnode;
    }
    else
    {
        head->prev = newnode;
        head = newnode;
    }

    printf("Node inserted at front.\n");
}

void insert_end()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = last;

    if (head == NULL)
    {
        head = last = newnode;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

void delete_position()
{
    struct node *temp;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp == head)
    {
        head = head->next;
    }
    else
    {
        temp->prev->next = temp->next;
    }

    if (temp == last)
    {
        last = temp->prev;
    }
    else
    {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully.\n");
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete from specified position\n");
        printf("3. Insert at end\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_front();
                break;

            case 2:
                delete_position();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}