#include<stdio.h>
#include<malloc.h>

struct node 
{
    int  data;
    struct node *next;
};

// void inserttop(int x)
// {
//     struct node *temp1 = (node*)malloc(sizeof(node));
//     temp1->data = x;
//     temp1->next = head;
//     head = temp1;
// }
struct node *head = NULL;

struct node *insertbot(int x, struct node *head)
{
    struct node *temp2 = (node*)malloc(sizeof(node));
    temp2->data = x;
    temp2->next = NULL;

    if( head == NULL)
    {
        head = temp2;
    }
    else
    {
        struct node* temp3 = head;
        while (temp3->next != NULL)
        {
            temp3 = temp3->next;
        }
        temp3->next = temp2;
    }
    return head;
}

void reverseReccursion(struct node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseReccursion(p->next);
    struct node *q = p->next;
    q->next= p;
    p->next = NULL;
}

void print(struct node*p)
{
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    printf(" %d", p->data);
    print(p->next);
}

void printlist(struct node *head)
{
    struct node *list = head;
    while (list != NULL)
    {
        printf(" %d", list->data);
        list = list->next;
    }
    printf("\n");
}

struct node *reverse(struct node *head)
{
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    head = insertbot(2,head);
    head = insertbot(4,head);
    head = insertbot(6,head);
    head = insertbot(8,head);
    printlist(head);
    //head = reverse(head);
    reverseReccursion(head);
    //printlist(head);
    print(head);
}