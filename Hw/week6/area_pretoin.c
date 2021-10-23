#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int x, y, z;
int idx = 0;
char buffer[100];


int getnext(){
    if(buffer[idx] != '\0' && isspace(buffer[idx]))
        idx++;
    if (buffer[idx] == '\0') {
        return -1;
    }
    else {
        int c = buffer[idx++];
        //printf("input: %c\n", c);
        return c;
    }
}

int intgetnext(){
    if(buffer[idx] != '\0' && isspace(buffer[idx])){
        idx++;
        return 32;
    }
    if (buffer[idx] == '\0') {
        return 32;
    }
    else {
        int c = buffer[idx++];
        //printf("input: %c\n", c);
        return c;
    }
}

int calculate(){
    int c;
    int ans;
    int op1, op2;

    c = getnext();
    //printf("c = %c\n", c);
    if (c == '+'){
        op1 = calculate();
        printf("+");
        op2 = calculate();
        ans = op1 + op2;
    }
    else if(c == '-'){
        op1 = calculate();
        printf("-");
        op2 = calculate();
        ans = op1 - op2;
    }
    else if(c == '*'){
        op1 = calculate();
        printf("*");
        op2 = calculate();
        ans = op1 * op2;
    }
    else if(c == '/'){
        op1 = calculate();
        printf("/");
        op2 = calculate();
        ans = op1 / op2;
    }
    else{
        if(c == 'x'){
            ans = x;
            printf("%c", c);
        }
        else if(c == 'y'){
            ans = y;
            printf("%c", c);
        }
        else if(c == 'z'){
            ans = z;
            printf("%c", c);
        } 
        else{
            char str[4];
            str[0] = c;
            int i = 1;
            while(c != 0){
                char token = intgetnext();
                if(token == ' ')break;
                else str[i++] = token;
            }
            str[i] = '\0';
            c = atoi(str);
            ans = c;
            printf("%d", ans);
        }
    }
    return ans;
}

int main(){
    fgets(buffer, sizeof(buffer), stdin);
    int length = strlen(buffer);
    if (length > 0 && buffer[length-1] == '\n') {
        --length;
        buffer[length] = '\0';
    }
    scanf("%d %d %d", &x, &y, &z);
    printf("\n%d\n", calculate());
    return 0;
}


