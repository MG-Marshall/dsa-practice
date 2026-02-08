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
    createDLL(10);
    createDLL(30);
    createDLL(60);
    display();
    return 0;
}