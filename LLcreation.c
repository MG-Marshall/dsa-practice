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
void insertNodeAtBeginning(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insertAnyPos(int pos, int value){
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
    head = head->next;
}
void deleteAnyPos(int pos)
{
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
int main(){
    createLinkedList(10);
    createLinkedList(20);
    createLinkedList(35);
    createLinkedList(50);
    insertNodeAtBeginning(5);
    insertNodeAtBeginning(1);
    insertAnyPos(6, 45);
    deleteAtBeg();
    deleteAtBeg();
    deleteAnyPos(4);
    deleteAtLast();
    display();
}
