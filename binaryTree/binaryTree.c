#include<stdio.h>
#include<stdlib.h>
/*
*  Node struct
*  @data: a int
*  @left: a pointer to t_node
*  @right: a pointer to t_node
*
*  Definds the tree struct.
*
*/
typedef struct t_node
{
    int data;
    struct t_node *left, *right;
} Node;
/**
*  newNode:
*  @val: a value of a Node.
*  
*  Allocate a space for a Node.
*
*  Note val must be a int.
*
*  newNode() has to allocate a space in memory for a Node
*  that left and right pointer to NULL 
*  
*  Return a pointer to Node
**/
Node* newNode(int val){
    Node *node =(Node *) malloc(sizeof(Node));
    node ->left = NULL;
    node ->right = NULL;
    node ->data = val;
    return node;
}
/**
 *  constructTree:
 *  @inorder: an array of int and sequial is inorder.
 *  @preorder: an array of int and sequial is preorder.
 *  @inorder_start: an int of a inorder begin index.
 *  @inorder_end: an int of a inorder last index.
 *  
 *  Create a tree of an array.
 *  
 *  Note inorder_start must smaller than inorder_end.
 * 
 *     
 **/
Node* constructTree(int inorder[ ],int preorder[ ], int inorder_start, int inorder_end){
    static int preorder_idx = 0;
    if(inorder_start > inorder_end)
        return NULL;
    Node *tree_node = newNode(preorder[preorder_idx++]);
    if(inorder_start == inorder_end)
        return tree_node;
    int inorder_idx = idxSearch(inorder, inorder_start, inorder_end, tree_node-> data);
    tree_node->left= constructTree(inorder, preorder, inorder_start, inorder_idx-1);
    tree_node->right = constructTree(inorder, preorder, inorder_idx+1, inorder_end);

    return tree_node;
}
void destoryTree(Node *root)
{
    if(root != NULL)
    {
        destoryTree(root->right);
        destoryTree(root->left);
        free(root);
    }
}
void inorder(Node *root)
{
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);

    }
}

void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
/**
*  idxSearch:
*  @arr: an array of int.
*  @start: array begin index.
*  @end: array end index
*  @value: search a value
*  
*  Searchs a number in an array
*
*  Note array must have value
*  
*  idxSearch() has to traverse the entire list to find a number that equales the value.     
*
*  Return: the index of the value in array.
**/
int idxSearch(int arr[], int start, int end, int value)
{
    int i;
    for(i=start; i<=end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

int maxValue(Node *tree)
{
    if(tree != NULL)
    {
        int maxval = tree->data;
        if(tree->left!=NULL){
            int tmp = maxValue(tree->left);
            if (maxval<tmp) maxval = tmp;
        }
        if(tree->right!=NULL){
            int tmp = maxValue(tree->right);
            if(maxval<tmp) maxval = tmp;
        }
        return maxval;
    }else return -1;
}

void printTree(FILE *fout, Node *tree)
{
    if(tree !=NULL){
            if(tree->left != NULL)
                fprintf(fout, "%d -> %d;\n", tree->data, tree->left->data);
            if(tree->right != NULL)
                fprintf(fout, "%d -> %d;\n", tree->data, tree->right->data);
            printTree(fout, tree->left);
            printTree(fout, tree->right);
    }
}

void writeGV(Node *tree)
{
    FILE *fout = fopen("tree.gv", "w");
    fprintf(fout, "digraph T {\n");
    printTree(fout, tree);
    fprintf(fout, "}\n");
}

int main(void)
{
    int *in, *pre, n, i;
    scanf("%d", &n);
    in = (int*)malloc(n*sizeof(int));
    pre = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d", &in[i]);
    for(i=0;i<n;i++)
        scanf("%d", &pre[i]);
    Node *root = constructTree(in, pre, 0, n-1);
    printf("%d\n", maxValue(root));

    writeGV(root);

    inorder(root);
    printf("\n");
    postorder(root);

    destoryTree(root);
    free(in);
    free(pre);

    return 0;
}
