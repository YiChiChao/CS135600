#include <iostream>
#include <string>
#include <cstdlib>
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
        string sub = ch.substr(i, 5);
        std::reverse(sub.begin(), sub.end());
        b.m[id++] = stoi(sub);
    }
    b.l = id;
    return in;

}
ostream& operator<<(ostream& out,  BigInt b) {
    if(b.sign == -1)out << "-";
    out << b.m[b.l-1];
    for(int i = b.l-2; i >= 0; i--){
        out.width(5);
        out.fill('0');
        out << b.m[i];
    }
    return out;
}
BigInt BigInt::operator +(const BigInt &y) {
    BigInt x(*this);
    int i;
    long long h = 0;
    //plus the two num together
    for(i = 0; i < x.l || i < y.l || h; i++){
        //if the digit is o, then we cannot access the num, represent as zero
        h += (i < x.l) * x[i] * x.sign + (i < y.l) * y[i] * y.sign;
        x[i] = h % max;
        h /= max;
    }
    //the total digit
    x.l = i;
    //to check if the digit is nonzero
    for(; x.l > 1 && !x[x.l-1]; x.l--);
    //if the first num is negative, it is a negative num
    if(x[x.l-1] < 0){
        x.sign = -1;
    }else x.sign = 1;
    if(x[x.l - 1] >= 0){
        for(int j = 0; j < x.l; ++j){
            if(x[j] < 0){
                x[j+1]--;
                x[j] += max;
            }
        }
    }else{
        for(int i = 0; i < x.l; ++i){
            if(x[i] > 0){
                x[i+1]++;
                x[i] -= max;
            }
        }
    }
    for(int i = 0; i < x.l; ++i){
        x[i] *= x.sign;
    }
    for(; x.l > 1 && !x[x.l-1]; x.l--);
    if(x.sign == -1 && x.l == 1 && x[0] == 0) x.sign = 1;
    return x;
}

BigInt BigInt::operator -( const BigInt &y ) {
    BigInt x(*this);
    int i;
    long long h = 0;
    //plus the two num together
    for(i = 0; i < x.l || i < y.l || h; i++){
        //if the digit is o, then we cannot access the num, represent as zero
        h += (i < x.l) * x[i] * x.sign - (i < y.l) * y[i] * y.sign;
        x[i] = h % max;
        h /= max;
    }
    //the total digit
    x.l = i;
    //to check if the digit is nonzero
    for(; x.l > 1 && !x[x.l-1]; x.l--);
    //if the first num is negative, it is a negative num
    if(x[x.l-1] < 0){
        x.sign = -1;
    }else x.sign = 1;
    if(x[x.l - 1] >= 0){
        for(int j = 0; j < x.l; ++j){
            if(x[j] < 0){
                x[j+1]--;
                x[j] += max;
            }
        }
    }else{
        for(int i = 0; i < x.l; ++i){
            if(x[i] > 0){
                x[i+1]++;
                x[i] -= max;
            }
        }
    }
    for(int i = 0; i < x.l; ++i){
        x[i] *= x.sign;
    }
    for(; x.l > 1 && !x[x.l-1]; x.l--);
    if(x.sign == -1 && x.l == 1 && x[0] == 0) x.sign = 1;
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
