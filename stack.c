#include <stdio.h>
#include<stdlib.h>
int arr[100], top = -1, n;
void push();
void pop();
void peek();
void Display();
int isfull();
int isempty();
void main()
{
    int choice;
    printf("Enter the size of stack: ");
    scanf("%d", &n);
    while (1)
    {
        printf("\t\n---------------------Stack Menu----------------------\n");
        printf("Enter your choice:\n");
        printf("1.Push\n2.pop\n3.peek\n4.Display\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            exit (0);
        default:
            printf("\tPlease enter a valid choice\n");
        }
    }
    return;
}
void push()
{
    int var, n;
    n = isfull();
    if (n == 1)
        printf("Overflow");
    else
    {
        printf("Enter your element: ");
        scanf("%d", &var);
        top++;
        arr[top] = var;
    }
    return;
}
void pop()
{
    int n = isempty();
    if (n == 1)
        printf("Underflow");
    else
    {
        printf("deleted element: %d", arr[top]);
        top--;
    }
    return;
}
void peek()
{
    printf("Top data element in the stack is: %d", arr[top]);
    return;
}
void Display()
{
    printf("elememts in the stack are: ");
    for (int i = top; i >= 0; i--)
        printf(" %d", arr[i]);
    return;
}
int isfull()
{
    if (top == n-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
