#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
struct node{
    char data;
    struct node *next;
};
struct node *top = NULL;

void push(char ch)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = ch;
    newnode->next = top;
    top = newnode;
}
char pop()
{
    struct node *temp = top;
    char ch = top->data;
    top = top->next;
    free(temp);
    return ch;
}
int precedence(char ch)
{
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;
    printf("Enter infix : ");
    scanf("%s", infix);

    while(infix[i]){
        if(isalnum(infix[i])){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(top->data != '('){
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else{
            while(top != NULL && precedence(top->data) >= precedence(infix[i])){
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
        i++;
    }
    
    while (top != NULL)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix : %s", postfix);
}
