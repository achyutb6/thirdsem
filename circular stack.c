/********************************************//**
 * \Problem : Implement stacks using circular lists.
 *
 * \By:	Achyut Bhandiwad
 * \Rollno: 07
 * \DateOfSubmission : 7/10/2015
 *
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0

struct node
{
    int info;
    struct node *next;
};
typedef struct node *nodeptr;

/**< Function to get a node from dynamic memory
 *Type -Struct node pointer*/

nodeptr getnode()
{

    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct node));
    return p;
}

/**< Function to free the node which is sent as parameter */

void freenode(nodeptr p)
{
    free(p);
}

/**< Function to check whether the stack is empty or not */

int isfull(nodeptr p)
{
    if((nodeptr)malloc(sizeof(struct node))==NULL)
       return 1;
   else
        return 0;
}

int empty(nodeptr pstack)
{
    return ((pstack==NULL)?TRUE:FALSE);
}

/**< Function to push an element x into the stack*/


nodeptr push(nodeptr pstack,int  x)
{
    nodeptr p;
    if(isfull(pstack)==1)
    {
        printf("Stack Full\n");
    }
    else
    {
        p=getnode();                          //Create a new node to be inserted
        p->info=x;
        if(empty(pstack)==TRUE)
        pstack=p;                          //make p as the first node
        else
        p->next=(pstack)->next;             //Insert at the front end
        pstack->next=p;                         //Link last node to first node
    }
    return pstack;
}

/**< Function to pop an element from the stack*/

nodeptr pop(nodeptr pstack,int *px)
{

    nodeptr p;
    if(empty(pstack)==TRUE){                //Check for empty list
        printf("Stack underflow\n");
        exit(1);
    }
    p=pstack->next;
    *px=p->info;
    if(p==pstack)                           //Pop if only one node
        pstack=NULL;
    else
        (pstack)->next=p->next;             //if list contains more than one node
    freenode(p);
    return pstack;
}

/**< Function to display the elements of the stack*/

void display(nodeptr pstack)
{
    nodeptr p;
    if(empty(pstack)==TRUE)                 //Check if list is empty
    {
        printf("Stack empty\n");
        return;
    }

    for(p=pstack->next;p!=pstack;p=p->next)     //Display till we get last node
    {
        printf("%d\t",p->info);
    }
    printf("%d\n",p->info);                     //Display Last node
}
 /**< Main Function */
int main()
{
    nodeptr pstack;
    int c,x,y;
    pstack=NULL;            //Initializing the list to NULL

    while(1)
    {
        printf("What do you want to do?\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the element which you want to push in the stack\n");
                   scanf("%d",&x);
                   pstack=push(pstack,x);
                   printf("\nPress any key to continue...\n");
                   getch();
                   break;
            case 2:pstack=pop(pstack,&y);
                   printf("Popped element is:\t%d\n",y);
                   printf("\nPress any key to continue...\n");
                   getch();
                   break;
            case 3:printf("Elements of stack are\n");
                   display(pstack);
                   printf("\nPress any key to continue...\n");
                   getch();
                   break;
            case 4:exit(1);

            default:printf("Invalid Choice!\n");
        }//End of switch
    }//End of while
}//End of main
