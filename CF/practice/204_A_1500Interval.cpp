#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

ll count(ll x){
    if (x == 0) return 1;
    
    string s;
    stringstream ss;
    ss << x; 
    ss >> s;

    ll res = 0;

    if (s.length() == 1) return x+1;

    for(int i = 1; i<s.length(); ++i) {
        if (i == 1) 
            res += 10;
        else {
            res += 9 * ((ll) pow(10, i-2));
        }
    }

    for(int i = 0; i<s.length(); ++i) {
        ll n = (s[i] - '0');
        if (i == 0) {
            res += (n - 1) * ((ll) pow(10, s.length()-i-2));
        }
        else if (i == s.length()-1) {
            res += (s[i] >= s[0]);
        }
        else {
            res += n * ((ll) pow(10, s.length()-i-2));
        }
    }
    return res;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << count(b) - count(a-1);
}