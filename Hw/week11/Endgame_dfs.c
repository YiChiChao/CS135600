#include<stdio.h>
int visited[1000][1000] = {0};
int go_x[4] = {0, 0, 1, -1};
int go_y[4] = {-1, 1, 0 , 0};

int tmp = 0;
int n, m;                                

int x,y;
int check = 0;
char arr[1001][1001];
int dfs(int start_x, int start_y){
    //printf("x = %d y = %d\n", start_x, start_y);
    
    int max = 0;
    if(start_x >= n || start_y >= m || start_x < 0 || start_y < 0)return 0;
    
    if(visited[start_y][start_x] == 1)return 0;
    if(arr[start_y][start_x] == 'C')return 0;
    visited[start_y][start_x] = 1;
    for(int i = 0; i < 4; ++i){
        if((tmp = dfs(start_x+go_x[i], start_y+go_y[i])) > max){
            //printf("x = %d y = %d\n", start_x +go_x[i], start_y+go_y[i]);
            max = tmp; 
       // printf("%d\n", max);
        }
    }
    if(max == 0 && arr[start_y][start_x] == '.')return max;
    else return max+1;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%s", arr[i]);
        //printf("%s\n", arr[i]);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m;++j){
            if(arr[i][j] == 'I'){
                y = i;
                x = j;
                check = 1;
                break;
            }
        }
        if(check == 1 )break;
    }
    //printf("%d %d\n", x, y);
    int ans = dfs(x,y);
    printf("%d\n", ans-1);
    return 0;
}