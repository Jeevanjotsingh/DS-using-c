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
        printf("\nUnderflow\n");
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
        printf("\nUnderflow\n");
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
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        struct node *temp1;
        struct node *temp2;
        temp1 = *head;
        temp2 = NULL;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        if (temp2 == NULL)
        {
            *head = NULL;
            free(temp1);
            return;
        }
        else
        {
            temp2->next = NULL;
            free(temp1);
            return;
        }
    }
}
void deleteatmid(struct node **head, int data)
{
    struct node *t;
    struct node *r;
    t = search(*head, data);
    if (t == NULL)
    {
        printf("\nElement not found\n");
        return;
    }
    else
    {
        if (*head == t)
        {
            deleteatbeg(head);
        }
        else
        {
            r = *head;
            while (r->next != t)
            {
                r = r->next;
            }
            r->next = t->next;
            free(t);
        }
    }
}
void display(struct node **head)
{
    if (*head == NULL)
    {
        printf("Underflow\n");
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
