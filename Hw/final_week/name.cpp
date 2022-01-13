#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    for(int i = 0; i < x; ++i){
        vector<int>check(26, 0);
        int alpha = 26;
        int t;
        cin >> t;
        int num = 0;
        for(int j = 0; j < t; ++j){
            string buffer;
            cin >> buffer;
            set<int> wait;
            for(int k = 0; k < buffer.length(); ++k){
                if(alpha == 0)break;
                if(check[buffer[i]-'a'] != 0){
                    
                }else if(k != buffer.length()-1){
                    wait.insert(buffer[i]-'a');
                }else {
                    alpha -= wait.size()+1;
                    check[buffer[i]-'a'] = ++num;
                    for(auto x:wait){
                        check[x] = num;
                    }
                    wait.clear();
                }
            }
        }
        cout << num << endl;
        num = 0;
        alpha = 26;
    }
}