#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXEXPR 256

char expr[MAXEXPR];
int pos;

typedef enum{VAR_A, VAR_B, VAR_C, VAR_D, OP_AND, OP_OR, END} TokenSet;
char sym[] = "ABCD&|()";

typedef struct Node{
    TokenSet data;
    struct Node *left, *right;
} BTNode;

BTNode *EXPR();
BTNode *FACTOR();

/*create a node without any child*/
BTNode *makeNode(char c){
    int i;
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    for(i = 0; (unsigned int) i < strlen(sym); i++){
        if(c == sym[i])node->data = i;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*clean a tree*/
void freeTree(BTNode *root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/*printf a tree by preorder*/
void printPrefix(BTNode *root){
    if(root != NULL){
        printf("%c", sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* FACTOR = VAR | (EXPR) */
BTNode* FACTOR(){
    char c;
    BTNode *node = NULL;

    if(pos >= 0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D'){
            node = makeNode(c);
        }
        else if(c == ')'){
            node = EXPR();
            if(expr[pos--] != '('){
                printf("ERROR: not matching parathesis\n");
                freeTree(node);
            }
        }
    }
    return node;
}

BTNode* EXPR(){
    char c;
    BTNode *node = NULL, *right = NULL;

    if(pos >= 0){
        right = FACTOR();
        if(pos > 0){
            c = expr[pos];
            if(c == '&' || c == '|'){
                node = makeNode(c);
                node->right = right;
                pos--;

                node->left = EXPR();
            }
            else node = right;
        }
        else{
            node = right;
        }
    }
    return node;
}

int main(){
    size_t len;
    fgets(expr, sizeof(expr), stdin);
    len = strlen(expr);
    if(len > 0 && expr[len-1] == '\n'){
        --len;
        expr[len] = '\0';
    }
    pos = strlen(expr) -1;
    BTNode *root = EXPR();
    printPrefix(root);
    freeTree(root);
    return 0;
}