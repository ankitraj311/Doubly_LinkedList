#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *prev;
  int data;
  struct node *next;
};


void insertStart(struct node **s, int data);
void insertLast(struct node **s, int data);
struct node *find(struct node **s, int data);
void insertafter(struct node **s, struct node *ptr, int data);
int deletionfirst(struct node **s);
int deletionlast(struct node **s);
int deleteIntermediate(struct node **s, struct node *ptr);
void viewList(struct node **s);
int getFirst(struct node **s);
int getLast(struct node **s);

int main()
{
  struct node *start = NULL ;
  struct node *ptr;
  insertStart(&start,10);
  insertLast(&start,20);
  ptr = find(&start,10);
  insertafter(&start,ptr,30);
  printf("First value id %d\n",getFirst(&start));
  printf("Last  value id %d\n",getLast(&start));
  deleteIntermediate(&start,find(&start,30));
  deletionfirst(&start);
  viewList(&start);

}

void viewList(struct node **s)
{
  struct node *t;
  if(*s == NULL)
    printf("List is Empty");
  else
  {
    t = *s;
    while(t != NULL)
    {
      printf("%d ",t->data);
      t = t->next;
    }
  }
}

int getFirst(struct node **s)
{
  struct node *t;
  if(*s == NULL)
  {
    printf("List is Empty");
    return -1;
  }
  else
  {
   return((*s)->data);
  }
}

int getLast(struct node **s)
{
  struct node *t;
  if(*s == NULL)
  {
    printf("List is Empty");
    return -1;
  }
  else
  {
    t = *s;
    while(t->next != NULL)
    {
      t = t->next;
    }
    return ((t)->data);
  }
}

void insertStart(struct node **s, int data)
{
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  p->data = data;
  p->prev = NULL;
  p->next = *s;
  *s = p;
  /*
  if(*s == NULL)
  {
    *s = p;//
    p->next = NULL; //
  }
  else
  {
    *s = p;//
     p->prev = *s; //
  }*/
}

void insertLast(struct node **s, int data)
{
  struct node *p,*t;
  p = (struct node *)malloc(sizeof(struct node));
  p->data = data;
  p->next = NULL;
  if(*s == NULL)
  {
    p->prev = NULL;
    *s = p;
  }
  else
  {
    t = *s;
    while(t->next != NULL)
    {
      t = t->next;
    }
    t->next = p;
     p->prev = t;
  }
}

struct node *find(struct node **s, int data)
{
  struct node *t;
  if(*s == NULL)
  {
    return  NULL;
  }
  else
  {
    t  = *s;
    while(t != NULL)
    {
      if(t->data == data)
      {
        return t;
      }
      t = t->next;
    }
    return NULL;
  }

}
void insertafter(struct node **s, struct node *ptr, int data)
{
  struct node *p;
  if(ptr == NULL)
  {
    printf("Insertion is Not Possible");
  }
  else
  {
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->prev = ptr; 
    p->next = ptr->next;
    if(ptr->next != NULL) //Checking Next node exist or Not
    {
      ptr->next->prev = p;
    }
    ptr->next = p;
  }
}

int deletionfirst(struct node **s)
{
  struct node *t;
  t = *s;
  if(*s == NULL)
  {
    printf("No  Linked List Exist");
  }
  else
  {
    //*s->next->prev = NULL;
   // *s = *s->next;
     *s = (*s)->next;
     (*s)->prev = NULL; 
     free(t);
  }
  return 0;
}

int deletionlast(struct node **s)
{
  struct node *t,*last;
  t = *s;
  if(*s == NULL)
  {
    printf("No Value Exist");
  }
  else
  {
    while(t->next != NULL)
    {
      //last = t;
      t = t->next;
    }
    if((*s)->next==NULL)
    {
      *s = NULL;
    }
    else
    {
      (*s)->prev->next = NULL;
    }
    free(t);
  }
}

/*
void deletioIntermediate(struct node **s)
{
  struct node *t, *last;
  int pos = 0, count = 0, i = 1;
  printf("Enter Position of Node\n");
  scanf("%d",&pos);
  t = *s;
  while(t != NULL)
  {
    count++;
  }
  if(pos>count)
  {
    printf("Deletion is Not Possible\n");
  }
  else
  { 
    while(i != pos)
    {
      last = t;
      t = t->next;
      i++;
    }
    t->prev->next = t->next;
    t->next->pre = t->prev;
    free(t);
  }
}*/


int deleteIntermediate(struct node **s, struct node *ptr)
{
  if(*s==NULL) //If Start is ZERO no NODE
  {
    return 0;
  }

  if(ptr->prev == NULL) //IF ptr is the only node
  {
    *s = ptr->next;
    free(ptr);
    return 1;
  }

  if(ptr->next == NULL) //IF ptr is  the last node
  {
    ptr->prev->next = ptr->next;
    free(ptr);
    return 1;
  }
  ptr->prev->next = ptr->next;
  ptr->next->prev = ptr->prev;
  free(ptr);
  return 1;
}
