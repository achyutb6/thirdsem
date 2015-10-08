/** Problem Statement:
*Implement  the following singly linked list operations. Each node to contain the data ( BookName, Author, AccessNo, No.of Copies, Price):
*a.insert at a given position( position is a number)
*b.delete the node containing access number
*c.search the list based on Author
*d.count the total number of books available  in library
*e.display the number of unique books available in library
*f.display the list of books available in library
*g.display the books in reverse order
*h.modify the data of a book selected by access number
*i.Display the costliest book
*j.Display the cheapest book
=================================================================
*Program by: Achyut Bhandiwad
*Date of Submission 7-10-2015 */
/**< ============================================================= */

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

#define BSIZE 50

/**< ============================================================= */

struct book{
char bookName[BSIZE];
char author[BSIZE];
int AccessNo;
int NoOfCopies;
int price;
};
struct node
{
    struct book info;
    struct node *next;
};
/**< ============================================================= */
typedef struct node *nodeptr;
void displayBook(struct book);


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

/**< Function to inset an element(book) after the specified node */

void insertAfter(nodeptr p,struct book x)
{
    nodeptr q;
    if(p==NULL)
    {
        printf("Void Insertion\n");
        exit(1);
    }
    q=getnode();
    q->info=x;
    q->next=p->next;
    p->next=q;
}

/**< Function to delete the node after specified node */
void deleteAfter(nodeptr p,struct book *px)
{
    nodeptr q;
    if((p==NULL)||(p->next==NULL))      //to check if list is empty
    {
        printf("Void Deletion \n");
        exit(1);
    }
    q=p->next;
    *px=q->info;                        //save the value temporarily
    p->next=q->next;
    freenode(q);                        //free the node
}

/**< Function to display all the elements of the list */

void displayList(nodeptr list)
{
    nodeptr p;
    for(p=list;p!=NULL;p=p->next)       //iterate till the end of list
    {
        displayBook(p->info);
        /*printf("Book Name: %s\n",p->info.bookName);
    printf("Author: %s\n",p->info.author);
    printf("Access Number: %d\n",p->info.AccessNo);
    printf("No Of Copies: %d\n",p->info.NoOfCopies);
    printf("Price: %d\n\n",p->info.price);*/
    }
    printf("\n");
}

/**< Function to print only the given book */

void displayBook(struct book b)
{
    printf("\n================================================\n");
    printf("Book Name: %s\n",b.bookName);
    printf("Author: %s\n",b.author);
    printf("Access Number: %d\n",b.AccessNo);
    printf("No Of Copies: %d\n",b.NoOfCopies);
    printf("Price: %d\n",b.price);
    printf("\n================================================\n");
}

/**< Function to search for a book given the author name */

void searchList(nodeptr list,char key[BSIZE])
{
    nodeptr p;
    for(p=list;p!=NULL;p=p->next)
    {
        if(strcmp(p->info.author,key)==0)                     //if search is successful
        {
            printf("Book written by this author is:\n");        //display the found book
            displayBook(p->info);
        }
    }
}

/**< function to count the number of books in library */

int counter(nodeptr list)
{
    nodeptr p;
    int count=0;
    for(p=list;p!=NULL;p=p->next)
        count++;
    return count;
}

/**< Function to reverse the current list */

nodeptr reverse(nodeptr list)
{
    nodeptr middle,trail;
    middle=NULL;                 //Initial reversed list
    while(list!=NULL)
    {
        trail=middle;         //Hold part of list not yet reversed
        middle=list;
        list=list->next;
        middle->next=trail;
    }
    displayList(middle);             //contains address of the reversed list
    return middle;
}

/**< Function to modify elements of the current list */

void modify(nodeptr list,int num)
{
    nodeptr p;
    int i;
    for(p=list;p!=NULL;p=p->next)
    {
        if(num==p->info.AccessNo)       //search for the access number
        {
            printf("What do you want to modify?\n1.Book Name\n2.Author name\n3.Access Number\n4.No of copies\n5.Price\n");
            scanf("%d",&i);
            switch(i)
            {
            case 1:printf("New Book name is:\n");
                    gets(p->info.bookName);
                break;
                case 2:
                printf("New Author name is:\n");
                gets(p->info.author);
                break;
                case 3:
                    printf("New Access Number is:\n");
                    scanf("%d",&p->info.AccessNo);
                    break;
                case 4:
                    printf("New No of copies is:\n");
                    scanf("%d",&p->info.NoOfCopies);
                    break;
                case 5:
                    printf("New Price is:\n");
                    scanf("%d",&p->info.price);
            }
        }
    }
}

/**< Function to Display the book with highest price */

