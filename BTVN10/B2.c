#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addFirst(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void addLast(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteFirst(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteLast(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deleteAt(Node** head, int position) {
    if (*head == NULL || position < 0) return;
    Node* temp = *head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == *head) *head = temp->next;
    free(temp);
}

void displayForward(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void freeList(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* list = NULL;

    addFirst(&list, 10);
    addLast(&list, 20);
    addFirst(&list, 5);
    addLast(&list, 30);

    printf("Duyet danh sach tu dau den cuoi: ");
    displayForward(list);

    printf("Duyet danh sach tu cuoi ve dau: ");
    displayBackward(list);

    deleteFirst(&list);
    printf("Sau khi xoa node dau: ");
    displayForward(list);

    deleteLast(&list);
    printf("Sau khi xoa node cuoi: ");
    displayForward(list);

    deleteAt(&list, 1);
    printf("Sau khi xoa node o vi tri 1: ");
    displayForward(list);

    freeList(&list);
    printf("Da giai phong bo nho\n");

    return 0;
}
