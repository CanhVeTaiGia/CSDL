#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = value;
    return newNode;
}

void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    int index = 0;
    while (current != NULL && index < position - 1)
    {
        current = current->next;
        index++;
    }
    if (current == NULL)
    {
        printf("Vi tri nam ngoai pham vi danh sach\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 15, 1);
    insertAtPosition(&head, 5, 0);
    printf("Danh sach lien ket: ");
    printList(head);
    insertAtPosition(&head, 25, 10);
    return 0;
}