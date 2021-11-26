#include <stdio.h>
#define ll long long

ll int fast_power(ll int x, ll int y, ll int m){
    ll int result = x % m;
    if(y == 0){
        return 1%m;
    }
    ll int former = fast_power(x, y/2, m);
    result =((former % m)*(former % m)) % m;
    if(y % 2 == 1){
        result *= x % m;
    }
    return result%m;
    
}

int main(){
    ll int x, y, m;
    ll int ans;
    scanf("%lld %lld %lld", &x, &y, &m);
    ans = fast_power(x, y, m);
    printf("%lld\n", ans);
    return 0;
}