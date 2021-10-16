#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
} Node;

Node *newNode(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root){
        postorder(root->right);
        printf("%d ", root->data);
        postorder(root->left);
    }
}

int idxSearch(int *inorder, int inorder_start, int inorder_end, int target){
    int index = -1;
    for(int i = inorder_start; i <= inorder_end; ++i){
        if(inorder[i] == target){
            index = i;
            break;
        } 
    }
    return index;
}

void destroyTree(Node *root){
    if(root != NULL){
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int maxValue(Node *tree){
    if(tree != NULL){
        int maxval = tree->data;//assume the current tree data is the max
        if(tree->left != NULL){
            int tmp = maxValue(tree->left);
            if(tmp > maxval) maxval = tmp;
        }
        if(tree->right != NULL){
            int tmp = maxValue(tree->right);
            if(tmp > maxval) maxval = tmp;
        }
        return maxval;
    }
    else return -1;
}

Node *constructTree(int inorder[], int preorder[], int inorder_start, int inorder_end){
    static int preorder_idx = 0;//should remeber the former preorder index
    if(inorder_start > inorder_end){
        return NULL;
    }

    Node *tree_node = newNode(preorder[preorder_idx++]);
    if(inorder_start == inorder_end)
        return tree_node;//newNode has inited the left and right as NULL
    int inorder_idx = idxSearch(inorder, inorder_start, inorder_end, tree_node->data);

    tree_node->left = constructTree(inorder, preorder, inorder_start, inorder_idx-1);
    tree_node->right = constructTree(inorder, preorder, inorder_idx+1, inorder_end);

    return tree_node;

}

void printTree (FILE *fout, Node *tree){
    if(tree != NULL){
        if(tree->left != NULL)
            fprintf(fout, "%d -> %d;\n", tree->data, tree->left->data);
        if(tree->right != NULL)
            fprintf(fout, "%d -> %d;\n",tree->data, tree->right->data);
        printTree(fout, tree->left);
        printTree(fout, tree->right);
    }
}

void writeGV(Node *tree){
    FILE *fout = fopen("tree.gv", "w");
    fprintf(fout, "digraph T {\n");
    printTree(fout, tree);
    fprintf(fout, "}\n");
}

int main(){
    int *in, *pre, n, i;
    scanf("%d", &n);
    in = (int *) malloc(n *sizeof(int));//allocate space for inorder
    pre = (int*)malloc(n*sizeof(int));//allocate space for preorder

    for(i = 0; i < n; ++i)//read in inorder
        scanf("%d", &in[i]);
    
    for(i = 0; i < n; ++i)//read in pre-order
        scanf("%d", &pre[i]);

    Node *root = constructTree(in, pre, 0, n-1);//construct tree
    printf("%d\n", maxValue(root));//printf maxvalue of the tree

    writeGV(root);

    inorder(root);
    printf("\n");
    postorder(root);

    destroyTree(root);//clean up
    free(in);
    free(pre);


    return 0;
}