#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

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

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
}

int findMax(struct Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return -1;
    }

    int max = head->data;
    struct Node *current = head->next;

    while (current != NULL)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->next;
    }

    return max;
}

int main()
{
    Node *head = NULL;
    int n;
    printf("Moi nhap n (n > 0): ");
    scanf("%d", &n);
    if (n <= 0)
        return 1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
        append(&head, arr[i]);
    }
    printf("Danh sach lien ket: ");
    printList(head);
    int max = findMax(head);
    if (max != -1)
    {
        printf("Phan tu lon nhat trong danh sach: %d\n", max);
    }
    return 0;
}