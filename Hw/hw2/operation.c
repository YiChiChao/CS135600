#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node* prev;
    struct node* next;
} Node;

void insert(Node **head, int val1, int val2){
    Node *nownode = *head;
    while(val2 --){
        Node* new = malloc(sizeof(Node));
        new->value = val1;
        new->next = nownode->next;
        new->prev = nownode;
        nownode->next->prev = new;
        nownode->next = new;
        nownode = new;
    }
}

void erase(Node **head, int val){
    Node *nownode = (*head)->next;
    while(val--){
        Node* delete = nownode;
        nownode = nownode->next;
        free(delete);
    }
    (*head)->next = nownode;
    nownode->prev = *head;
}

void move(Node **head, int val){
    Node* nownode = *head;
    Node* checknode = *head;
    int length = 1;
    while(checknode->next != *head){
        ++length;
        checknode = checknode->next;
    }
    val %= length;
    while(val--){
        nownode = nownode->next;
    }
    *head = nownode;
}

void show(Node **head){
    Node *nownode = *head;
    while(nownode->next != *head){
        printf("%d ", nownode->value);
        nownode = nownode->next;
    }
    printf("%d\n", nownode->value);
}

int main(){
    Node* a;
    int x, n;
    char buf[100];
    int num1, num2;
    scanf("%d", &x);
    a = malloc(sizeof(Node));
    a->value = x;
    a->next = a;//point to itself
    a->prev = a;
    scanf("%d", &n);
    while(n--) {
        scanf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%d %d",&num1, &num2);
            insert(&a, num1, num2); 
        }
        else if(!strcmp(buf,"erase")) {
            scanf("%d",&num1);
            erase(&a, num1); // erase1 <dest>
        }
        else if(!strcmp(buf,"move")) {
            scanf("%d",&num1);
            move(&a, num1); // erase2 <color>
        }
        else if(!strcmp(buf,"show")) {
            show(&a);
        }
        
    }
    return 0;
}