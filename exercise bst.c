#include<stdio.h>
#include<stdlib.h>

struct bin_tree
{
    int data;
    struct bin_tree *right, *left;
};

typedef struct bin_tree node;

 void insert(node *tree,int val)
{
    node *temp = NULL;
    if(!(tree))
    {
        temp = (node*) malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        tree = temp;
        return;
    }
    if(val < (tree)->data){
        insert((tree)->left,val);
    }
     if(val > (tree)->data){
        insert((tree)->right,val);
    }

}

node *search (node *tree, int val)
{
    if(!(tree)){
        return NULL;
    }

    if(val > (tree)->data){
        search((tree)->right,val);
    }
    else if(val < (tree)->data){
        search((tree)->left,val);
    }
    else if(val==(tree)->data)
    {
        return 1;
    }
}


void inorder(node *tree)
{

    inorder((tree)->left);
    printf("%d\n",tree->data);
    inorder(tree->right);
}
void preorder(node *tree)
{
    printf("%d\n",tree->data);
    preorder((tree)->left);
    preorder(tree->right);
}
void postorder(node *tree)
{
    postorder((tree)->left);
    postorder(tree->right);
    printf("%d\n",tree->data);
}


int main()
{
    node *root;
    node *tmp;

    int n,num,s;
    printf("how many nodes is bst\n");
    scanf("%d",&n);

    int i;
    for(i=0;i<n;i++){
    printf("Enter the nodes in Bst...");
    scanf("%d",&num);
    insert(&root,num);
    }

    printf("Inorder...");
    inorder(root);
     printf("preorder...");
    preorder(root);
     printf("postorder...");
    postorder(root);
    printf("enter the node to be searched...\n");
    scanf("%d",&s);
    tmp = search(&root,s);
    if(tmp){
        printf("found");
    }
    else
    {
        printf("not found");
    }
    return 0;


}
