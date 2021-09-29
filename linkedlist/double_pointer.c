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
    if(*head == NULL || data < prev->value){
        insert_front(head, data);
    }
    else{
        while(prev->next != NULL ){//if we write "if(data > prev->next->value" in the while loop, when confront NULL if will occur segment fault 
            if(data > prev->next->value) prev = prev->next;
            else break;
        }
        insert(&prev, data);
    }
}

void delete_node(Node **head, int index){
    Node *delete_node;
    if(*head == NULL) return;
    else if(index == 1){
        delete_node = *head;
        *head = (*head)->next;
        free(delete_node);
        return;
    }

    Node *cur = *head;
    while(cur->next != NULL){
        if(index > 2){//we want the cur node to stop at the front 
            cur = cur->next;
            index--;
        }
        else break;
    }
    delete_node = cur->next;
    cur->next = delete_node->next;
    free(delete_node);   
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
    delete_node(&head, 3);
    print_list(head);
    return 0;
}