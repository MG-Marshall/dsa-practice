#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

void createDLL()
{
    int value;
    printf("Enter data to add end: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtBeg()
{
    int value;
    printf("Enter data to insert at beginning: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;
}
void insertAnyPos()
{
    int pos, value;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data to insert: ");
    scanf("%d", &value);

    if (pos == 1){
        insertAtBeg();
        return;
    }
    struct Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    if (temp == NULL){
        printf("Invalid position!\n");
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode; 
    temp->next = newNode;
}
void deleteAtBeg()
{
    if (head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}
void deleteAnyPos()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL){
        printf("List is empty!\n");
        return;
    }
    if (pos == 1){
        deleteAtBeg();
        return;
    }
    struct Node *temp = head;
    int count = 1;
    while (count < pos && temp != NULL){
        temp = temp->next;
        count++;
    }
    if (temp == NULL){
        printf("Invalid position!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}
void deleteAtLast()
{
    if (tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = tail;
    tail = tail->prev;

    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;

    free(temp);
}
void reverseList()
{
    if (head == NULL)
        return;
    struct Node *current = head;
    struct Node *temp = NULL;
    tail = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("NULL <- ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("**********MENU**********\n");
        printf("1. Add data at the end\n");
        printf("2. Insert New Node at beginning\n");
        printf("3. Insert New Node at any position\n");
        printf("4. Delete Node from beginning\n");
        printf("5. Delete Node from any position\n");
        printf("6. Delete Node from last position\n");
        printf("7. Reverse Linked List\n");
        printf("8. display\n");
        printf("9. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createDLL();
            break;
        case 2:
            insertAtBeg();
            break;
        case 3:
            insertAnyPos();
            break;
        case 4:
            deleteAtBeg();
            break;
        case 5:
            deleteAnyPos();
            break;
        case 6:
            deleteAtLast();
            break;
        case 7:
            reverseList();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid Choice!!! Try Again...\n");
        }
    }
}
