#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define BASE 29
using namespace std;

ll PRE[1000006];


vector<ll> computeHash(string s) {
    vector<ll> res;
    res.push_back(0);
    for(int i = 1;i<=s.length();++i) {
        ll tmp = (res[i-1]*BASE % MOD + (s[i-1]-'a')+MOD) % MOD;
        res.push_back(tmp);
    }
    return res;
}

ll getHash(vector<ll>& a, int i, int j){
    return (a[j]-a[i-1]*PRE[j-i+1]%MOD+MOD) % MOD;
}

string getKey(string s) {
    auto hsh = computeHash(s);
    ll res = -1;
    for(int i = 1; i<=s.length(); ++i) {
        bool flag = 1;
        ll currentHash = getHash(hsh, 1, i);
        for(int j=i; j<s.length(); j += i) {
                if (
                    (s.length()-j < i && getHash(hsh, 1, s.length()-j) != getHash(hsh, j+1, s.length()))
                    ||
                    currentHash != getHash(hsh, j+1, j+i)
                ) {
                    flag = 0;
                    break;
                }
        }
        if (flag) {
            res = i;
            break;
        }
    }
    if (res < 0) res = s.length();
    return s.substr(0, res);
}

int main(){

    PRE[0] = 1;
    for(int i = 1; i<1000001; ++i) {
        PRE[i] = (PRE[i-1] * BASE) % MOD;
    }

    // string sn;
    // int n;
    // getline(cin, sn);
    // stringstream ss(sn);
    // ss >> n;

    // string u, v;
    // string s;
    // getline(cin, u);
    // getline(cin, v);
    // // cout << u << "\n";
    // for(int i = 0; i<u.length(); ++i) {
    //     if (u[i] == ' ') continue;
    //     s += (v[i] - u[i] + 26) % 26 + 96;
    // }

    // auto a = computeHash(s);

    cout << getKey("bowbowb");
}