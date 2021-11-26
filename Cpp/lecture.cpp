#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Rational{
public:
    //constructor
    Rational() : numer{0}, denom{1} {}
    Rational(int n) : numer{n}, denom{1} {}
    Rational(int n, int d) : numer{n}, denom{d} {}
    void show() const{
        cout << numer << "/" << denom << endl;
    }

    Rational &operator = (const Rational &q){
        numer = q.numer;
        denom = q.denom;
        return *this;
    }
    //
private:
    int numer;
    int denom;
};

int main(){
    Rational q1;
    Rational q2()
}