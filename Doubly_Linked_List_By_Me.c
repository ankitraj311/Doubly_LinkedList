#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *prev;
  int data;
  struct node *next;



}*START = NULL, *START_COPY = NULL;



void create();
void display(struct node*);
void rdisplay(struct node*);
//void display(struct node*);
//void finsertion(struct node*);
//void fdelete(struct node*);
void einsertion(struct node*);
//void edelete();

int main()
{
  struct node *opposite, *opposite2;
  create();
  rdisplay(START);
  //finsertion(START);
  //display(START);
  //fdelete(START);
  //edelete(START);
  einsertion(START);
  display(START);
  rdisplay(START);
}

void create()
{
  char c;
  do
  {
    struct node *temp, *prev_add;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of Node Data");
    scanf("%d",&temp->data);
    temp->prev = NULL;
    temp->next = NULL;
    if(START == NULL)
    {
      START = temp;
      START_COPY = temp;
      prev_add = temp;

    }
    else
    {
      START_COPY->next = temp;
      temp->prev = START_COPY;    
      START_COPY = temp; 
    }
    printf("\nEnter y for yes\n");
    scanf(" %c",&c);
  }while(c == 'y' || c == 'Y');

}

void display(struct node *temp)
{
  struct node *last;
  while(temp != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("null\n");
}


void rdisplay(struct node *temp)
{
  struct node *last;

  while(temp != NULL)
  {
    last = temp;
    temp = temp->next;
  }
  if(temp == NULL)
  { 
    temp = last;
    while(temp != NULL)
    {
      printf("%d->",temp->data);
      temp = temp->prev;
    }
  }
  
  printf("null\n");
}


void finsertion(struct node* temp)
{
  struct node *new, *new1;
  printf("Enter new value of Data\n");
  new = (struct node *)malloc(sizeof(struct node));
  scanf("%d",&new->data);
  new1 = START;
  START = new;
  new->prev = NULL;
  new->next = new1;
}

void fdelete(struct node* temp)
{
  START = temp->next;
  START->prev = NULL;
}

void edelete(struct node *temp)
{
  struct node *last;
  while(temp->next != NULL)
  {
   // last = temp;
    temp = temp->next;
  }
  last = temp->prev;
  last->next = NULL;
}

void einsertion(struct node* temp)
{
  struct node *new, *new1;
  printf("Enter new value of Data\n");
  new = (struct node *)malloc(sizeof(struct node));
  scanf("%d",&new->data);

  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  printf("\nValue of Temp is %d",temp->data);
  temp->next = new;
  new->next = NULL;
}


