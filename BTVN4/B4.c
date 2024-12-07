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

void appendNode(Node **head, const int data)
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

int searchIndex(Node *head, int value)
{
    Node *temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main()
{
    int n;
    Node *head = NULL;
    do
    {
        printf("Vui long nhap n (0 <= n <= 1000): ");
        scanf("%d", &n);
    } while (n < 0 || n > 1000);
    if (n == 0)
    {
        printf("Danh sach trong");
        return 1;
    }
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
        appendNode(&head, arr[i]);
    }
    int search;
    printf("Moi nhap gia tri tim kiem: ");
    scanf("%d", &search);
    int found = searchIndex(head, search);
    printf("%d", found);
    return 0;
}