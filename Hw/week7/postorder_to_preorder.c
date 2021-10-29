#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct tree{
    int value;
    struct tree *left;
    struct tree *right;
}Node;


Node *create_node(int val){
    Node *newnode = malloc(sizeof(Node));
    newnode->value = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int search_inorder_idx(int inorder[], int target, int inorder_start, int inorder_end){
    for(int i = inorder_start; i <= inorder_end; ++i){
        if(inorder[i] == target)return i;
    }
    return -1;
}


int postorder_index;

Node* construct_tree(int postorder[], int inorder[], int inorder_start, int inorder_end, int n){
    if(inorder_end - inorder_start +1 == n){
        postorder_index = n-1;
    }
    if(inorder_end < inorder_start)return NULL;

    Node *treenode = create_node(postorder[postorder_index--]);
    if(inorder_start == inorder_end){
        return treenode;
    }
    int index = search_inorder_idx(inorder, treenode->value, inorder_start, inorder_end);
    treenode->right = construct_tree(postorder, inorder, index+1, inorder_end, n);
    treenode->left = construct_tree(postorder, inorder, inorder_start, index-1, n);
    return treenode;
}

void print_preorder(Node *root){
    printf("%d ", root->value);
    if(root->left != NULL){
        print_preorder(root->left);
    }
    
    if(root->right != NULL){
        print_preorder(root->right);
    }
    return;
}

void free_tree(Node *root){
    if(root->left != NULL){
        free_tree(root->left);
    }
    
    if(root->right != NULL){
        free_tree(root->right);
    }
    free(root);
    return;
}

int main(){
    int postorder[105] = {0};
    int inorder[105] = {0};
    int n;
    int count = 0;
    while(scanf("%d", &n) != EOF){
        count++;
        for(int i = 0; i < n; ++i){
            scanf("%d", &inorder[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &postorder[i]);
        }
        Node *tree = construct_tree(postorder, inorder, 0, n-1, n);
        printf("testcase%d: ", count);
        print_preorder(tree);
        printf("\n");
        free_tree(tree);
    }
    return 0;
}