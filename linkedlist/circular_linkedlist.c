#include <stdio.h>
#include <stdlib.h>

typedef struct t_list{
    int id;
    char str[10];
    struct t_list* next;
}List;

//sentinel node to record the fist and last pointer
typedef struct {
    List* first;
    List* last;
}Head;

List* getData(void);
void printlist(Head head);
Head insertion_from_tail(Head head, List* newnode);
Head delete_first(Head head);
Head freelist(Head head);

List* getData(){
    //establish a newnode
    //if scanf can input a name
    //the next pointer should point to itself
    List* newnode = malloc(sizeof(List));
    static int id = 0;
    if(newnode != NULL){
        if(scanf("%9s", newnode->str) == 1){
            newnode->id = id++;
            newnode->next = newnode;//differ from single linkedlist
        }
        else{
            free(newnode);
            newnode = NULL;
        }
    }
    return newnode;   
}

Head insertion_to_last(Head head, List* newnode){
    //1.point the last next pointer to the newnode
    //2.change the next pointer from the newnode to the first node
    //3.change the last pointer in the Head 
    if(head.last == NULL){//first node
        head.first = newnode;
        head.last = newnode;
    }
    else if(newnode != NULL){
        (head.last)->next = newnode;
        newnode->next = head.first;
        head.last = newnode;
    }
    return head;
}

Head insertion_to_first(Head head, List* newnode){
    //1.let the next pointer of the newnode be the head.first
    //2.change the head first pointer to the newnode
    //3.change the next pointer of the last pointer to the new first pointer 
    if(head.last == NULL){//first node
        head.first = newnode;
        head.last = newnode;
    }
    else if(newnode != NULL){
        newnode->next = head.first;
        head.first = newnode;
        head.last->next = head.first;
    }
    return head;
}

Head delete_first(Head head){
    //1.change first pointer from head to the second node;
    //2.change the last->next to the second node;
    if(head.first != NULL){
        if(head.first->next == head.first){
            free(head.first);//remember to free the space
            head.first = NULL;
            head.last = NULL;
        }
        else{
            head.first = head.first->next;
            (head.last)->next = head.first;
            free(head.first);
        }
    }
    return head;
}

Head delete_last(Head head){
    //1.find out the previous node from the last node(for loop)
    //2.change the next node of the previous node to the head node
    //3.change the last node to the previous node
    List* tmp;
    if(head.first != NULL){
        if((head.first)->next == head.first){
            free(head.first);//remember to free the space
            head.first = NULL;
            head.last = NULL;
        }
        else{
            tmp = head.first;
            while(tmp->next != head.last){
                tmp = tmp->next;
            }
            tmp->next = head.first;
            free(head.last);
            head.last = tmp;
        }
    }
    return head;
}


int main(){
    //init
    Head head = {NULL, NULL};
    List *newnode = NULL;
    
    return 0;
}