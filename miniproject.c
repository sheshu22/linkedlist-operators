#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void create();
void insertt();
void delet();
void display();
struct node
{
char name[10];
char branch[10];
int reg;
char section[10];
struct node *link;
};
struct node *first=NULL,*last=NULL,*next,*prev,*cur;
void create()
{
 cur=(struct node*)malloc(sizeof(struct node));
 printf("\nENTER THE NAME: ");
 scanf("%s",&cur->name);
 printf("\nENTER THE BRANCH: ");
 scanf("%s",&cur->branch);
 printf("\nENTER THE REGISTRATION NUMBER: ");
 scanf("%d",&cur->reg);
 printf("\nENTER THE SECTION: ");
 scanf("%s",&cur->section);
 cur->link=NULL;
 first=cur;
 last=cur;
}
void insertt()
{
 int pos,c=1;
 cur=(struct node*)malloc(sizeof(struct node));
 printf("\nENTER THE NAME: ");
 scanf("%s",&cur->name);
 printf("\nENTER THE BRANCH: ");
 scanf("%s",&cur->branch);
 printf("\nENTER THE REGISTRATION NUMBER: ");
 scanf("%d",&cur->reg);
 printf("\nENTER THE SECTION: ");
 scanf("%s",&cur->section);
 printf("\nENTER THE POSITION: ");
 scanf("%d",&pos);
 if((pos==1) &&(first!=NULL))
 {
 cur->link = first;
 first=cur;
 }
 else
 {
 next=first;
 while(c<pos)
 {
 prev=next;
 next=prev->link;
 c++;
 }
 if(prev==NULL)
 {
 printf("\nINVALID POSITION\n");
 }
 else
 {
 cur->link=prev->link;
 prev->link=cur;
 }
}
}
void delet()
{
int pos,c=1;
printf("\nENTER THE POSITION : ");
scanf("%d",&pos);
if(first==NULL)
{
printf("\nLIST IS EMPTY\n");
}
else if(pos==1 && first->link==NULL)
{
printf("\n DELETED ELEMENT IS %s\n",first->name);
free(first);
first=NULL;
}
else if(pos==1 && first->link!=NULL)
{
cur=first;
first=first->link;
cur->link=NULL;
printf("\n DELETED ELEMENT IS %s\n",cur->name);
free(cur);
}
else
{
next=first;
while(c<pos)
{
cur=next;
next=next->link;
c++;
}
cur->link=next->link;
next->link=NULL;
if(next==NULL)
{
printf("\nINVALID POSITION\n");
}
else
{
printf("\n DELETED ELEMENT IS %s\n",next->name);
free(next);
}
}
}
void display()
{
 cur=first;
 while(cur!=NULL)
{
 printf("%s",cur->name);
 printf(" ");
 printf("%s",cur->branch);
 printf(" ");
 printf("%d",cur->reg);
 printf(" ");
 printf("%s",cur->section);
 printf("\n");
 cur=cur->link;
 }
}

void search()
{
int r;
int flag=0;
printf("\nEnter the registration number u want to  search:");
scanf("%d",r);
struct node *t;
t=first;
while(t!=NULL)
{
    if(r==t->reg)
    {
        printf("\nThe roll number found in the list!!!\nHis name is %s",t->name);
        flag=1;
        break;
    }
    t=t->link;
}
if(flag==0)
printf("\nThe  number is not there");
}

void main()
{
int ch;
printf("\n\nSINGLY LINKED LIST");
do
{
printf("\n\n1.CREATE\n2.INSERT\n3.DELETE\n4.SEARCH\n5.EXIT\n");
printf("\n\nENTER YOUR CHOICE : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
display();
break;
case 2:
insertt();
display();
break;
case 3:
delet();
display();
break;
case 4:
search();
display();
case 5:
exit(0);
default:
 printf("Invalid choice...");
}
}while(1);
}

