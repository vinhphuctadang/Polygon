#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>
#define ii pair<int, int>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

bool gte0(vector<ll>& a) {
    for(auto c: a) { if (c < 0) return false; }
    return true;
}

bool lte0(vector<ll>& a) {
    for(auto c: a) { if (c > 0) return false; }
    return true;
}

ll minArr(vector<ll>& a){
    ll mn = MAXN;
    for(auto c : a) { if (mn > c) mn = c; }
    return mn;
}

int main(){

    int n;
    vector<ll> a;
    scanf("%d", &n);
    for(int i = 0; i<n; ++i) {
        ll x = 0;
        scanf("%lld", &x);
        a.push_back(x);
    }

    if (n == 1) { cout << a[0]; return 0; }

    ll res = 0;
    if (gte0(a)) {
        ll mn = minArr(a);
        // cout << mn << " ";
        for(int i = 0; i<a.size(); ++i) { if (a[i] == mn) { a[i] = -a[i]; break; } }
        for(auto c: a) res += c;
    }
    else if (lte0(a)) {
        for(auto& c: a) c = -c;
        ll mn = minArr(a);
        for(auto& c: a) { if (c == mn) { c = -c; break; } }
        for(auto c: a) res += c;
    }
    else {
        for(auto c: a) {
            if (c < 0) res += -c; else res += c;
        }
    }
    printf("%lld", res);
}