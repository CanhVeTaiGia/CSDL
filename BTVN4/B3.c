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

void printList(Node *head)
{
   Node *temp = head;
   while (temp != NULL)
   {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

void insertElement(Node **head, int value)
{
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteHead(Node** head)
{
   if (head == NULL)
   {
      printf("Danh sach trong\n");
      return;
   }
   Node *temp = *head;
   *head = (*head)->next;
   free(temp);
}

int main()
{
   int n;
   Node *head = NULL;
   printf("Moi nhap so luong lien ket: ");
   scanf("%d", &n);
   if (n <= 0)
   {
      printf("Danh sach trong");
      return 1;
   }
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      printf("Moi nhap phan tu thu: ", i + 1);
      scanf("%d", &arr[i]);
      insertElement(&head, arr[i]);
   }
   printf("Danh sach truoc khi xoa:\n");
   printList(head);
   deleteHead(&head);
   printf("Danh sach sau khi xoa: \n");
   printList(head);
   return 0;
}