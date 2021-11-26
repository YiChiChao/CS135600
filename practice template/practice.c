#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

typedef struct node{
    long long int times;
    long long int id;
}Node;

Node game[1000005];

int fpw(long long int a, long long int times){
    long long int ans = 1;
    times /= 2;
    while(times){
        if(times % 2 == 1) ans = ((ans % MOD) * (a %MOD)) % MOD;
        a = ((a % MOD) * (a % MOD) % MOD);
        printf("ans = %lld a = %lld\n", ans,a);
        times /= 2;
    }
    return ans;
}

int cmp(const void *a, const void *b){
    Node A = *(Node*)a;
    Node B = *(Node*)b;
    if(A.times < B.times)return -1;
    else if(A.times == B.times)return 0;
    else return 1;
}
int binary_search(int x, int n){
    int left = 1, right = n, ans = 0;
    while(left < right){
        int mid = (left + right)/2;
        if(game[mid].times >= x){
            ans = mid;
            right = mid;
        }
        else left = mid+1;
    }
    if(game[ans].times == x)return game[ans].id;
    else return 0;
}
int main(){
    int n, q;
    int t;
    while(~scanf("%d %d", &n, &q)){
        for(int i = 1; i <= n;++i){
            scanf("%lld(/`A`)/ ~I__I ", &(game[i].times));
            game[i].id = i;
            if(game[i].times % 2 == 1)game[i].times = 0;
            else game[i].times = fpw(2, game[i].times);
        }
        for(int i = 1; i <= n; ++i){
            printf("%lld ", game[i].times);
        }
        printf("\n");
        qsort(game, n, sizeof(game[1]), cmp);
        for(int i = 1; i <= n; ++i){
            printf("%lld ", game[i].times);
        }
        printf("\n");
        for(int i = 0; i < q; ++i){
            scanf("%d", &t);
            int ans = binary_search(t, n);
            if(!ans)printf("Go Down Chicken 404\n");
            else printf("%d\n", ans);
        }
    } 
    return 0;
}