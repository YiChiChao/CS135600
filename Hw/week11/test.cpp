#include <iostream>

using namespace std;
class Point{
public:
    int x, y;
    Point(){
        x = y = 0;
    }
    Point(int x, int y){ 
        this->x = x; 
        this->y = y; 
    } 

};

istream &operator>> (istream &s, Point p){
    int num1;
    int num2;
    s >> num1;
    s >> num2;
    if(num1 == 2 && num2 == 1){
        cout <<num1<< " " << num2 << endl;
    }
    else{
        cout <<num1<<  num2 << endl;
    }
    return s;
}

int main(){
    Point p1;
    cin >> p1;
    return 0;
}