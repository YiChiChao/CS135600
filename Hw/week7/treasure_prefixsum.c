#include <stdio.h>
#include <stdlib.h>

long long int arr[1000005] = {0};
int main(){
    int n, q;
    int l, r, m;
    long long int temp = 0;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &temp);
        if(temp < 0)temp = 0;
        arr[i] = arr[i-1]+temp;
    }
    for(int i = 0; i < q; ++i){
        scanf("%d %d %d", &l, &r, &m);
        long long int index = l + m -1;
        long long int ans = arr[index] - arr[l-1];
        printf("%lld\n", ans);
    }
}