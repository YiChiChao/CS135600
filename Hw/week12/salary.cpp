#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define MOD 1000000007
string str;
int main(){
    int x;
    int n;
    cin >> x;
    while(x--){
        cin >> n;
        cin >> str;
        long long count = str.length();
        for(int i = 1; i <= n; ++i){
            int times = atoi((str.substr(i-1, 1)).c_str());
            count = ((((count-i)*(times-1))%MOD + count)%MOD + MOD)%MOD;
            if(str.length() < n && times-1 >= 1){
                string sub = str.substr(i, str.length()-i);
                for(int j = 0; j < times-1 && str.length() < n; ++j){
                    str += sub;
                    //cout << str << endl;
                }  
            }
            
        }
        cout << count << endl;
    }
}