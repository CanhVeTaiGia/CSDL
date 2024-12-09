#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
};
typedef struct Node *node;
node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}
void delEvenNumberOfNode(node *head)
{
    node temp = *head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            node toDelete = temp;

            // Nếu là nút đầu
            if (temp->pre == NULL)
            {
                *head = temp->next;
                if (*head != NULL)
                {
                    (*head)->pre = NULL;
                }
            }
            // Nếu là nút cuối
            else if (temp->next == NULL)
            {
                temp->pre->next = NULL;
            }
            // Nếu là nút giữa
            else
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
            }
            temp = temp->next;
            free(toDelete);
        }
        else
        {
            temp = temp->next;
        }
    }
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Danh sach trong");
        return 0;
    }
    node head = NULL;
    node tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        node newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }
    delEvenNumberOfNode(&head);
    printf("Danh sach lien ket vua nhap: ");
    node currentNode = head;
    if (currentNode == NULL)
    {
        printf("Danh sach ko con phan tu nao");
    }

    while (currentNode != NULL)
    {
        printf("%d", currentNode->data);
        if (currentNode->next != NULL)
        {
            printf(" <-> ");
        }
        currentNode = currentNode->next;
    }
    printf(" <-> NULL\n");

    currentNode = head;
    while (currentNode != NULL)
    {
        node temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}