#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    int num1, num2;
    string buffet;
    set <int> myset = {};
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> buffet;
        if(buffet == "print"){
            int i = 0;
            int arr[100005] = {0};
            for(const auto &s : myset){
                arr[i] = s;
                i++;
            }
            for(int index = 0; index < i; ++index){
                printf("%d%c", arr[index], (index == i-1)?'\n':' ');
            }
        }else if(buffet == "range_erase"){
            cin >> num1 >> num2;
            myset.erase(myset.lower_bound(num1), myset.upper_bound(num2));
        }else if(buffet == "min"){
            if(myset.size() == 0)continue;
            cout << *myset.begin() << endl;
        }else if(buffet == "insert"){
            cin >> num1;
            //std::set.insert can order the set and does not insert the repeated element
            myset.insert(num1);
        }else if(buffet == "sum"){
            num1 = 0;
            for(const auto &s : myset){
                num1 += s;
            }
            cout << num1 << endl;
        }
    }
}