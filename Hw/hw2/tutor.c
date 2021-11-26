#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;

Node *createList(int n){
    Node *head = malloc(sizeof(Node));
    Node *cur = head;
    head->number = 1;
    head->next = head;
    for(int i = 2; i <= n; ++i){
        Node *newnode = malloc(sizeof(Node));
        newnode->number = i;
        newnode->next = head;
        cur->next = newnode;
        cur = newnode;
    }
    return head;
}

void freeList(Node *head){
    while(head->next != head){
        Node *delete = head->next;
        head->next = head->next->next;
        free(delete);
    }
    free(head);
}

int solveJosephus(Node **head, int step){
    int length = 1;
    Node *count = (*head)->next;
    while(count != *head){
        length++;
        count = count->next;
    }
    while(*head != (*head)->next){
        int k = (step % length -2 + length) % length;//-1 for count in the start point, -1 for stop on the target->prev
        for(int i = 0; i < k; ++i){
            *head = (*head)->next;
        }
        Node* tmp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(tmp);
        *head = (*head)->next;
        length--;
    }
    return (*head)->number;
}