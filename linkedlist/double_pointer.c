#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void insert_increase_list(Node **head, int data){
    Node *local_head = *head;
    Node *cur = *head;
    if(local_head == NULL){
        Node *new = (Node*)malloc(sizeof(Node));
        new->value = data;
        new->next = NULL;
        local_head = new;
    }
    else if(data < local_head->value){
        Node *new = (Node*)malloc(sizeof(Node));
        new->value = data;
        new->next = local_head;
        local_head = new;
    }
    else{
        while(data > cur->next->value){
            cur = cur->next;
        }
        Node *new = (Node*)malloc(sizeof(Node));
        new->value = data;
        new->next = cur->next;
        cur->next = new;
    }
    *head = local_head;
}

void print_list(Node *head){
    while(head != NULL){
        printf("%d\n", head->value);
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    insert_increase_list(&head, 2);
    insert_increase_list(&head, 1);
    insert_increase_list(&head, 3);
    insert_increase_list(&head, 5);
    insert_increase_list(&head, 4);
    print_list(head);
    return 0;
}