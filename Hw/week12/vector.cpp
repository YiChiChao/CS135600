#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_INT 2147483647
#define MIN_INT -2147483648
int arr[200000] = {0};
int main(){
    int x;
    int min = MAX_INT, max = MIN_INT;
    int max_index, min_index;
    int num;
    int index = 0;
    string buffer;
    cin >> x;
    while(x--){
        int check = 0;
        cin >> buffer;
        if(buffer == "push_back"){
            cin >> num;
            arr[index++] = num;
            if(num >= max){
                max = num;
                max_index = index;
            }
            if(num == MAX_INT && check == 0){
                min = num;
                min_index = index;
                check = 1;
            }
            if(num < min){
                min = num;
                min_index = index;
            }
        }else if(buffer == "pop_back"){
            int max_check = 0;
            if(index == 0)continue;
            if(max == arr[--index] && max_index == index+1){
                max = MIN_INT;
                for(int i = index-1; i >= 0; --i){
                    if(arr[i] == MIN_INT && max_check == 0){
                        max = arr[i];
                        max_index = i+1;
                        max_check = 1;
                    }
                    else if(arr[i] > max){
                        max = arr[i];
                        max_index = i+1;
                    }
                }
            }
            if(min == arr[index] && min_index == index+1){
                if(min == MAX_INT)check = 0;
                min = MAX_INT;
                for(int i = 0; i < index; ++i){
                    if(arr[i] == MAX_INT && check == 0){
                        min = arr[i];
                        min_index = i+1;
                        check = 1;
                    }
                    else if(arr[i] < min){
                        min = arr[i];
                        min_index = i+1;
                    }
                }
            }
        }else if(buffer == "find"){
            cin >> num;
            if(num >= index || num <= 0)continue;
            cout << arr[num-1] << endl;
        }else if(buffer == "min"){
            if(index == 0)continue;
            cout << min << " " << min_index << endl;
        }else if(buffer == "max"){
            if(index == 0)continue;
            cout << max << " " << max_index << endl;
        }
    }
    return 0;
}