void costliest(nodeptr list)
{
    nodeptr pos,p;
    int m=list->info.price;
    for(p=list;p!=NULL;p=p->next)
    {
        if(m>=p->info.price)
        {
            m=p->info.price;
            pos=p;
        }
    }
    displayBook(pos->info);     //Display the costliest book
}

/**< Function to display the book with lowest price  */

void cheapest(nodeptr list)
{
    nodeptr pos,p;
    int m=list->info.price;
    for(p=list;p!=NULL;p=p->next)
    {
        if(m<=p->info.price)
        {
            m=p->info.price;
            pos=p;
        }
    }
    displayBook(pos->info);         //Display the cheapest book
}

/**< Function to insert element at the front of list */

/*nodeptr push(nodeptr list,struct book item)
{
    nodeptr p;
    p=getnode();
    p->info=item;
    p->next=list;
    return p;
}
*/
/**< Function to insert details of a book */

struct book insertDetails()
{
    struct book b;
    printf("Enter Book Name:\n");
    scanf("%s",b.bookName);
    printf("Enter Author name:\n");
    scanf("%s",b.author);
    printf("Enter Access No:\n");
    scanf("%d",&b.AccessNo);
    printf("Enter No of copies:\n");
    scanf("%d",&b.NoOfCopies);
    printf("Enter price:\n");
    scanf("%d",&b.price);
    return b;
}

/**< Function to delete the book based on access number  */

nodeptr searchndelete(nodeptr list,int anum)
{
    nodeptr prev,cur;
    if(list==NULL)
    {
        printf("Void Deletion");
        return NULL;
    }
    if(anum==list->info.AccessNo)
    {
        cur=list;
        list=list->next;
        freenode(cur);
        return list;
    }
    prev=NULL;
    cur=list;
    while(cur!=NULL)
    {
        if(anum==cur->info.AccessNo)break;
        prev=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("Entered Access number does not exist\n");
        return list;
    }
    prev->next=cur->next;
    freenode(cur);
    return list;
}

nodeptr insert_pos(struct book item,int pos,nodeptr list)
{
    nodeptr temp;       //node to be inserted
    nodeptr prev,cur;
    int count;

    temp=getnode();
    temp->info=item;
    temp->next=NULL;

    if(list==NULL&&pos==1)
        return temp;
    if(list==NULL)
    {
        printf("Invalid Position\n");
        return list;
    }
    if(pos==1)
    {
        temp->next=list;
        return temp;
    }
    count=1;
    prev=NULL;
    cur=list;
    while(cur!=NULL&&count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=temp;
        temp->next=cur;
        return list;
    }
    printf("Invalid Position\n");
    return list;
}

int unique_books(nodeptr list)
{
	nodeptr p;
	int count=0;
	for(p=list;p!=NULL;p=p->next)
	{
		if(p->info.NoOfCopies==1)
			count++;
	}
	return count;
}

/**< main function */

int main()
{
   int i,pos,anum;
   char auth[BSIZE];
   nodeptr list;
   list=NULL;
   struct book b;
   while(1)
   {
       printf("What do you want to do?\n1.Insert at a given position\n2.Delete the node containing access number\n3.Search the list based on Author\n4.Count the total number of books available  in library\n5.Display the list of books available in library\n6.Display the books in reverse order\n7.Modify the data of a book selected by access number\n8.Display the costliest book\n9.Display the cheapest book\n10.No of Unique books in library\n11.Exit\n\n");
       scanf("%d",&i);

       switch(i)
       {
           case 1:{
                    printf("At what position do you want to insert?");
                    scanf("%d",&pos);
                    b=insertDetails();
                    //if(pos==0)
                    //list=push(list,b);
                    //else
                    //insertAfter(list,b);
                    list=insert_pos(b,pos,list);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 2:{
                    printf("Enter the Access number:\n");
                    scanf("%d",&anum);
                    list=searchndelete(list,anum);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 3:{
                    printf("Enter author name:\n");
                    scanf("%s",auth);
                    searchList(list,auth);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 4:{
                    printf("Number of books is : %d\n",counter(list));
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 5:{
                    displayList(list);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 6:{
                    printf("Books in reverse order is:\n");
                    list=reverse(list);
                    //displayList(temp);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 7:{
                    printf("Enter the Access No:\n");
                    scanf("%d",&anum);
                    modify(list,anum);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 8:{
                    printf("Costliest book is:\n");
                    costliest(list);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 9:{
                    printf("Cheapest book is:\n");
                    cheapest(list);
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;}
            case 10:printf("No of unique books in library is: %d",unique_books(list));
                    printf("\nPress any key to continue...\n");
                    getch();
                    break;
            case 11:exit(1);

            default:printf("\n! ! ! ! ! ! ! ! ! ! ! !\nInvalid Choice!\n! ! ! ! ! ! ! ! ! ! ! !\n\n");
       }
    }

   return 0;
}

/**< End of Program */
