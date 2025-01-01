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

void display(Node *head)
{
    printf("linked list: ");
    while (head->next != NULL)
    {
        printf("%d -> ", head->data);
    }
    printf("NULL\n");
}

void append(Node **head, int data)
{
    Node *newNode = createNode(newNode);
    newNode->next = *head;
    *head = newNode;
}

void push(Node **head, int data)
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

void delete(Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }

    Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        printf("Node at position %d deleted.\n", pos);
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Khong tim thay %d trong danh sach.\n", pos);
        return;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Xoa thanh cong.\n");
}

void edit(Node *head, int pos, int data)
{
    Node *temp = head;
    for (int i = 0; temp != NULL && i < pos; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Vi tri %d khong tim thay trong danh sach.\n", pos);
        return;
    }
    temp->data = data;
    printf("Node o vi tri %d duoc cap nhat thanh %d.\n", pos, data);
}


int main()
{  
    int value, pos, choice;
    Node* head = NULL;
    do
    {
        printf("----- Menu -----\n");
        printf("0. Thoat\n");
        printf("1. Hien thi danh sach\n");
        printf("2. Them vao dau\n");
        printf("3. Them vao cuoi\n");
        printf("4. Xoa node\n");
        printf("5. Sua node\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("Nhap gia tri can them vao dau: ");
            scanf("%d", &value);
            append(&head, value);
            break;
        case 3:
            printf("Nhap gia tri can them vao cuoi: ");
            scanf("%d", &value);
            push(&head, value);
            break;
        case 4:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &pos);
            delete(&head, pos);
            break;
        case 5:
            printf("Nhap vi tri can sua: ");
            scanf("%d", &pos);
            printf("Nhap gia tri moi: ");
            scanf("%d", &value);
            edit(head, pos, value);
            break;
        default:
            printf("Lua chon khong hop le. Thu lai.\n");
        }
    } while (choice != 0);
    
    return 0;
}