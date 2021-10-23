#include<stdio.h>
int main(){
    int n;
    int flag = 0;
    char str[28] = {0};
    scanf("%d", &n);
    if(n > 26 || n == 1) printf("I'm the god of Knuckles!\n");
    else{
        scanf("%s", str);
        for(int i = 1; i < n; ++i){
            scanf("%c", &str[i]);
            //printf("%c\n", str[i]);
            if(str[i-1] == str[i]){
                printf("I'm the god of Knuckles!\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("Different makes perfect\n");
    }
    return 0;
}