#include<stdio.h>
#include<malloc.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *head;

void addNode(int x)
{
    struct node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = head;
    head = newNode; 
}


void deleteNode(int n)
{
    struct node *temp1 = head;
    if(n=1)
    {
        head = temp1->next; // fix the link and link to next node
        free(temp1); // delete node
        return;
    }
    for (int i=0;i<n-2;i++)
    {
        temp1 = temp1->next;
    }
    struct node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void Print()
{
    struct node *print = head;
    while(print != NULL)
    {
        printf("%d ", print->data);
        print = print->next;
    }
}

int main()
{
    int n;
    head = NULL;
    addNode(2);
    addNode(4);
    addNode(5);
    addNode(6);
    printf("Enter a position: \n");
    scanf("%d",&n);
    deleteNode(n);
    Print();
}