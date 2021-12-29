#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    vector<int> prefix;
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n, p, k;
        int tmp;
        cin >> n >> p >> k;
        for(int j = 0; j < n; ++j){
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        if(v[0] > p){
            cout << "0" << endl;
            continue;
        }
        prefix.push_back(0);
        prefix.push_back(v[0]);
        int ans = 0;
        for(int product = 2; product <= n; ++product){
            if(product-k < 0)prefix.push_back(prefix[product-1] + v[product-1]);
            else prefix.push_back(prefix[product-k] + v[product-1]);
            if(prefix[product] > p && prefix[product-1] <= p){
                ans = product-1;
            }
            else if(product == n && prefix[product] <= p){
                ans = product;
            } 
        }
        cout << ans << endl;
        prefix.clear();
        v.clear();
    }
}