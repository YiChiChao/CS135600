#include<stdio.h>
#include<math.h>
int visited[1001] = {0};
float length[1001][1001];
int ally = 0;
int one = 0;
int n, r;

int dfs(int start){
    int count = 0;
    visited[start] = 1;
    for(int i = 0; i < n; ++i){
        if(visited[i] == 1)continue;
        if(length[start][i] <= r){
            count++;
            dfs(i);
        }
    }
    if(count == 0)return 0;
    else return 1;
}
int main(){
    int x[1001]={0};
    int y[1001]={0};
    
    scanf("%d %d", &n, &r);
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
        if(dfs(i) == 1)ally++;
        else one++;
    }
    printf("%d %d\n", one, ally);

    return 0;
}