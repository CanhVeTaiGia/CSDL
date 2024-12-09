#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void appendNode(Node **head, int data)
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
    newNode->prev = temp;
}

void printReverse(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng.\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Duyet danh sach nguoc: \nNULL ");
    while (temp != NULL)
    {
        printf("<-> %d <->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int n;
    Node *head = NULL;
    do
    {
        printf("Vui long nhap so luong: ");
        scanf("%d", &n);
    } while (n <= 0);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        appendNode(&head, arr[i]);
    }

    printReverse(head);

    freeList(head);

    return 0;
}