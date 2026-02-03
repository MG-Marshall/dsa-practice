#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;
void createLinkedList(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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
void insertNodeAtBeginning(value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void deleteAtBeg()
{
    head = head->next;
}
void deleteAtLast()
{
    struct node* temp = head;
    while(temp->next != tail){
        temp = tepm->next;
    }
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
    createLinkedList(10);
    createLinkedList(20);
    createLinkedList(35);
    createLinkedList(50);
    insertNodeAtBeginning(5);
    insertNodeAtBeginning(1);
    deleteAtBeg();
    deleteAtBeg();
    display();
}
