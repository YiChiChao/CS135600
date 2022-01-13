#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int t;
    long long int coffee[200005]={0};
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        long long int m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            cin >> coffee[i];
            //save the number of coffee as prefix sum
        }
        int ans = -1;
        long long int L = 0, R = n+1;
        while(L < R){
            long long int day = (L+R)/2;
            long long int count = 0;
            if(day == 0)break;
            for(int i = 1; i <= day; ++i)count += coffee[i];
            int cycle = 0, minus = 1;
            for(int i = day+1; i <= n; ++i){
                cycle++;
                if(coffee[i] > minus) count += coffee[i]-minus;
                if(cycle == day){
                    cycle = 0;
                    minus++;
                }
            }
            //cout << count << endl;
            if(count >= m){
                ans = day;
                R = day;
            }
            else L = day+1;
            //cout << "== " << day <<"==" << endl;
        }
        cout << ans << endl;
        //cout << endl;
        //cout << "-----------------------------------------------" << endl;
        memset(coffee, 0, sizeof(coffee));
    }
}