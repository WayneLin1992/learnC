#include<stdio.h>
#include<stdlib.h>
/**
*  Node struct
*  @data: a int
*  @is_leaf: a int of leaf
*  @lchild: a pointer to t_node
*  @rchild: a pointer to t_node
*  
*  Define a tree struct.
*
**/
typedef struct t_node
{
    int data;
    /* data */
    struct t_node *lchild, *rchild;
    int is_leaf;   
} Node;
/**
*  newnode
*  @val: a int
*  
*  Allocate a space for a Node
* 
*  Note val must be int
*
*  Return a Node* tree lchild and rchild are NULL.
**/
Node* newnode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->lchild = NULL;
    node->rchild = NULL;
    node->is_leaf = 1;
    return node;
}
/**
*  destoryTree
*  @root: is a Node*
*  
*  free the root, rchild and lchild
* 
*  Return detoryTree and free all space of the tree.
**/

void destoryTree(Node* root){
    if(root != NULL)
        destoryTree(root->rchild);
        destoryTree(root->lchild);
        free(root);
}
/**
*  insertTree
*  @root: is a Node*
*  @data: is a int for insert Node.
*  
*  Inserts the tree from the leaf.
*
*  Note the root is not NULL
* 
*  insertTree() allocates a new space for insert tree, and it traveles 
*  the member of the tree to sure the position(it_leaf != 0) for the new tree.
*  data > root-> in rchild or data < root-> in lchild
*
*  Return root and include new tree.
**/

Node* insertTree(Node* root, int data){
    if(root == NULL){
        root = newnode(data);
        return root;
    }else{
        Node* node = newnode(data);
        Node* tmp = root;
        while(tmp){
            if(tmp->is_leaf){
                if(tmp->data > data){
                    tmp->lchild = node;
                    tmp->is_leaf = 0;
                    break;
                }else{
                    tmp->rchild = node;
                    tmp->is_leaf = 0;
                    break;
                }    
            }else{
                if (tmp->data > data){
                    if(tmp->lchild == NULL){
                        tmp->lchild = node;
                        break;
                    }
                    tmp = tmp->lchild;
                }else{
                    if(tmp->rchild == NULL){
                        tmp->rchild = node;
                        break;
                    }
                    tmp = tmp->rchild;
                }
            }
        }
    }
    return root;
}

int searchTree(Node* root, int target){
    if(root == NULL)
       return 0;
    if (root->data == target)
        return 1;
    else if(root->data > target)
        return searchTree(root->lchild, target);
    else
        return searchTree(root->rchild, target);
    return 0;
}

void show_search(Node* root, int target){
    if (searchTree(root, target) ==1)
        printf("Value: %d found in the BST\n", target);
    else
        printf("Value: %d is not found in the BST\n", target);
    
}

void showTree(Node* root){
    if(!root)
        return;
    showTree(root->lchild);
    printf("Node: %d-> ", root->data);
    showTree(root->rchild);
}
Node* get_inorder_successor(Node* node){
    Node* tmp = node->rchild;
    while(tmp->lchild){
        tmp = tmp->lchild;
    }
    return tmp;
}

Node* deleteTree(Node* root, int target){
    if(!root)
      return root;
    else{
        Node* tmp = root;
        if(tmp->data > target)
            tmp->lchild = deleteTree(root->lchild, target);
        else if(tmp-> data < target)
            tmp->rchild = deleteTree(root->rchild, target);
        else {
            if(tmp->lchild == NULL){
                Node *del_node = tmp;
                tmp = tmp->rchild;
                del_node-> rchild;
                free(del_node);
                return tmp;
            }
            else if(tmp->rchild == NULL){
                Node* del_node = tmp;
                tmp = tmp->lchild;
                del_node-> lchild;
                free(del_node);
                return tmp;
            }
            else
            {
                Node* inorder_successor = get_inorder_successor(tmp);
                tmp->data = inorder_successor->data;
                root->rchild = deleteTree(root->rchild, inorder_successor->data);
            }
            
        }
        
    }
    return root;
}
int Max_tree(Node* root){
    Node* tmp = root;
    while(tmp->rchild != NULL){
        tmp = tmp->rchild;
    }
    printf("%d", tmp->data);
    return tmp->data;
}

int Min_tree(Node* root){
    Node* tmp = root;
    while(tmp->lchild != NULL){
        tmp = tmp->lchild;
    }
    printf("%d", tmp->data);
    return tmp->data;
}
/*
* infix
*/
void showTreePre(Node* root){
    if(!root)
        return;
    showTree(root->lchild);
    showTree(root->rchild);
    printf("Node: %d-> ", root->data);    
}
/*
*  incorrect prefix
*/
int main(){
    Node* root = newnode(45);
    root = insertTree(root,20);
    root = insertTree(root,15);
    root = insertTree(root,60);
    root = insertTree(root,40);
    root = insertTree(root,50);
    root = insertTree(root,70);
    root = insertTree(root,42);
    showTree(root);
    printf("\n");
    showTreePre(root);
    printf("\n");
    show_search(root,15);
    show_search(root,70);
    show_search(root,35);
    root = deleteTree(root,50);
    printf("Delete 50");
    showTree(root);
    printf("\n");
    Max_tree(root);
    printf("\n");
    Min_tree(root);
    printf("\n");
    root = deleteTree(root, 45);
    showTree(root);
    destoryTree(root);
    return 0;
}