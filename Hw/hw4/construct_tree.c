#include <stdio.h>
#include <stdlib.h>
#define right ptr_to_right_node
#define left ptr_to_left_node

typedef struct _NODE
{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;
int n;

Node *newNode(int val){
    Node *node = malloc(sizeof(Node));
    node->number = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int idxSearch(int inorder[], int preorder[], int inorder_start, int inorder_end, int target){
    for(int i = inorder_start; i <= inorder_end; ++i){
        if(inorder[i] == target){
            //printf("root = %d\n", inorder[i]);
            return i;
        }
    }
    return -1;
}
int preorder_idx = 0;
Node* buildTree(int inorder[], int preorder[], int inorder_start, int inorder_end){
    if(inorder_end - inorder_start+1 == n) preorder_idx = 0;
    //printf("preorder_idx = %d\n", preorder_idx);
    if(inorder_start > inorder_end){
        //printf("NULL\n");
        return NULL;
    }

    Node *tree_node = newNode(preorder[preorder_idx++]);
    if(inorder_start == inorder_end){
        //printf("leaf = %d\n", tree_node->number);
        return tree_node;
    }
    int inorder_idx = idxSearch(inorder, preorder, inorder_start, inorder_end, tree_node->number);
    tree_node->left = buildTree(inorder, preorder, inorder_start, inorder_idx-1);
    tree_node->right = buildTree(inorder, preorder, inorder_idx+1, inorder_end);
    return tree_node;
}

void showPostorder(Node* root){
    if(root->left != NULL){
        showPostorder(root->left);
    }
    if(root->right != NULL){
        showPostorder(root->right);
    }
    printf("%d ", root->number);
    return;
}

void freeTree(Node *root){
    if(root->left != NULL){
        freeTree(root->left);
    }
    if(root->right != NULL){
        freeTree(root->right);
    }
    //printf("%d is free\n",root->number);
    Node *deleted = root;
    root = NULL;
    free(deleted);
    return;
}

int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
        if(root == NULL){
            printf("finish!\n");
        }
    }
    return 0;
}