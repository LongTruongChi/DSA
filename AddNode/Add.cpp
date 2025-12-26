#include<stdio.h>
#include<malloc.h>
struct Node
{
     int data;
     struct Node *next;
};

struct Node *head;

void inserttop(int x) //insert at begining
{
     struct Node *newNode = (Node*)malloc(sizeof(Node));
     newNode->data = x;
     newNode->next = head;
     head = newNode;      
}

void insertbot(int y)
{
     
     struct Node *bottomNode = (Node*)malloc(sizeof(Node));
     bottomNode->data = y;
     bottomNode->next = NULL;
     if(head == NULL)
     {
          printf("No linkedlist, create new\n");
          head = bottomNode;
     }
     else
     {
          struct Node *move = head;
          while(move->next != NULL)
          {
               move = move->next;
           }
     move->next = bottomNode;
     }
     
}

void Print()
{
     struct Node *temp = head;
     while (temp != NULL)
     {
           printf("data: %d \n", temp->data);
           temp = temp->next;
     }
}   

int dem()
{
     int cong;
     struct Node *dem = head;
     while (dem != NULL)
     {
           dem = dem->next;
           cong++;
     }
     printf("So Node: %d",cong);
     return cong;
}

int main()
{
    int i,n,m;
    head = NULL;
    printf("Nhap so node: \n");
    scanf("%d",&n);
    for (i = 0; i<n; i++)
    {
        printf("Nhap gia tri: \n ");
        scanf("%d",&m);
        //inserttop(m);
        insertbot(m);
        Print();
    }
    return 0;
}
