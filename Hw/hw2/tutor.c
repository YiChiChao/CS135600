#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n){
    //create list in the reverse order
    //the node will stop at the head
    Node *np = (Node*)malloc(sizeof(Node));
    np->number = n;
    np->next = np;
    Node *nownode = np; 
    while(--n){
        Node *addnode = malloc(sizeof(Node));
        addnode->number = n;
        addnode->next = nownode;
        nownode = addnode; 
    }
    np->next = nownode;
    return nownode;
}

void freeList(Node* head){
    
}

int solveJosephus(Node **head, int step){
    Node* nownode = *head;
    int length = 1;
    while(nownode->next != *head){
        ++length;
        nownode = nownode->next;
    }
    //printf("length = %d\n", length);
    while(nownode->next != nownode){
        int mod_step = step % length;
        if(mod_step == 0){
            for(int i = 0; i< length-1; ++i){
                nownode = nownode->next;
            }
            Node *delete = nownode->next;
            nownode->next = delete->next;
            free(delete);    
        }
        else{
            for(int i = 0; i < (mod_step-1);++i){
            nownode = nownode->next;
            }
            //printf("%d\n", nownode->number);
            Node* delete = nownode->next;
            nownode->next = delete->next;
            free(delete);
        }
        
        //printf("%d\n", nownode->number);
        //printf("%d\n", nownode->next->number);
        --length;
    }
    
    return nownode->number;
}
void print(Node *head){
    Node* nownode = head;
    while(nownode->next != head){
        printf("%d ", nownode->number);
        nownode = nownode->next;
    }
    printf("%d\n", nownode->number);
}

int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
    {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}