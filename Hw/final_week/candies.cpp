#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int x;
    cin >> x;
    for(int i = 0; i < x; ++i){
        vector<int> V(3,0);
        cin >> V[0] >> V[1]>> V[2];
        sort(V.begin(), V.end());
        //scernario of b is not big enough
        if(V[2] >= V[0]+V[1]){
            cout << V[0]+V[1] << endl;
        }else cout << (V[0]+V[1]+V[2])/2 << endl;
    }
}