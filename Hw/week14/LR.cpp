#include <iostream>
#include <string>
using namespace std;
int main(){
    int x;
    int i = 0;
    int left = 0;
    int right = 0;
    string buffer;
    cin >> x;
    cin >> buffer;
    while(i < buffer.length()){
        if(buffer[i] == 'L'){
            left++;
        }else if(buffer[i] == 'R'){
            right++;
        }
        i++;
    }
    cout << left+right+1 << endl;
}