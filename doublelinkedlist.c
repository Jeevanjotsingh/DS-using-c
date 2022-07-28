#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;
void insert_beg(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        tail = newnode;
        head = newnode;
        return;
    }
    else
    {
        newnode->next = head;
        newnode->prev = NULL;
        head->prev = newnode;
        head = newnode;
        return;
    }
}
void insert_end(int data)
{
    if (head == NULL)
    {
        insert_beg(data);
        return;
    }
    else
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        return;
    }
}
void insert_specific(int data, int pos)
{
    if (head == NULL)
    {
        printf("\nUnderflow\n");
        return;
    }
    else if (pos == 1)
    {
        insert_beg(data);
        return;
    }
    else
    {
        struct node *newnode;
        struct node *temp;
        struct node *temp1;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        temp = head;
        for (int i = 2; i < pos; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp1->prev = newnode;
        return;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        struct node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return;
    }
}
void delete_beg()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
}
void delete_end()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        struct node *temp;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}
void delete_specific(int data)
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        struct node *temp;
        struct node *temp1;
        struct node *temp2;
        temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == NULL)
        {
            printf("Data not found\n");
        }
        else if (temp == head)
        {
            delete_beg();
        }
        else if (temp == tail)
        {
            delete_end();
        }
        else
        {
            temp1 = temp->prev;
            temp2 = temp->next;
            temp1->next = temp->next;
            temp2->prev = temp1;
            free(temp);
        }
    }
}