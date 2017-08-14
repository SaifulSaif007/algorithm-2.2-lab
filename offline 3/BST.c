#include<stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insertNode(struct node *q, int data) {
    if(q == NULL) {
        struct node *p = (struct node*)malloc(sizeof(struct node));
        p->left = NULL;
        p->right = NULL;
        p->data = data;
        root = p;
        return;
    }
    else if(data < q->data && q->left != NULL) {
        q = q->left;
        insertNode(q,data);
    }
    else if(data > q->data && q->right != NULL) {
        q = q->right;
        insertNode(q,data);
    }

        return;
    }


void inOrderTrav(struct node *q) {
    if(q != NULL) {
        inOrderTrav(q->left);
        printf("%d\n",q->data);
        inOrderTrav(q->right);
    }
}

void preOrderTrav(struct node *q) {
    if(q != NULL) {
        printf("%d\n",q->data);
        preOrderTrav(q->left);
        preOrderTrav(q->right);
    }
}

void postOrderTrav(struct node *q) {
    if(q != NULL) {
        postOrderTrav(q->left);
        postOrderTrav(q->right);
        printf("%d\n",q->data);
    }
}
 void search (struct node *q, int val)
{
    if(!(q))
    {
        printf("not found");
    }

    if(val <(q)->data)
    {
        search(((q)->left), val);
    }
    else if(val > (q)->data)
    {
        search(((q)->right), val);
    }
    else if(val == (q)->data)
    {
        printf("Found");
    }
    return 0;
}
void main() {
    int n;
    int num;
    printf("Enter the number of nodes...\n");
    scanf("%d",&num);
    int x;
    for( x=0;x<num;x++) {
        printf("Enter new node of BST ");
        scanf("%d",&n);
        insertNode(root,n);
    }

    printf("\nInorder Traversal is:\n");
    inOrderTrav(root);

    printf("\nPreorder Traversal is:\n");
    preOrderTrav(root);

    printf("\nPostorder Traversal is:\n");
    postOrderTrav(root);

    printf("Enter the values to be searched... \n");
    int s;

    scanf("%d",&s);

    search(root,s);

    return 0;
}
