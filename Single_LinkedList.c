#include <stdio.h>
#include <stdlib.h>

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;
typedef long double        f128;

typedef struct node
{
	s32 Info;
	struct node * Link;
}Node;

Node * CreateList         (Node * Start);
void   DisplayList        (Node * Start);
s32    CountNodes         (Node * Start);
void   Search             (Node * Start,s32 x);
Node * InsertInBeginning  (Node * Start,s32 Data);
void   InsertAtEnd        (Node * Start, s32 Data);
void   InsertAfter        (Node * Start,s32 x,s32 Data);
Node * InsertBefore       (Node * Start,s32 x,s32 Data);
Node * InsertAtPosition   (Node * Start,s32 Data,s32 Pos);
Node * DeleteNode         (Node * Start,s32 Data);
Node * ReverseList        (Node * Start);

void main(void)
{
	Node * Start1 = NULL;
	Start1 = CreateList(Start1);
}


Node * CreateList         (Node * Start)
{
	s32 n,Data,i;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	
	if(0 == n)
	{
		return Start;
	}
	
	printf("Please Enter the first element to be inserted : ");
	scanf("%d",&Data);
	Start = InsertInBeginning(Start,Data);
	
	for(i = 2; i<= n ;i++)
	{
		printf("Please Enter the next element to be inserted : ");
		scanf("%d",&Data);
		InsertAtEnd(Start,Data);
	}
	return Start;
}

Node * InsertInBeginning  (Node * Start,s32 Data)
{
	/* Create Node */
	Node * temp = (Node *)malloc(sizeof(Node));
	if(temp != NULL)
	{
		temp->Info = Data;
		temp->Link = Start;
		Start      = temp;
	}
	return Start;
}
void   InsertAtEnd        (Node * Start, s32 Data)
{
	Node * p ;
	/* Create Node */
	Node * temp = (Node *)malloc(sizeof(Node));
	if(temp != NULL)
	{
		temp->Info = Data;
		
		p = Start;
		while(p->Link != NULL)
		{
			p = p->Link;
		}
		/* Insert Node At the end */
		p   ->Link = temp;
		temp->Link = NULL;
	}
}
void   InsertAfter        (Node * Start,s32 x,s32 Data)
{
	Node * temp,*p;
	p = Start;
	
	while(p!=NULL)
	{
		if(p->info == x)
		{ break; }
		p = p->Link;
	}
	if(p == NULL)
	{
		printf("The value %d is not in the List \n",x);
	}
	else
	{
		temp        = (Node *)malloc(sizeof(Node));
		temp->info  = Data;
		temp->Link  = p->Link;
		p->Link     = temp;
	}
}
Node * InsertBefore       (Node * Start,s32 x,s32 Data)
{
	Node * temp,*p;
	if(Start == NULL)
	{
		printf("List is empty\n");
		return Start;
	}
	/* if x is in the first node, insert node at the beginning of the list */
	if(Start->Info == x)
	{
		Start = InsertInBeginning(Start,Data);
		return Start;
	}
	/* Find pointer to predecessor of the node containing x */
	p = Start;
	while(P->Link != NULL)
	{
		if(p->Link->Info == x)
		{
			break;
		}
		p = p->Link;
	}
	if(p->Link == NULL)
	{
		printf("The Value %d is not in the List\n",x);
	}
	else
	{
		temp       = (Node*)malloc(sizeof(Node));
		temp->Info = Data;
		temp->Link = p->Link;
		p->Link    = temp;
	}
	return Start;
}
Node * InsertAtPosition   (Node * Start,s32 Data,s32 Pos)
{
	Node * temp, *p;
	s32 i;
	if(Pos == 1)/* Insert At the beginning */
	{
		Start = InsertInBeginning(Start,Data);
		return Start;
	}
	p = Start;
	for(i = 1;(i<pos-1) && (p!=NULL);i++)
	{
		p = p->Link;
	}
	if(p == NULL)
	{
		printf("You can insert only upto %d th position \n",i);
	}
	else
	{
		temp       = (Node *)malloc(sizeof(Node));
		temp->Info = Data;
		temp->Link = p->Link;
		p->Link    = temp;
	}
	return Start;
}
void   DisplayList        (Node * Start)
{
	Node * p;
	if(Start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("List is : ");
	p = Start;
	while(p!=NULL)
	{
		printf("%d ",p->Info);
		p = p->Link;
	}
	printf("\n");
}
s32    CountNodes         (Node * Start)
{
	s32 counter=0;
	Node * p = Start;
	while(p!=NULL)
	{
		counter++;
		p=p->Link;
	}
	printf("Number of nodes in the List = %d\n",counter);
	return counter;
}

void   Search             (Node * Start,s32 x)
{
	Node * p;
	s32 counter=0;
	/*if(Start == NULL)
	{
		printf("List is empty\n");
		return;
	}*/
	p = start;
	while((p!=NULL) &&(p->Info != x))
	{
		counter++;
		p=p->Link;
	}
	if(p == NULL)
	{
		printf("The value %d is not at the List\n",x);
	}
	else
	{
		printf("The value %d is at %d th position at the List",x,counter);
	}
}

Node * DeleteNode         (Node * Start,s32 Data)
{
	Node * temp,*p;
	if(Start == NULL)/* List is empty */
	{
		printf("List is empty \n");
		return Start;
	}
	/* Delete the first Node at the List */
	if(Start->Info == Data)
	{
		temp  = Start;
		Start = Start->Link;
		free(temp);
		return Start;
	}
	/* Delete in between the Nodes or at the end */
	p = Start;
	while(p->Link != NULL)
	{
		if(p->Link->Info == Data)
		{
			temp = p->Link;
			break;
		}
		p = p->Link;
	}
	if(p->Link == NULL)
	{
		printf("Element of the value %d is not in the List\n",Data);
	}
	else
	{
		p->Link = temp -> Link;
		free(temp);
	}
	return Start;
}
Node * ReverseList        (Node * Start)
{
	Node * prev,*ptr,*next;
	prev = NULL;
	ptr  = Start;
	while(ptr != NULL)
	{
		next      = ptr->Link;
		ptr->Link = prev;
		prev      = ptr;
		ptr       = next;
	}
	Start = prev;
	
	return Start;
}