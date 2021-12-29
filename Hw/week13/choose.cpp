#include <cstdio>
#include <array>
#define MAX 1000000001
#define MIN -1
#define max(i,j) (i > j) ? i : j
#define min(i,j) (i < j) ? i : j
using namespace std;
int main(){
    int x;
    array<int, 5000> arr;
    scanf("%d", &x);
    for(int i = 0; i < x; ++i){
        int n, m, k;
        scanf("%d %d %d", &n,&m, &k);
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
            //printf("%d\n", arr[i]);
        }
        int ans = MIN;
        if(m-k <= 0)k = m-1;
        for(int i = 0; i <= k; ++i){
            //order part
            int at_least = MAX;
            int head = i;
            int tail = n-(k-i)-1;
            for(int h = 0; h <= m-k-1; ++h){
                //the part we cannot control
                int head_point = head + h;
                int tail_point = tail - (m-k-1-h);
                //printf("at_least: %d\n", at_least);
                int tmp = max(arr[head_point], arr[tail_point]);
                at_least = min(tmp, at_least);
                //printf("headPoint = %d, tailPoint = %d\n", head_point, tail_point);
                
            }
            ans = max(ans, at_least);
            //printf("max = %d\n", ans);
            //printf("---------------------\n");
        }
        printf("%d\n", ans);
    }
}