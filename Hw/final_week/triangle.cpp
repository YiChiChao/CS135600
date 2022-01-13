#include <iostream>
#include <vector>
#include <string>
#define Max(x, y) (x > y)? x : y
using namespace std;
vector<long long int> prefix(100000, 0);
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        int a,b,c,d;
        long long int count = 0;
        cin >> a >> b >> c >> d;
        //prefix sum
        for(int j = a+b; j <= b+c+1; ++j){
            int tmp = 0;
            //when the sum of two side is between c and d
            //the sum cannot be equal to c
            //since a+b > c
            if(j > c && j <= d){
                tmp = j - c;
            }else if(j > d){
                tmp = d - c +1;
            }
            prefix[j] = prefix[j-1] + tmp;
            //cout << prefix[j] << " " ;
        }
        //cout << endl;
        for(int j = a; j <= b; ++j){
            int min = j + b;
            int max = j + c;
            //cout << "add : " << prefix[max] - prefix[min-1] << endl;
            count += prefix[max] - prefix[min-1];
        }
/*          if(max < c || min > d)continue;
            else if(max >= c && max <= d){
                int tmp;
                if(c > min)tmp = max - c +1;
                else if(min > c)tmp = max - min + 1;
                else tmp = max - c;
                count += tmp;
            }else if(min > d){
                int tmp = d - min + 1;
                count += tmp;
            }
        }*/
        cout << count << endl;
        prefix.assign(100000, 0);
    }
}