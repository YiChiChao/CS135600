#include<stdio.h>

int pre[1000005]={0};
int sum = 0;
int main(){
    for(int i = 1; i <= 1000000;++i){
        int num = i;
        while(num != 0){
            if(num % 10 == 1) ++sum;
            num/=10;
        }
        pre[i] = sum;
    }
    int x;
    int val1, val2;
    scanf("%d", &x);
    while(x--){
        scanf("%d %d", &val1, &val2);
        int ans = pre[val2] - pre[val1 - 1];
        printf("%d\n", ans);

    }
    return 0;
}
