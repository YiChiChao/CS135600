#include <stdio.h>
#define ll long long int
#define MAX 1000000000000000001
int main(){
    ll f;
    while(~scanf("%lld", &f)){
        ll max = MAX;
        ll tmp;
        ll swap;
        ll a = 1, b = 1;
        while((tmp = (f-a)/b) >= 0){
            if((f-a)%b == 0){
                if(tmp < max){
                    max = tmp;
                }
            }
            swap = b;
            b += a;
            a = swap;
        }
        if(a == 1 && b == 1)max = 0;
        printf("%lld\n", max);
    }
    
    return 0;
}