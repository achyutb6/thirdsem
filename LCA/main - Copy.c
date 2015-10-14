/**< ====================================================
* PROGRAM TO FIND THE LEAST COMMON ANCESTOR OF TWO NODES IN A
* BINARY SEARCH TREE
*/

/**< ==================================================== */
/**< PROGRAM BY : ACHYUT BHANDIWAD
  *  ROLL NO: 07
  *  DATE OF SUBMISSION : 10/14/15
  */

/**=================PREPROCESSOR DIRECTIVES================= */

#include <stdio.h>
#include <stdlib.h>

/**=================STRUCTURE DEFINITION==================== */

struct nodetype{
    int info;
    struct nodetype *left;
    struct nodetype *right;
};
typedef struct nodetype *nodeptr;

/**< Function to get a node from dynamic memory
 *Type -Struct node pointer*/
nodeptr getnode()
{

    nodeptr p;
    p=(nodeptr)malloc(sizeof(struct nodetype));
    return p;
}
/**< Function to MAKE TREE*/
nodeptr maketree(int x)
{
    nodeptr p;

    p=getnode();
    p->info=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

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

/** Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
nodeptr lca(nodeptr tree, int n1, int n2)
{
    if (tree == NULL) return NULL;

    /** If both n1 and n2 are smaller than root, then LCA lies in left*/
    if (tree->info > n1 && tree->info > n2)
        return lca(tree->left, n1, n2);

    /** If both n1 and n2 are greater than tree, then LCA lies in right*/
    if (tree->info < n1 && tree->info < n2)
        return lca(tree->right, n1, n2);

    return tree;
}
// C function to search a given key in a given BST
nodeptr search(nodeptr root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->info == key)
       return root;

    // Key is greater than root's key
    if (root->info < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

/** MAIN FUNCTION */
int main()
{
    int num,n1,n2;
    nodeptr tree,temp;
    nodeptr p,q;

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
    printf("Enter values for n1 and n2\n");
    scanf("%d%d",&n1,&n2);
    temp=lca(tree,n1,n2);

    printf("LCA of %d and %d is %d \n", n1, n2, temp->info);

    return 0;
}
