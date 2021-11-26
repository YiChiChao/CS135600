#include <stdio.h>
#include <math.h>
float distance[1005][1005];
int visited[1005] = {0};
int dfs(int now, int n, int r);
int ally = 0;
int independent = 0;
int main(){
    int n;
    int r;
    int x[1005], y[1005];
    scanf("%d %d", &n, &r);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            distance[i][j] = sqrt(pow((x[i]-x[j]), 2) + pow((y[i]-y[j]), 2));
        }
    }
    for(int i = 0; i < n; ++i){
        if(visited[i] == 1)continue;
        else{
            if(dfs(i, n, r) == 1)ally++;
            else independent++;
        }
    }
    printf("%d %d\n", independent, ally);
    return 0;
}

int dfs(int cur, int n, int r){
    int count = 0;
    visited[cur] = 1;
    for(int i = 0; i < n; ++i){
        if(i == cur)continue;
        if(visited[i] == 1)continue;
        if(distance[i][cur] <= r){
            dfs(i, n, r);
            count++;
        }
    }
    if(count == 0)return 0;
    else return 1;
}