#include<stdio.h>
#include<math.h>
#include <string.h>
int visited[1001] = {0};
float length[1001][1001];
int ally = 0;
int one = 0;
int n, r, k;

int dfs(int start){
    int count = 0;
    visited[start] = 1;
    for(int i = 0; i < n; ++i){
        if(visited[i] == 1)continue;
        if(length[start][i] <= r){
            count++;
            count += dfs(i);
        }
    }
    return count;
}
int main(){
    int x[1001]={0};
    int y[1001]={0};
    int t;
    int ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &r, &k);
        for(int i = 0; i < n; ++i){
            scanf("%d %d", &x[i], &y[i]);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                length[i][j] = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
            }
        }
        for(int i = 0; i < n; ++i){
            if(visited[i] == 1)continue;
            if((ans = dfs(i)+1) >= k){
                ally++;
            }
            else one++;
        }
        printf("%d %d\n", one, ally);

        for(int i = 0; i < n; ++i){
            visited[i] = 0;
        }
        ally = 0;
        one = 0;
    }
    return 0;
}