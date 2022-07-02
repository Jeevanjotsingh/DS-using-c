#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[20];
    double num;
    struct node *next;
};
void insert(struct node **h)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory is full");
        return;
    }
    else
    {
        printf("\nEnter name: ");
        fflush(stdin);
        fgets(newnode->name, 20, stdin);
        printf("\nEnter contact number: ");
        scanf("%lf", &newnode->num);
        if (*h == NULL)
        {
            newnode->next = NULL;
            *h = newnode;
        }
        else
        {
            struct node *temp = *h;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    printf("\n Press enter key: ");
    fflush(stdin);
    getchar();
    system("CLS");
}
void delete (struct node **h)
{
    char s[20];
    printf("Enter name you want to delete: ");
    fflush(stdin);
    fgets(s, 20, stdin);
    struct node *temp1, *temp2;
    temp1 = *h;
    while (temp1->next != NULL)
    {
        if (strcmp(temp1->name, s) == 0)
            break;
        else
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
    if (strcmp(temp1->name, s) != 0)
        printf("Contact not found");
    else
    {
        if (temp1 == *h)
        {
            *h = temp1->next;
            free(temp1);
        }
        else
        {
            temp2->next = temp1->next;
            free(temp1);
        }
        printf("Deleted successfully");
    }
    printf("\n Press enter key: ");
    fflush(stdin);
    getchar();
    system("CLS");
}
void display(struct node **h)
{
    if (*h == NULL)
        printf("List is empty");
    else
    {
        struct node *temp;
        temp = *h;
        while (temp != NULL)
        {
            printf("Name- %s\tContact number-%.0lf\n", temp->name, temp->num);
            temp = temp->next;
        }
    }
    printf("\n Press enter key: ");
    fflush(stdin);
    getchar();
    system("CLS");
}
void search(struct node **h)
{
    if (h == NULL)
        printf("list is empty");
    else
    {
        char n[20];
        printf("Enter name you want to search: ");
        fflush(stdin);
        fgets(n, 20, stdin);
        struct node *temp;
        temp = *h;
        while (temp->next != NULL)
        {
            if (strcmp(temp->name, n) == 0)
                break;
            else
            {
                temp = temp->next;
            }
        }
        if (strcmp(temp->name, n) != 0)
            printf("Contact not found");
        else
            printf("Contact details\nName: %s\tContact number: %.0lf", temp->name, temp->num);
    }
    printf("\n Press enter key: ");
    fflush(stdin);
    getchar();
    system("CLS");
}
void main()
{
    system("CLS");
    struct node *head = NULL;
    int num;
    printf("\t\n******Contact list******");
    while (1)
    {
        printf("\nEnter your choice: ");
        printf("\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Search\n\t5.Exit\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            insert(&head);
            break;
        case 2:
            delete (&head);
            break;
        case 3:
            display(&head);
            break;
        case 4:
            search(&head);
            break;
        case 5:
            exit(0);
        }
    }
}
