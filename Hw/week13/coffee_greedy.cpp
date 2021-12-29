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
            int tmp;
            cin >> tmp;
            coffee[i] = coffee[i-1] + tmp;
        }
        int day = 1;
        while(day <= n){
            long long int count = 0;
            for(int i = 1, j = 0; i <= n; i += day, ++j){
                if(i+day-1 <= n){
                    long long int tmp;
                    if((tmp = coffee[i+day-1] - coffee[i-1] - (j*day))>0){
                        count += tmp;
                        //cout << "coffee[i+day-1] = " << coffee[i+day-1] << " coffee[i-1] = " << coffee[i-1] << endl;
                        //cout << "count = " << count << endl;
                    }
                    else break;
                    
                }
                else{
                    long long int tmp;
                    if((tmp = coffee[n] - coffee[i-1] - (j*(n-i+1)))>0){
                        count += tmp;
                        //cout << "count = " << count << endl;
                        break;
                    }else break;
                }
            }
            if(count >= m){
                cout << day << endl;
                break;
            }
            else if(day == n)cout << "-1" << endl;
            day++;
            //cout << "== " << day <<"==" << endl;
        }
        //cout << "-----------------------------------------------" << endl;
        memset(coffee, 0, sizeof(coffee));
    }
}