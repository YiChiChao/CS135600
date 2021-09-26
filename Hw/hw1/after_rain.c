#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;

void insert(Node **head, char *color, int index){
    //1.move the space to the correct place
    //2.if the index is not over the index, 
    //2.if over the index, add a new space in the end and the next pointer is NULL
    //3.put the color into the space
    Node *now = *head;
    //1. since the for loop cannot deal with index=0
    //2. when index>0 but there is nothing in the dest
    if(index == 0 || now->next == NULL){
        Node* tmp = (Node*)malloc(sizeof(Node));
        strcpy(tmp->color, color);
        tmp->next = now->next;
        now->next = tmp;
        return;
    }
    //to deal with the index 1, start from the first color index
    now = now->next;
    for(int i = 1; i < (index); ++i){
        //when the index is over the dest length, break
        if(now->next == NULL) break;
        else now = now->next;
    }
    if(color != NULL){
        Node* tmp = (Node*)malloc(sizeof(Node));
        strcpy(tmp->color, color);
        tmp->next = now->next;
        now->next = tmp;
    }   
}

void erase1(Node**head, int index){
    Node* now = *head;
    Node* tmp;
    //nothing to erase
    if(now->next == NULL)return;
    for(int i = 1; i < index; ++i){
        //when the index is over the dest length, break
        //now has to stop at the prev position
        if(now->next->next == NULL)break;
        now = now->next;
    }
    tmp = now->next;
    now->next = tmp->next;
    free(tmp);
}

void erase2(Node**head, char* color){
    Node* now = (*head)->next;
    Node* prev = *head;
    if(now == NULL) return;
    while(now != NULL){
        if(strcmp(color, now->color) == 0){
            prev->next = now->next;
            free(now);
            now = prev->next;
            continue;
        }
        prev = prev->next;
        now = prev->next;
    }
}

void reverse(Node**head, int a, int b){
    //directly change the pointer direction
    Node* now = (*head)->next;
    Node* prev = *head;
    Node* next;
    for(int i = 1; i < a; ++i){
        if(now->next == NULL) return;
        now = now->next;
        prev = prev->next;  
    }
    //to remember the head before the reverse part
    Node* first = prev;
    //start from the second node in the reverse part
    now = now->next;
    prev = prev->next;
    for(int i = a+1; i <= b; ++i){
        next = now->next;
        //switch the next pointer direction to the front
        now->next = prev;
        prev = now;
        now = next;
        //if b is bigger than the dest length
        if(now == NULL)break;  
    }
    //remember the tail after the reverse part
    Node* last = now;
    //connect the head with the reverse new head
    //connect the reverse new tail to the tail
    first->next->next = last;
    first->next = prev;

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