#include <stdio.h>
#include <stdlib.h>
#define MAX_N 103

enum{VAL, ID, OP};
typedef struct _Node{
    struct _Node*left, *right;
    int type;
    int val;
    char op;
}Node;

Node *newNode(int type, int val, char op){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->type = type;
    newnode->val = val;
    newnode->op = op;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
char in[4];
int ids[3];

Node *buildTree(){
    scanf("%s", in);
    Node *now;
    if('0'<= in[0] && in[0] <= '9')now = newNode(VAL, atoi(in), '\0');
    else if('x'<= in[0] && in[0] <= 'z')now = newNode(ID, 0, in[0]);
    else now = newNode(OP, 0, in[0]);
    if(now->type != OP)return now;
    now->left = buildTree();
    now->right = buildTree();
    return now;
}

int showInorder(Node *root){
    int left, right;
    switch(root->type){
        case VAL:
            printf("%d", root->val);
            return root->val;
        case ID:
            printf("%c", root->op);
            return ids[root->op - 'x'];
        case OP:
            left = showInorder(root->left);
            printf("%c", root->op);
            right = showInorder(root->right);
            switch(root->op){
                case '+': return left + right;
                case '-': return left - right;
                case '*': return left * right;
                case '/': return left / right;
                default: exit(1);
            }
        default: exit(1);
    }
}

int main(){
    Node *root = buildTree();
    scanf("%d %d %d", &ids[0], &ids[1], &ids[2]);
    printf("\n%d\n", showInorder(root));
    return 0;
}