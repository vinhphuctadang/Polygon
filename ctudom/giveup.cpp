#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#define ll long long
#define MOD 1000000007
#define BASE 11
using namespace std;

ll a[1000005], BIT[1000005], n;
unordered_map<ll, ll> SUFF, PREF;

void update(ll x) {
    while (x<=n) BIT[x]++, x+=x&(-x);
}
ll get(ll x) {
    ll res = 0;
    while (x) {
        res += BIT[x];
        x -= x&(-x);
    }
    return res;
}

int main(){
    cin >> n;
    
    ll cnt = 1;
    for(int i = 1; i<=n; ++i) cin >> a[i];
    for(int i = 1; i<=n; ++i) PREF[a[i]]++; // store prefix count of value a[i]

    // keep tracking and update
    ll res = 0;
    for(int i = n; i>=1; --i) {
        ll tmp = get(PREF[a[i]]-1);
        res += tmp;
        cout << tmp << " ";
        update(SUFF[a[i]]+1);
        SUFF[a[i]]++;
        PREF[a[i]]--;
    }
    cout << res;
}