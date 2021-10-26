#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define left left_child
#define right right_child
typedef struct _NODE {
    int level;
    struct _NODE *left_child, *right_child;
} Node;



/*void print_tree(Node *root){
    if(root == NULL)return;
    printf("%d ", root->level);
    print_tree(root->left);
    printf("// ");
    print_tree(root->right);
}*/




void build_tree(Node **now, int *arr, int l, int r){
    if(l > r)return;
    int mid = (l + r)/2;
    (*now) = (Node*)malloc(sizeof(Node));
    if(l == r){
        (*now)->level = arr[mid];
        (*now)->left = (*now)->right = NULL;
    }else{
        (*now)->level = arr[mid];
        build_tree(&((*now)->left), arr, l, mid-1);
        build_tree(&((*now)->right), arr, mid+1, r);
    }
    
}
int query_heatstroke(Node *now, int x){
    if(now == NULL)return 0;
    if(now->level == x)return 1;
    if(now->level > x){
        return query_heatstroke(now->left, x);
    }else{
        return query_heatstroke(now->right, x);
    }
}
void eat_rat(Node **root, int x){//delete node
    Node *now = *root;
    if(now == NULL){
        return;
    }
    //if x  > now root
    //then it lies in left subtree
    if(x > now->level){
        eat_rat(&now->right, x);
    }
    //if x < now root
    //then if lies in right subtree
    else if( x < now->level){
        eat_rat(&now->left, x);
    }
    // if key is same as now root
    //do the deletion
    else{
        //node with only one child or no child
        if(now->left == NULL){
            *root = now->right;
            free(now);
            return;
        }else if (now->right == NULL){
            *root = now->left;
            free(now);
            return;
        }
        //node with two children
        //get the inorder successor
        //min of the right subtree
        Node *min = now->right;
        while(min->left != NULL){
            min = min->left;
        }
        (*root)->level = min->level;
        //printf("root = %d\n", (*root)->level);
        eat_rat(&now->right, min->level);
    }
}
        /*delete = now;
        if(flag)pre->right = now->left;
        else pre->left = now->left;
    }else if(now->left == NULL){
        delete = now;
        if(flag)pre->right = now->right;
        else pre->left = now->right;
    }else{
        while(now->left->left != NULL){
            now->level = now->left->level;
            now = now->left;
        }
        now->level = now->left->level;
        delete = now->left;
        now->left = now->left->right;
    }
    free(delete);
}*/


int main(){
    int *arr;
    int n;
    Node *root = NULL;
    scanf("%d", &n);
    arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    
    build_tree(&root, arr, 0, n-1);
    //print_tree(root);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        int x;
        scanf("%d", &x);
        if(query_heatstroke(root, x)){
            printf("We might as well eat it.\n");
            eat_rat(&root, x);
            //print_tree(root);
            //printf("\n");
        }else{
            printf("No dinner tonight.\n");
        }

    }
    return 0;
}


