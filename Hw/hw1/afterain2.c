#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;

void insert(Node **head, char *color, int index){
    //start from the node with color
    Node *nownode = *head;
    if(!(index == 0 || nownode->next == NULL)){
        nownode = nownode->next;
        for(int i = 1; i < index; ++i){
            if(nownode->next == NULL)break;
            else nownode = nownode->next;
        }
    }
    Node *addnode = malloc(sizeof(Node));
    strcpy(addnode, color);
    addnode->next = nownode->next;
    nownode->next = addnode;
    return;
}

void erase1(Node**head, int index){
    Node *nownode = *head;
    for(int i = 1; i < index; ++i){
        if(nownode->next != NULL){
            nownode = nownode->next;
        }
        else break;
    }
    Node *delete = nownode->next;
    nownode->next = delete->next;
    free((delete));
}
void erase2(Node**head, char* color){
    Node *nownode = *head;
    Node *prev = NULL;
    while(nownode != NULL){
        if(!strcmp(nownode->color, color)){
            prev->next = nownode->next;
            free(nownode);
            nownode = prev;
        }
        prev = nownode;
        nownode = nownode->next; 
    }
}
void reverse(Node**head, int a, int b){
    Node *nownode = *head;
    Node *tmp;
    Node *first;
    int i;
    for(i = 0; i != a; first = nownode, nownode = nownode->next, ++i);
    while(i < b && nownode->next != NULL){
        tmp = nownode->next;
        nownode->next = tmp->next;
        tmp->next = first->next;
        first->next = tmp;
        ++i;
    }
}
void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}




int n;
char buf[100];
int num1, num2;
Node *head;

int main() {
    head = (Node*)malloc(sizeof(Node)); // create an empty node
    memset(head->color,'\0',sizeof(head->color));
    head->next = NULL;
    scanf("%d",&n);
    while(n--) {
        scanf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%s%d",buf,&num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if(!strcmp(buf,"erase1")) {
            scanf("%d",&num1);
            erase1(&head, num1); // erase1 <dest>
        }
        
        else if(!strcmp(buf,"erase2")) {
            scanf("%s",buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if(!strcmp(buf,"reverse")) {
            scanf("%d%d",&num1,&num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf,"show")) {
            show(&head);
        }
    }
    return 0;
}