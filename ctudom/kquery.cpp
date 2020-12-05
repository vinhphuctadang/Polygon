#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

unordered_map<ll, unordered_map<ll, ll> > a;

void update(ll i, ll k) {
    while (i) {
        while (k) {
            a[i][k] ++;
            k -= k & (-k);
        }
        i -= i & (-i);
    }
}

ll get(ll i, ll k) {
    ll res = 0;
    while (i<=100000) {
        while (k<=100000) {
            res += a[i][k];
            k += k & (-k);
        }
        i += i & (-i);
    }
    return res;
}

int main(){
    
    ll n, x, q;
    cin >> n;
    for(int i = 1; i<=n; ++i) cin >> x, update(i, x);
    cout << get(1, 1);
    
    // cin >> q;
    // for(int i = 1; i<=q; ++i) {
    //     int l, r, k;
    //     cin >> l >> r >> k;
    //     cout << get(l, k) - get(r+1, k)  << endl;
    // }
}