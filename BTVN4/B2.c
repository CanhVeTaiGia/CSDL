#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int data;
   struct Node *next;
} Node;

void printList(Node *head)
{
   Node *temp = head;
   while (temp != NULL)
   {
      printf("%d-->", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

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

int main()
{
   int n;
   Node *head = NULL;
   printf("Nhap so phan tu lien ket: ");
   scanf("%d", &n);
   if(n <= 0){
      printf("Danh sach trong");
      return 1;
   }
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      printf("Moi nhap phan tu thu %d: ", i + 1);
      scanf("%d", &arr[i]);
      insertHead(&head, arr[i]);
   }
   printList(head);
   return 0;
}