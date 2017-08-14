#include<stdlib.h>
#include<stdio.h>

struct bin_tree
{
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node * tree, int val)
{
    node *temp = NULL;
    if(!(tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        tree = temp;
        return;
    }

    if(val < (tree)->data)
    {
        insert(&(tree)->left, val);
    }
    else if(val > (tree)->data)
    {
        insert(&(tree)->right, val);
    }

}

void inorder(node * tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%d\n",tree->data);
        inorder(tree->right);
    }
}

void preorder(node *tree) {
    if(tree) {
        printf("%d\n",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(node * tree) {
    if(tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n",tree->data);
    }
}



node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
      int n;
      int num;
      printf("number of nodes...\n");
      scanf("%d",&num);

    int x;
    for( x=0;x<num;x++) {
        printf("Enter new node of BST ");
        scanf("%d",&n);
        insert(&root,n);
    }
    /* Inserting nodes into tree */




    printf("In Order Display\n");
    inorder(root);

    printf("Pre-oreder disply\n");
    preorder(root);

    printf("Post order display\n");
    postorder(root);



    /* Search node into tree */
    printf("\n\nWhat value do you want to search...");
    int s;
    scanf("%d",&s);
    tmp = search(&root, s);
    if (tmp)
    {
        printf("Found...Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
}
