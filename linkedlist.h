#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertatbeg(struct node **head, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
    return;
}
void insertatmid(struct node **head, int data, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        struct node *temp;
        temp = *head;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return;
    }
}
void insertatend(struct node **head, int data)
{
    struct node *newnode;
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (*head = NULL)
    {
        *head = newnode;
        newnode->next = NULL;
        return;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        return;
    }
}
void deleteatbeg(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        struct node *temp;
        temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
}
void deleteatend(struct node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        struct node *temp;
        temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return;
    }
}
void deleteatmid(struct node **head, int data)
{
    if (*head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    else
    {
        struct node *temp1;
        struct node *temp2;
        temp1 = *head;
        temp2 = NULL;
        while (temp1->data != data)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}
void display(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        struct node *temp;
        temp = *head;
        printf("\nList data:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return;
    }
}
struct node *search(struct node *head, int data)
{
    while (head)
    {
        if (head->data == data)
            return head;
        head = head->next;
    }
}