#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> visited(26,0);
int total_check = 26;
map<int,int> check_word;
map<int, vector<int>> nonduplicate;
map<char, int> alpha;
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        string buffer;
        cin >> buffer;
        check_word.insert({i,0});
        vector<char> duplicate;
        for(int j = 0; j < buffer.length();++j){
            if(alpha.find(buffer[i]) == alpha.end()){
                duplicate.push_back(buffer[i]);
                vector<int> words;
                words.push_back(i);
                alpha.insert(pair<char, vector<int>> )
            }
        }
    }
}