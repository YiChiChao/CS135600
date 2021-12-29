#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 0x3a3a3a3a
#define Max(x, y) (x > y)? x:y
#define Min(x, y) (x < y)? x:y
using namespace std;
vector<pair<int, int>> guard;
int n, q;
int calculate(int delete_guard, vector<int> wall){
    vector<int> Wall_ = wall;
    for(int i = guard[delete_guard].first; i <= guard[delete_guard].second; ++i)Wall_[i]--;
    vector<int> prefix(n+1, 0);
    for(int i = 1; i <= n; ++i){
        prefix[i] = prefix[i-1]+((Wall_[i] == 1)? 1:0);
    }
    int minus = INF;
    int tmp;
    for(int i = 0; i < q; ++i){
        if(i != delete_guard){
            //minus = Min(minus, prefix[guard[i].second] - prefix[guard[i].first -1]);
            if(minus > prefix[guard[i].second] - prefix[guard[i].first -1]){
                minus = prefix[guard[i].second] - prefix[guard[i].first -1];
                tmp = i;
            }
        }
    }
    
    int full = 0;
    for(int i = guard[tmp].first; i <= guard[tmp].second; ++i){
        Wall_[i]--;
    }
    for(int i = 1; i <= n; ++i){
        if(Wall_[i] > 0){
            full++;
            //cout << "wa[" << i << "]>0" << endl;
        }
    }
    //cout << "full = " << full << endl;
    return full;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> q;
        vector<int> v(n+1, 0);
        
        for(int j = 0; j < q; ++j){
            int L, R;
            cin >> L >> R;
            guard.push_back(make_pair(L, R));
            for(int i = L; i <= R; ++i){
                v[i] += 1;
            }
        }
        int max = 0;
        int cal;
        for(int j = 0; j < q; ++j){
            if(max < (cal = calculate(j, v))){
                max = cal;
            }
        }
        cout << max << endl;
        guard.clear();
    }
}