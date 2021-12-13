#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <utility>
using namespace std;
set<pair<int, int>> myset;
vector<int> v;
int main(){
    int x;
    int num;
    int index = 0;
    string buffer;
    cin >> x;
    for(int i = 0; i < x ; ++i){
        cin >> buffer;
        if(buffer == "push_back"){
            cin >> num;
            v.push_back(num);
            myset.insert({num, index++});
        }
        else if(buffer == "pop_back"){
            if(!myset.empty()){
                myset.erase({v[(--index)], index});
                v.pop_back();
            }
            
        }
        else if( buffer == "min"){
            pair<int, int> tmp = (*myset.begin());
            if(!myset.empty()){
                cout << tmp.first << " " << tmp.second + 1 << endl;
            }
            
        }
        else if( buffer == "max"){
            if(!myset.empty()){
                pair<int, int> tmp = (*myset.rbegin());
                cout << tmp.first << " " << tmp.second + 1 << endl;
            }
        }
        else if(buffer == "find"){
            cin >> num;
            if(num <= myset.size()){
                cout << v[num-1] << endl;
            }
        }
        else if(buffer == "print"){
            for(auto x : myset){
                cout << x.first << endl;
            }
        }
    }
}