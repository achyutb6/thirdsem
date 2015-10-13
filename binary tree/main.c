#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define MAXSTACK 100

struct nodetype{
int info;
struct nodetype *left;
struct nodetype *right;
};
typedef struct nodetype *nodeptr;

struct stack{
    int top;
    nodeptr item[MAXSTACK];
    };

int count=0;

/**< Function to get a node from dynamic memory
 *Type -Struct node pointer*/
nodeptr getnode()
{

    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct nodetype));
    return p;
}

nodeptr maketree(int x)
{
    nodeptr p;

    p=getnode();
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

int empty(struct stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}
void push(struct stack *s,nodeptr x)
{
    s->item[++s->top]=x;
}
nodeptr pop(struct stack *s)
{
    if(empty(*s))
    {
        printf("Stack Underflow");
        exit(1);
    }
    return s->item[s->top--];
}

void inorder(nodeptr tree)
{
    nodeptr p;
    struct stack s;

    s.top=-1;
    p=tree;
    do{
        while(p!=NULL){
            push(&s,p);
            p=p->left;
        }
        if(!empty(s)){
            p=pop(&s);
            printf("%d\t",p->info);
            p=p->right;
        }
    }while(!empty(s)||p!=NULL);

}

void preorder(nodeptr tree)
{
    if(tree!=NULL){
        printf("%d\t",tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(nodeptr tree)
{
    if(tree!=NULL){
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->info);
    }
}

int height(nodeptr tree)
{
   if (tree==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(tree->left);
     int rheight = height(tree->right);

     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}

void printGivenLevel(nodeptr tree,int level)
{
  if(tree == NULL)
    return;
  if(level == 1)
    printf("%d ", tree->info);
  else if (level > 1)
  {
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
  }
}

/* Function to print level order traversal a tree*/
void printLevelOrder(nodeptr tree)
{
  int h = height(tree);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(tree, i);
}

void count_leaf(nodeptr tree)
{
    if (tree == NULL)
    {
        return;
    }
    if (tree->left == NULL && tree->right == NULL)
    {
        count++;
    }
    count_leaf(tree->left);
    count_leaf(tree->right);
}



/*void insert(nodeptr tree, nodeptr item)
{
   if(!(tree))
    {
      tree = item;
      return;
    }
   if(item->info<(tree)->info)
      insert((tree)->left, item);
   else if(item->info>(tree)->info)
      insert((tree)->right, item);
}*/

void setleft(nodeptr p,int x)
{
    if(p==NULL)
        printf("Void insertion\n");
    else if(p->left!=NULL)
        printf("Invalid Insertion");
    else p->left=maketree(x);
}

void setright(nodeptr p,int x)
{
    if(p==NULL)
        printf("Void insertion\n");
    else if(p->right!=NULL)
        printf("Invalid Insertion");
    else p->right=maketree(x);
}

nodeptr insert(nodeptr tree,int item)
{
    char direction;
    printf("Give the direction you want to insert(L or R)\n");
    scanf("%c",&direction);
    direction=toupper(direction);
    if(direction=='L')
        setleft(tree,item);
    else
        setright(tree,item);
    return tree;

}


int main()
{
    int choice,num;
    nodeptr tree,p,q;

    while(1)
    {
        printf("What do you want to do?\n\t1.Make Tree\n\t2.Inorder Traversal\n\t3.Preorder Traversal\n\t4.Postrder Traversal\n\t5.Levelorder Traversal\n\t6.Count leaves\n\t7.Height of tree\n\t8.Exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                    printf("Enter integer values for tree\n");
                    scanf("%d",&num);
                    tree=maketree(num);
                    while(scanf("%d",&num)!=EOF)
                    {
                        p=q=tree;
                        while(num!=p->info&&q!=NULL){
                            p=q;
                            if(num<p->info)
                                q=p->left;
                            else
                                q=p->right;
                        };
                        if(num==p->info)
                            printf("duplicate\n");
                        else if(num<p->info)
                            setleft(p,num);
                        else
                            setright(p,num);
                    }
                    break;
                    }
              case 2:printf("Inorder Traversal:\n");
                     inorder(tree);
                     break;
              case 3:printf("Preorder Traversal:\n");
                     preorder(tree);
                     break;
              case 4:printf("Postorder Traversal:\n");
                     postorder(tree);
                     break;
              case 5:printf("Level-order Traversal:\n");
                     printLevelOrder(tree);
                     break;
              case 6:count_leaf(tree);
                     printf("No of leaves = %d\n",count);
                     break;
              case 7:printf("Height of tree is : %d\n",height(tree));
              break;
              case 8:exit(1);
        }
    }
    return 0;
}
