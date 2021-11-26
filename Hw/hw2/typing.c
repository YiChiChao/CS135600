#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
} Node;

#define next ptr_to_next_node 
#define prev ptr_to_prev_node

int n;
char buf[100];
Node* cursor;
char intype;
int num;
Node *head;
Node *tail; 


void insert(Node **cur, char c){
    Node *nownode = malloc(sizeof(Node));
    //point to itself -->only one node
    nownode->character = c;
    nownode->prev= *cur;
    nownode->next = (*cur)->next;
    (*cur)->next->prev = nownode;
    (*cur)->next = nownode;
    /*if(nownode->next == *cur){
        tail = nownode;
    }
    if(nownode->prev == *cur){
        head = nownode;
    }*/
}
void backspace(Node **cur){
    if((*cur) == head) return;
    Node *delete = (*cur);
    (*cur)->prev->next = (*cur)->next;
    (*cur)->next->prev = (*cur)->prev;
    *cur = delete->prev;
    free(delete);
    
}

void deletion(Node **cur){
    if((*cur)->next == tail) return;
    Node *delete = (*cur)->next;
    (*cur)->next = delete->next;
    delete->next->prev = *cur;
    free(delete);
}
void go_left(Node **cur, int t){
    Node *now = *cur;
    for(int i = 0; i < t; ++i){
        now = now->prev;
    }
    *cur = now;
}
void go_right(Node **cur, int t){
    Node *now = *cur;
    for(int i = 0; i < t; ++i){
        now = now->next;
    }
    *cur = now;
}
void go_home(Node **cur){
    *cur = head;
}
void go_end(Node **cur){
    *cur = tail->prev;
}

void show()
{
    if(head == NULL)
        {
        printf("\n");
        return;
    }
    Node *now = head->next;
    while(now != head)
    {
        printf("%c ", now->character);
        now = now->next;
    }
    printf("\n");
}



int main()
{
    scanf("%d",&n);
    head = (Node*)malloc(sizeof(Node));
    head->next = head->prev = head;
    cursor = tail = head;
    while(n--)
    {
        scanf("%s",buf);
        if(!strcmp(buf,"insert"))
        {
            getchar();
            scanf("%c",&intype);
            insert(&cursor, intype); 
        }
        else if(!strcmp(buf,"deletion"))
        {
            deletion(&cursor); 
        }
        else if(!strcmp(buf,"backspace"))
        {
            backspace(&cursor); 
        }
        else if(!strcmp(buf,"go_left"))
        {
            scanf("%d", &num);
            go_left(&cursor, num); 
        }
        else if(!strcmp(buf,"go_right"))
        {
            scanf("%d", &num);
            go_right(&cursor, num); 
        }
        else if(!strcmp(buf,"go_home"))
        {
            go_home(&cursor); 
        }
        else if(!strcmp(buf,"go_end"))
        {
            go_end(&cursor); 
        }
        else if(!strcmp(buf,"show"))
        {
            show();
        }
    }
    return 0;
}