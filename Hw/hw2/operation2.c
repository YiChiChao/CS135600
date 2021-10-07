#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node* prev;
    struct node* next;
} Node;

void insert(Node**head, int val1, int val2){
    while(val2--){
        Node *newnode = malloc(sizeof(Node));
        newnode->value = val1;
        newnode->next = (*head)->next;
        newnode->prev = (*head);
        (*head)->prev = newnode;
        (*head)->next = newnode;
    }
}

void erase(Node **head, int index){
    Node *nownode = (*head)->next;
    while(index--){
        Node *delete = nownode;
        nownode = nownode->next;
        free(delete);
    }
    (*head)->next = nownode;
}

void show(Node *head){
    Node *nownode = head;
    while(nownode->next != head){
        printf("%d ", nownode->value);
        nownode = nownode->next;
    }
    printf("%d\n", nownode->value);
}

void move(Node **head, int step, int length){
    Node *nownode = *head;
    step %= length;
    while(step--){
        nownode = nownode->next;
    }
    *head = nownode;
}

int main(){
    int x;
    int n;
    char buffer[20];
    int val1, val2;
    int length = 1;
    scanf("%d", &x);
    //init head
    Node *head = malloc(sizeof(Node));
    head->value = x;
    head->next = head->prev = head;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buffer);
        if(!strcmp(buffer, "insert")){
            scanf("%d %d", &val1, &val2);
            insert(&head, val1, val2);
            length += val2;
        }
        else if(!strcmp(buffer, "erase")){
            scanf("%d", &val1);
            erase(&head, val1);
            length -= val1;
        }
        else if(!strcmp(buffer, "show")){
            show(head);
        }
        else if(!strcmp(buffer, "move")){
            scanf("%d", &val1);
            move(&head, val1, length);
        }

    }
    return 0;
}