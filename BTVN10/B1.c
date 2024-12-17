#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertHead(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node **head, int value)
{
    Node *newNode = createNode(value);
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

void deleteHead(Node **head)
{
    if (head == NULL)
    {
        printf("Danh sach lien ket rong!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void displayList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteEnd(Node **head)
{
    if (head == NULL)
    {
        printf("Danh sach lien ket rong!\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void search(Node *head, int value)
{
    if (head == NULL)
    {
        printf("Danh sach lien ket rong!\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if(temp->data == value){
            printf("%d\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay!\n");
}

void freeList(Node** head){
    while(*head != NULL){
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Node* head = NULL;
    insertHead(&head, 6);
    insertEnd(&head, 5);
    insertHead(&head, 7);
    insertEnd(&head, 9);

    printf("Danh sach lien ket: ");
    displayList(head);

    deleteHead(&head);
    printf("Sau khi xoa dau: ");
    displayList(head);

    deleteEnd(&head);
    printf("Sau khi xoa cuoi: ");
    displayList(head);

    int searchValue = 7;
    search(head, searchValue);
    freeList(&head);

    return 0;
}