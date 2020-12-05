#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define BASE 11
using namespace std;

string rands(int n){
    string s = "";
    s += (char) (rand()%9+'1');
    for(int i = 0; i<n; ++i) s += (char) (rand()%10+'0');
    return s;
}

vector<string> generate(int n){
    string s = rands(n);
    int pref = rand()%n;
    string k = rands(n-pref);
    string exp = s + k;
    vector<string> res;
    res.push_back(s);
    res.push_back(s.substr(s.length()-pref+1, pref) + k);
    res.push_back(exp);
    return res;
}

int main(){
    for(int i = 0; i<10; ++i) {
        auto a = generate(10);
        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }
}