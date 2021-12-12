#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#define max 100000
using namespace std;
class BigInt{
    public:
        long long operator [](int i) const { return m[i]; }
        long long &operator [](int i) { return m[i]; }
        BigInt(){ l=1, m[0]=0; sign=1; }
        friend istream& operator>>(istream&, BigInt&);   
        friend ostream& operator<<(ostream&, BigInt);   
        BigInt operator +( const BigInt &y );  
        BigInt operator -( const BigInt &y );
    private:
        long long m[1000];
        int l;
        int sign;
};



istream& operator>>(istream & in,  BigInt & b) {
    string ch;
    in >> ch;
    if(*ch.begin() == '-'){
        b.sign = -1;
        ch.erase(0, 1);
    }else b.sign = 1;
    std::reverse(ch.begin(), ch.end());
    int id = 0;
    for(int i = 0; i < ch.length(); i += 5){
        string sub = ch.substr(0+id*5, 5);
        std::reverse(sub.begin(), sub.end());
        b.m[id++] = atoi(sub.c_str());
    }
    for(int i = id; i < 1000; i++){
        b.m[i] = 0;
    }
    b.l = id;
    return in;

}
ostream& operator<<(ostream& out,  BigInt b) {
    if(b.sign == -1)out << "-";
    out << b.m[b.l-1];
    for(int i = b.l-2; i >= 0; i--){
        out.width(5);
        out.fill(0);
        cout << "now = " << b.m[i] << endl;
        out << b.m[i];
    }
    return out;
}
BigInt BigInt::operator +(const BigInt &y) {
    BigInt &x = *this;
    int i;
    long long h = 0;
    for(i = 0; i < x.l || i < y.l || h; i++){
        h += y.m[i] * y.sign;
        cout << "x = " << x.m[i] << endl;
        cout << "y = " << y.m[i] << endl;
        x.m[i] += h % max;
        h /= max;
    }

    x.l = i;
    if(x.m[i-1] < 0){
        x.sign = -1;
    }else x.sign = 1;

    for(int j = 0; j < x.l; ++j){
        x.m[j] *= x.sign;
        cout << "x.m[j] = " << x.m[j] << endl;
        x.m[j] -= h;
        if(x.m[j] < 0){
            x.m[j] += max;
            h = 1;
        }
        else h = 0;
    }

    if(x.m[i-1] == 0) x.l--;
    return x;
}

BigInt BigInt::operator -( const BigInt &y ) {
    BigInt &x = (*this);
    int i;
    long long h = 0;
    for(i = 0; i < x.l || i < y.l || h; i++){
        h -= y.m[i] * y.sign;
        x[i] += h % max;
        h /= max;
    }
    x.l = i;
    for(int j = 0; j < x.l; ++j){
        if(y.m[j] < 0){
            x.m[j] += max;
            x.m[j+1] -= 1;
        }
        else if(y.m[j] > max){
            x.m[j] -= max;
            x.m[j+1] += 1;
        }
    }
    if(x.m[i-1] == 0)x.m[i-1]--;
    else if(x.m[i] != 0) x.m[i-1]++;
    return x;
}

int main(){
    BigInt x;
    BigInt y;
    while(cin >> x >> y){
        cout << "x == " << x << endl;
        cout << "y == " << y << endl;
        cout << x+y << endl;
        cout << x-y << endl;
        cout << "------------------------" <<endl;
    }
}
