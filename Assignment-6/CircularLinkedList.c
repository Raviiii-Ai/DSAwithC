#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the node data?");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nnode inserted\n");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nnode inserted\n");
    }
}
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode deleted\n");
    }
}
void last_delete()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;

            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        printf("\nNothing to print ");
    }
    else
    {
        printf("\nPrinting values: ");
        while (ptr->next != head)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}
int main()
{
    int choice = 0;
    while (1)
    {
        printf("\nChoose one option from the following list...\n");
        printf("\nl.Insert in begining:\n");
        printf("2.Insert at last:\n");
        printf("3.Delete from Beginning:\n");
        printf("4.Delete from last:\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice); 
        switch (choice)
        {
        case 1:
            beginsert();
            display();
            break;
        case 2:
            lastinsert();
            display();
            break;
        case 3:
            begin_delete();
            display();
            break;
        case 4:
            last_delete();
            display();
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}