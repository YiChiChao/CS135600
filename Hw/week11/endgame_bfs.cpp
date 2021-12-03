#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int visited[1000][1000] = {0};
int go_x[4] = {0, 0, 1, -1};
int go_y[4] = {-1, 1, 0 , 0};
int target = 0;
int n, m;                                
queue<pair<int, int> > Q;
int x,y;
int check = 0;
char arr[1001][1001];

int bfs(){
    pair<int, int> now;
    int dist;
    while(!Q.empty()){
        now = Q.front();Q.pop();
        dist =Q.front().first;Q.pop();
        for(int i = 0; i < 4; ++i){
            int x = now.first + go_x[i];
            int y = now.second + go_y[i];
            if(x >= n || x < 0 || y >= m || y < 0){
                continue;
            }
            if(arr[y][x] == 'C')continue;
            if(arr[y][x] == 'T'){
                target--;
                if(target == 0)return dist+1;
            }
            arr[y][x] = 'C';
            Q.push({x, y});
            Q.push({dist+1, 0});
        }
    }
    return -1;
}
int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        //printf("%s\n", arr[i]);
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[j][i] == 'I'){
                Q.push({i, j});
                Q.push({0, 0});
            }
            else if(arr[j][i] == 'T') target++;
        }
    }
    cout << bfs() << "\n";
}
