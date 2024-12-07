#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Vi tri sau khi xoa.\n");
        return;
    }
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
    Node *head = NULL;
    int n;
    printf("Moi nhap n:");
    scanf("%d", &n);
    if (n <= 0)
    {
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu: ");
        scanf("%d", &arr[i]);
        append(&head, arr[i]);
    }
    printf("Danh sach ban dau:\n");
    printList(head);
    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);
    deleteAtPosition(&head, position);
    printf("Danh sach sau khi xoa:\n");
    printList(head);

    return 0;
}
