#include <iostream>
#include <string>
#include <set>
using namespace std;

struct person{
    int age;
    string name;
    person(const string& theName = "", const int& theAge = 0)
    :age(theAge),
    name(theName){}

    bool operator<(const person& t) const{
        person c(*this);
        if(c.age == t.age){
            if(c.name < t.name)return true;
            else return false;
        }else if(c.age < t.age)return true;
        else return false;
    }
    bool operator==(const person& t)const{
        return name == t.name && age == t.age;
    }
};
set<person>people;
int main(){
    int x;
    string buffer;
    person someone;
    cin >> x;
    for(int i = 0; i < x; ++i){
        cin >> buffer;
        if(buffer == "born"){
            cin >> someone.name >> someone.age;
            people.insert(someone);
        }else if(buffer == "find"){
            cin >> someone.name >> someone.age;
            if(people.count(someone)){
                cout << "YES" << endl;
            }else cout << "NO" << endl;
        }else if(buffer == "kill"){
            cin >> someone.name >> someone.age;
            people.erase(someone);
        }else if(buffer == "young"){
            someone = *(people.begin());
            cout << someone.name << " " << someone.age << endl;
        }/*else if(buffer == "print"){
            for(auto x:people){
                cout << x.name << " " << x.age << endl;
            }
        }*/
    }
}

/*int main(){
    person num1;
    person num2;
    cin >> num1.name >> num1.age;
    cin >> num2.name >> num2.age;
    if(num1 < num2){
        cout << "smaller." << endl;
    }
    else{
        cout << "bigger." << endl;
    }

}*/