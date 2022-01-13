#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
vector<int>visited(26, 0);
int total_check = 26;
map<int, int> check_word;
map<int, vector<char>> nonduplicate;
map<char, vector<int>> alpha;
int DFS(char i){
    int count = 1;
    visited[i - 'a'] = 1;
    //Scout << i << " is visited" << endl;
    total_check--;
    vector<int>words = alpha[i];
    for(auto x : words){
        if(total_check == 0)break;
        if(check_word[x] == 1)continue;
        check_word[x] = 1;
        //cout << x <<" " ;
        for(auto j : nonduplicate[x]){
            if(total_check == 0)break;
            if(visited[j - 'a'] == 1)continue;
            count++;
            count += DFS(j);
        }
    }
    //cout << i << ": " << count << endl;
    return count;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            string buffer;
            cin >> buffer;
            check_word.insert({i, 0});
            vector<char> duplicate;
            //cout << "p" << endl;
            for(int j = 0; j < buffer.length(); ++j){
                //cout << "in" << endl;
                if(alpha.find(buffer[j]) == alpha.end()){
                    //cout << "1" << endl;
                    duplicate.push_back(buffer[j]);
                    vector<int> words;
                    words.push_back(i);
                    alpha.insert(pair<char, vector<int>> (buffer[j], words));
                    
                }
                else if(alpha[buffer[j]].back() != i){
                    //cout << "3" << endl;
                    alpha[buffer[j]].push_back(i);
                    duplicate.push_back(buffer[j]);
                }
                //cout << "2" << endl;
                    
            }
            nonduplicate.insert({i, duplicate});
            duplicate.clear();
        }
        /*for(auto x : alpha){
            cout << x.first << ": " ;
            for(auto y: x.second){
                cout << y << " ";
            }cout << endl;
        }*/
        int group = 0;
        for(auto y : alpha){
            char index = y.first;
            if(total_check == 0)break;
            if(visited[index-'a'] == 1) continue;
            //cout << "into" << endl;
            DFS(index);
            group++;
        }
        cout << group << endl;
        alpha.clear();
        nonduplicate.clear();
        check_word.clear();
        visited.assign(26, 0);
        total_check = 26;
    }
}