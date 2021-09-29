#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

void insert_front(Node **head, int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->value = data;
    new->next = *head;
    *head = new;
}

void insert(Node **prev, int data){
    Node *new = (Node*)malloc(sizeof(Node));
    new->value = data;
    new->next = (*prev)->next;
    (*prev)->next = new;
}

void insert_increase_list(Node **head, int data){
    Node *prev = *head;
    if(*head == NULL){
        insert_front(head, data);
    }
    else if(data < (*head)->value){
        insert_front(head, data);
    }
    else{
        while(data > prev->next->value){
            prev = prev->next;
        }
        printf("prev = %d\n", prev->value);
        insert(&prev, data);
        printf("now = %d\n", prev->next->value);
    }
}

void print_list(Node *head){
    while(head != NULL){
        printf("%d\n", head->value);
        head = head->next;
    }
    printf("FINISHED!!\n");
}

int main(){
    Node *head = NULL;
    insert_increase_list(&head, 2);
    insert_increase_list(&head, 1);
    print_list(head);
    insert_increase_list(&head, 3);
    print_list(head);
    insert_increase_list(&head, 5);
    print_list(head);
    insert_increase_list(&head, 4);
    print_list(head);
    return 0;
}