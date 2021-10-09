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
        //prefix sum
        while(index <= s_length){
            if(strncmp(s+(index-1), p, p_length) == 0){
                sum[index++] = ++count;
            }
            else {
                sum[index] = count;
                index++;
            }
        }
        scanf("%d", &q);
        for(int i = 0; i < q;++i){
            int start, end;
            scanf("%d %d", &start, &end);
            int num = end-p_length+1;
            int tmp;
            if(num < 0) tmp = 0;
            else tmp = sum[end - p_length + 1]-sum[start - 1];
            printf("%d %d\n", num, tmp);
            if(tmp > max){
                max = tmp;
            }
        }
        printf("%d\n", max);
        memset(s, 0, s_length);
        memset(p, 0, p_length);
    }
    
    return 0;
}