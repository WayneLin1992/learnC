#include<stdio.h>
#include<stdlib.h>

static int level = 0; 
typedef struct t_node
{
    int data;
    struct t_node *left, *right;
    int is_leaf;
    
} Node;

Node* newnode(int val){
    Node* node = malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->is_leaf = 2;
    return node; 
}

Node* insertTree(Node*root, int val){
    Node* tmp = root;
    Node* node = newnode(val);
    if(root == NULL){
        return node;
    }else{
        while(tmp){
            if(tmp->is_leaf)
                if(tmp->is_leaf == 2){
                    tmp->left = node;
                    tmp->is_leaf = 1;
                    break;
                }else if(tmp->is_leaf == 1){
                    tmp->right = node;
                    tmp->is_leaf = 0;
                    break;
                }else if(tmp->is_leaf ==0){
                    break;
                }
            else{
                tmp = tmp->left;
            }   

        }
        
    }

}
int main(){

    printf("hello");
}