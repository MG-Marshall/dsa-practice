#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;
void createLinkedList()
{
    int value;
    printf("Enter value to add the list : ");
    scanf("%d", &value);
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}
void insertNodeAtBeginning()
{
    int value;
    printf("Enter value to add at beginning : ");
    scanf("%d", &value);
    struct node *newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insertAnyPos()
{
    int value, pos;
    printf("Enter position to add : ");
    scanf("%d", &pos);
    printf("Enter the value : ");
    scanf("%d", &value);

    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    struct node *temp1, *temp = head;

    newnode->data = value;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp->next = newnode;
    newnode->next = temp1;
}
void deleteAtBeg()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}
void deleteAnyPos()
{
    int pos;
    printf("Enter position to delete : ");
    scanf("%d", &pos);
    struct node* temp = head, *temp1;

    int count = 1;
    while (count < pos - 1){
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
}
void deleteAtLast()
{
    struct node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void reverseList()
{
    struct node *prev = NULL;
    struct node *temp = head;
    struct node *next = NULL;

    while (temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head = prev;
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null");
}
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== LINKED LIST MENU =====\n");
        printf("1. Create / Add node at end\n");
        printf("2. Insert node at beginning\n");
        printf("3. Insert node at any position\n");
        printf("4. Delete node at beginning\n");
        printf("5. Delete node at any position\n");
        printf("6. Delete node at last\n");
        printf("7. Display list\n");
        printf("8. Reverse list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createLinkedList();
            break;
        case 2:
            insertNodeAtBeginning();
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
            display();
            break;
        case 8:
            reverseList();
            printf("List reversed successfully.\n");
            break;
        case 9:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
