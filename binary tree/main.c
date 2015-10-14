/** PROGRAM TO DO THE FOLLOWING TASKS ON A BINARY TREE
 * MAKE TREE
 * INORDER TRAVERSAL
 * PREORDER TRAVERSAL
 * POSTORDER TRAVERSAL
 * LEVEL-ORDER TRAVERSAL
 * COUNT NUMBER OF LEAVES
 * HEIGHT OF TREE
 */
 /**< ==================================================== */
/**< PROGRAM BY : ACHYUT BHANDIWAD
  *  ROLL NO: 07
  DATE OF SUBMISSION : 10/14/15 */
/**=================PREPROCESSOR DIRECTIVES================= */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/**=========================MACROS========================== */
#define MAXSTACK 100

/**=================STRUCTURE DEFINITION==================== */
struct nodetype{
int info;
struct nodetype *left;
struct nodetype *right;
};
typedef struct nodetype *nodeptr;
/**=================STRUCTURE DEFINITION==================== */
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
    p=(nodeptr)malloc(sizeof(struct nodetype));             /**allocate memory dynamically*/
    return p;
}
/**< Function to MAKE TREE*/
nodeptr maketree(int x)
{
    nodeptr p;

    p=getnode();                                            /**Get node */
    p->info=x;
    p->left=NULL;                                           /**set left subtree to NULL*/
    p->right=NULL;                                          /**set right subtree to NULL*/
    return p;
}
/**< Function to check if stack is empty*/
int empty(struct stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

/**< Function to push element in stack */
void push(struct stack *s,nodeptr x)
{
    s->item[++s->top]=x;
}

/**< Function to pop element from stack*/

nodeptr pop(struct stack *s)
{
    if(empty(*s))
    {
        printf("Stack Underflow");
        exit(1);
    }
    return s->item[s->top--];
}

/**< Function to perform inorder traversal(recursive)*/
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

/**< Function to perform preorder traversal*/

void preorder(nodeptr tree)
{
    if(tree!=NULL){
        printf("%d\t",tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}

/**< Function to perform postorder traversal*/

void postorder(nodeptr tree)
{
    if(tree!=NULL){
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\t",tree->info);
    }
}

/**< Function to calculate height of tree*/

int height(nodeptr tree)
{
   if (tree==NULL)
       return 0;
   else
   {
     /** compute the height of each subtree */
     int lheight = height(tree->left);
     int rheight = height(tree->right);

     /** use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}

/**< Function to print given level of tree*/


void printgivenlevel(nodeptr tree,int level)
{
  if(tree == NULL)
    return;
  if(level == 1)
    printf("%d ", tree->info);
  else if (level > 1)
  {
    printgivenlevel(tree->left, level-1);
    printgivenlevel(tree->right, level-1);
  }
}

/** Function to print level order traversal a tree*/
void printlevelorder(nodeptr tree)
{
  int h = height(tree);
  int i;
  for(i=1; i<=h; i++)
    printgivenlevel(tree, i);
}

/**< Function to count number of leaves in a tree*/

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

/**< Function to insert an element to left of the current node*/

void setleft(nodeptr p,int x)
{
    if(p==NULL)
        printf("Void insertion\n");
    else if(p->left!=NULL)
        printf("Invalid Insertion");
    else p->left=maketree(x);
}

/**< Function to insert an element to right of the current node*/

void setright(nodeptr p,int x)
{
    if(p==NULL)
        printf("Void insertion\n");
    else if(p->right!=NULL)
        printf("Invalid Insertion");
    else p->right=maketree(x);
}

/**< Function to insert an element by asking the user whether to insert right or left*/
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
/**< MAIN FUNCTION*/

int main()
{
    int choice,num;
    nodeptr tree,p,q;

    while(1)
    {
        printf("What do you want to do?\n\t1.Make Tree\n\t2.Inorder Traversal\n\t3.Preorder Traversal\n\t4.Postrder Traversal\n\t5.Levelorder Traversal\n\t6.Count leaves\n\t7.Height of tree\n\t8.Exit\n\n");
        scanf("%d",&choice);
        switch(choice)                                               /**switch to chose options*/
        {
            case 1:{
                    printf("Enter integer values for tree\n");          /**create a tree and return pointer to root node*/
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
              case 2:printf("Inorder Traversal:\n");                /**traverse the tree in inorder*/
                     inorder(tree);
                     printf("\n");
                     break;
              case 3:printf("Preorder Traversal:\n");               /**traverse the tree in preorder*/
                     preorder(tree);
                     printf("\n");
                     break;
              case 4:printf("Postorder Traversal:\n");              /**traverse the tree in postorder*/
                     postorder(tree);
                     printf("\n");
                     break;
              case 5:printf("Level-order Traversal:\n");            /**print the level order of tree*/
                     printlevelorder(tree);
                     printf("\n");
                     break;
              case 6:count_leaf(tree);
                     printf("No of leaves = %d\n",count);
                     break;
              case 7:printf("Height of tree is : %d\n",height(tree));       /**find the height of tree*/
              break;
              case 8:exit(1);
        }
    }
    return 0;
}
/**END OF PROGRAM*/
