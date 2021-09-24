//prefix sum
#include<stdio.h>
long long int arr[2000005];
int main(){
    int n;
    long long int q;
    long long int tmp = 0;
    long long int try;
    long long int ans = 0;
    long long int ansa, ansb;
    while(scanf("%d %lld", &n, &q) != EOF){
        //scan the arr and do the prefix sum
        for(int i = 0; i < n;++i){
            int t;
            scanf("%d", &t);
            tmp += t;
            arr[i] = tmp;
        }
        tmp = 0;
        for(long long int i = 0; i < q; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            //to determine different scenerio of a and b turnsout different consequence
            if(a > b) try = arr[n-1]-(arr[a-2] - arr[b-1]);
            else if(a < b) try = arr[b-1]-arr[a-2];
            else try = arr[a-1]-arr[a-2];
            //printf("try = %d\n", try);
            if(try > ans) {
                ans = try;
                ansa = a;
                ansb = b;
            }
            try = 0;
        }
        printf("Max_range: (%lld,%lld); Value: %lld\n", ansa, ansb, ans);
        ans = 0;
    }
    return 0;
}