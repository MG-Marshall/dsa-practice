#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(int ch)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
}
int pop()
{
    struct node *temp = top;
    int ch = top->data;
    top = top->next;
    free(temp);
    return ch;
}
int main()
{
    char postfix[100];
    int i = 0, ans, x, y;
    printf("Enter postfix : ");
    scanf("%s", postfix);

    while (postfix[i] != '\0'){
        char ch = postfix[i];
        if(isdigit(ch))
            push(ch - '0');
        else{
            y = pop();
            x = pop();

            switch(ch){
            case '+': ans = x + y; break;
            case '-': ans = x - y; break;
            case '*': ans = x * y; break;
            case '/': ans = x / y; break;
            }
            push(ans);
        }
        i++;
    }
    printf("Result: %d\n", pop());
    return 0;
}