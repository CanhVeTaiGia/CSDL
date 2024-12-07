#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} Node;

void append(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
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

void reverseList(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    struct Node *head = NULL;
    int n;
    printf("Moi nhap n (n > 0): ");
    if (n <= 0)
    {
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d", i + 1);
        scanf("%d", &arr[i]);
        append(&head, arr[i]);
    }
    printf("Danh sach ban dau:\n");
    printList(head);
    reverseList(&head);
    printf("Danh sach sau khi dao nguoc:\n");
    printList(head);

    return 0;
}
