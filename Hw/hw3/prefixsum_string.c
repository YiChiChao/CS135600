#include <stdio.h>
#include <string.h>
#define Max(x, y) ((x > y) ? (x) : (y))


char S[1001], P[1001];
int s_length, p_length;
int q;
int check(int index){
    for(int i = 0; i < p_length; ++i){
        if(S[index +i] != P[i])return 0;
    }
    return 1;
}

int main(){
    while(~scanf("%s %s", S, P)){
        int ans = -1;
        int prefix[1787] = {0};
        s_length = strlen(S);
        p_length = strlen(P);
        scanf("%d", &q);
        for(int i = 0; i < s_length - p_length + 1; ++i){
            prefix[i+1] = check(i) + prefix[i];
        }
        while(q--){
            int l, r;
            scanf("%d %d", &l, &r);
            int start = l-1, end = r - p_length + 1;
            int temp = (end <= start) ? 0 : prefix[end] - prefix[start];
            ans = Max(temp, ans);
        }
        printf("%d\n", ans);
    }
}
