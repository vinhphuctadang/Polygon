#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define BASE 11
using namespace std;


ll PRE[1000006];

vector<ll> computeHash(string s) {
    vector<ll> res;
    res.push_back(0);
    for(int i = 1;i<=s.length();++i) {
        ll tmp = (res[i-1]*BASE % MOD + (s[i-1]-'0')+MOD) % MOD;
        res.push_back(tmp);
    }
    return res;
}


ll getHash(vector<ll>& a, int i, int j){
    return (a[j]-a[i-1]*PRE[j-i+1]%MOD+MOD) % MOD;
}

int longestLen(string a, string b) {
    auto hsh_a = computeHash(a);
    auto hsh_b = computeHash(b);
    int res = 0;
    for(int i = 1; i<=b.length(); ++i) {
        if (i > a.length()) break;
        if (getHash(hsh_b, 1, i) == getHash(hsh_a, a.length()-i+1, a.length())) {
            res = i;
        }
    }
    return res;
}

string nonLZ(string& a) {
    int i = 0;
    while (i < a.length() && a[i] == '0') i++;
    if (i >= a.length()) return "0";

    return a.substr(i, a.length()-i);
}
int main(){
    string a, b;
    cin >> a >> b;
    a = nonLZ(a);
    b = nonLZ(b);
    
    PRE[0] = 1;
    for(int i = 1; i<1000001; ++i) {
        PRE[i] = (PRE[i-1] * BASE) % MOD;
    }
    int len = longestLen(a, b);
    // cout << len;
    cout << a + b.substr(len, b.length()-len) << endl;
}