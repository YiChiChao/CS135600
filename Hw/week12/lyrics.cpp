#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<int, map<char, vector<string>>> bucket;
    int x;
    cin >> x;
    string buffer;
    for(int i = 0; i < x; ++i){
        cin >> buffer;
        int tmp = 0;
        char word;
        for(int i = 0; i < buffer.length(); ++i){
            if(buffer[i] == 'a' || buffer[i] == 'e' 
            || buffer[i] == 'i' || buffer[i] == 'o' 
            || buffer[i] == 'u'){
                tmp++;
                word = buffer[i];
            }
        }
        if(bucket.find(tmp) == bucket.end()){
            map<char, vector<string>> container;
            vector<string> map_words;
            map_words.push_back(buffer);
            container.insert(pair<char, vector<string>>(word, map_words));
            bucket.insert(pair<int, map<char, vector<string>>>(tmp, container));
        }
        else{
            if(bucket[tmp].find(word) == bucket[tmp].end()){
                vector<string> map_words;
                map_words.push_back(buffer);
                bucket[tmp].insert(pair<char, vector<string>>(word, map_words));
            }
            else{
                ((bucket[tmp])[word]).push_back(buffer);
            }
        }
        /*for(auto s:((bucket[tmp])[word])){
            cout << s << " " ;
        }
        cout << endl;*/
    }
    int compound = 0;
    int uncompound = 0;
    for(auto smap : bucket){
        int rest = 0;
        for(auto v : smap.second){
            compound += ((v.second).size())/2;
            rest += ((v.second).size())%2;
        }
        uncompound += rest/2;
    }
    //cout << "compound: " << compound << ", uncompound: " << uncompound << endl;
    int pairs = 0;
    if(uncompound <= compound){
        pairs += uncompound;
        compound -= uncompound;
        pairs += compound / 2;
    }
    else{
        pairs += compound;
    }
    cout << pairs << endl;
}