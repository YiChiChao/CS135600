#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define left left_child
#define right right_child

typedef struct _NODE {
    int level;
    struct _NODE *left_child, *right_child;
} Node;

Node* createNode(int num){
    Node *newnode = malloc(sizeof(Node));
    newnode->level = num;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void build_tree(Node **now, int *arr, int l, int r){
    if(l > r)return;
    int mid = (l + r)/2;
    Node *treenode = createNode(arr[mid]);
    if(*now == NULL) *now = treenode;
    build_tree(&((*now)->left), arr, l, mid-1);
    build_tree(&((*now)->right), arr, mid+1, r);
    return;
}
int query_heatstroke(Node *now, int x){
    int ans = 0;
    if(now == NULL)return 0;
    if(now->level > x)ans = query_heatstroke(now->left, x);
    else if(now->level < x)ans = query_heatstroke(now->right, x);
    else ans = 1;
    return ans;
}
void eat_rat(Node **root, int x){
    Node **nownode = root;
    while(*nownode != NULL){
        if((*nownode)->level > x)nownode = &((*nownode)->left);
        else if((*nownode)->level < x)nownode = &((*nownode)->right);
        else break;
    }
    if((*nownode)->left == NULL && (*nownode)->right == NULL){
        Node *delete = (*nownode);
        (*nownode) = NULL;
        free(delete);
    }
    else if((*nownode)->left != NULL && (*nownode)->right == NULL){
        Node *delete = (*nownode);
        *nownode = (*nownode)->left;
        free(delete);
    }
    else if((*nownode)->left == NULL && (*nownode)->right != NULL){
        Node *delete = (*nownode);
        *nownode = (*nownode)->right;
        free(delete);
    }
    else{
        Node *max = (*nownode)->left;
        while(max->right != NULL){
            max = max->right;
        }
        (*nownode)->level = max->level;
        eat_rat(&(*nownode)->left, max->level);
    }



}
void buy_rat(Node **root, int x){
    Node **nownode = root;
    while((*nownode) != NULL){
        if((*nownode)->level > x)nownode = &((*nownode)->left);
        else if((*nownode)->level <= x)nownode = &((*nownode)->right);
        else break;
    }
    *nownode = createNode(x);

}

void printtree(Node *root){
    if(root == NULL)return;
    printtree(root->left);
    printf("%d ", root->level);
    printtree(root->right);
    return;
}

int main(){
    int n;
    int arr[10005] = {0};
    char buffet[20];
    int q;
    int num;
    Node *root = NULL;
    
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    build_tree(&root, arr, 0, n-1);
    //printtree(root);
    //printf("\n");

    scanf("%d", &q);
    for(int i = 0; i < q; ++i){
        scanf("%s", buffet);
        if(strcmp("heatstroke", buffet) == 0){
            scanf("%d", &num);
            if(query_heatstroke(root, num) == 1){
                printf("We might as well eat it.\n");
                eat_rat(&root, num);
            }else printf("No dinner tonight.\n");
            
        }
        if(strcmp("buy", buffet) == 0){
            scanf("%d", &num);
            buy_rat(&root, num);
        }
    }
    return 0;
}

