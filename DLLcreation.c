#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL, *tail = NULL;

void createDLL(int value)
{
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    if(head == NULL){
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insrertAtBeg(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}
void insertAnyPos(int pos, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp1, *temp = head;
    newnode->data = value;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp1->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = temp1;

}
void deleteAtBeg()
{
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    temp = temp->next;
    temp->prev = NULL;
    head = temp;
}
void deleteAnyPos(int pos)
{
    struct Node *temp = head, *temp1;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp1 = temp1->next;
    temp1->prev = temp;
    temp->next = temp1;
}
void deleteAtLast()
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}
void display()
{
    printf("NULL <- ");
    struct Node *temp;
    temp = head;
    while(temp != NULL){
        if (temp->next != NULL)
            printf("%d <-> ", temp->data);
        else
            printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    createDLL(10);       // NULL <- 10 -> NULL
    createDLL(30);       // NULL <- 10 <-> 30 -> NULL
    createDLL(60);       // NULL <- 10 <-> 30 <-> 60 -> NULL
    insrertAtBeg(5);     // NULL <- 5 <-> 10 <-> 30 <-> 60 -> NULL
    insrertAtBeg(1);     // NULL <- 1 <-> 5 <-> 10 <-> 30 <-> 60 -> NULL
    insertAnyPos(4, 20); // NULL <- 1 <-> 5 <-> 10 <-> 20 <-> 30 <-> 60 -> NULL
    deleteAtBeg();       // NULL <- 5 <-> 10 <-> 20 <-> 30 <-> 60 -> NULL
    deleteAnyPos(4);     // NULL <- 5 <-> 10 <-> 20 <-> 60 -> NULL
    deleteAtLast();      // NULL <- 5 <-> 10 <-> 20 -> NULL
    display();           // output == NULL <- 5 <-> 10 <-> 20 -> NULL
    return 0;
}
