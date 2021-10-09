# CS135600

## Week 2
[single linked list note](https://hackmd.io/@YiChiChao/rJ3FWLqJt#Linked-List)

## Linkedlist 作業整理
### Operation on Sequence
http://735cad64.cs.nthu.edu.tw/contest/4/problem/A

Summary: To simulate the typer, and write 4 function `insert`, `erase`, `move`, `show`.

#### Code Note

```c=
//因為有prev，在寫function的時候就不需要存取前一個pointer
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
        //先接new 的 pointer
        new->next = nownode->next;
        new->prev = nownode;
        //nownode->next要最後更改
        //因為它會影響到nownode->next->prev的位置
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
    //因為val可能很大，我們可以取得linkedlist length後
    //做mod，就不會出現TLE
    //因為while得停止條件會少做一次，所以先設length = 1
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
```
### After Rain
http://735cad64.cs.nthu.edu.tw/contest/3/problem/3

Summary: Write 5 operations `insert`, `erase1`, `erase2`, `reverse`, `show`

The content in the linkedlist is a string
`color[10]`

The answer form is a partial judge, restricted to be a singular linkedlist format. 
>When writing a singular linkedlist, be reminded that the function has to create a node for remembering the prev node of the target node in order to do the reconnection between the prev node and the next node.
#### Coding Note
```c=
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
    //2.if dest length is not over the index, 
    //2.if dest length is over the index, add a new space in the end and the next pointer is NULL
    //3.put the color into the space
    Node *now = *head;
    //Two particular condition 
    //1. the for loop cannot deal with the scenarion when index=0
    //2. when index>0 but there is nothing in the dest, the for loop might occur segment fault
    if(index == 0 || now->next == NULL){
        Node* tmp = (Node*)malloc(sizeof(Node));
        strcpy(tmp->color, color);
        tmp->next = NULL;
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
```

## Week 4
### Crazy give head
http://735cad64.cs.nthu.edu.tw/contest/7/problem/A

Question description:
To count how many substrings are in the certain interval, and to print out the maximum consequence for all the interval.

What method to use: `prefix sum` `strncmp`

Problems I confront during coding:

* I wanted to categorize `s_length - p_length +1` and index without having the substring and the one contains substring (too many) -->actually only has to divied as the one with contains substring and the one without it.
* When the `end` is less the `p_length`, it main lead to a problem that the index is less than 0. On the other hand, it means that the `end` and `start` index are not able to contain the substring, so we can just let `tmp = 0`
```c=
#include <stdio.h>
#include <string.h>
char s[1005] = {0};
char p[1005] = {0};

int main(){
    int q;
    while(scanf("%s %s", s, p) != EOF){
        int sum[1005]={0};
        int count = 0;
        int p_length = strlen(p);
        int s_length = strlen(s);
        int index = 1;
        int max = 0;
        while(index <= s_length){
            if(strncmp(s+(index-1), p, p_length) == 0){
                sum[index++] = ++count;
            }
            else {
                sum[index++] = count;
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q;++i){
            int start, end;
            scanf("%d %d", &start, &end);
            int num = end - p_length + 1;
            int tmp;
            //since num might be less than 0, which means both index won't have any string
            if(num < 0) tmp = 0;
            else tmp = sum[end - p_length + 1]-sum[start - 1];
            if(tmp > max){
                max = tmp;
            }
        }
        printf("%d\n", max);
    }
    
    return 0;
}

```
