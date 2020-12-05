#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <math.h>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define oo 100000000000000
using namespace std;

ll a[100005], mnIT[100005*4], mxIT[100005*4];
ll n, d;

void build(ll id, ll l, ll r){
    if (l > r) {
        return;
    }
    if (l == r) {
        mnIT[id] = mxIT[id] = a[l];
        return;
    }
    ll m = (l + r) / 2;
    build(id*2, l, m);
    build(id*2+1, m+1, r);
    mnIT[id] = min(mnIT[id*2], mnIT[id*2+1]);
    mxIT[id] = max(mxIT[id*2], mxIT[id*2+1]);
}

ll getMn(ll id, ll l, ll r, ll u, ll v) {
    if (l > r) return oo;
    if (v < l || r < u) return oo;
    if (u <= l && r <= v) return mnIT[id];
    ll m = (l + r) / 2;
    return min(getMn(id*2, l, m, u, v), getMn(id*2+1, m+1, r, u, v));
}

ll getMx(ll id, ll l, ll r, ll u, ll v) {
    if (l > r) return -oo;
    if (v < l || r < u) return -oo;
    if (u <= l && r <= v) return mxIT[ id];
    ll m = (l + r) / 2;
    return max(getMx(id*2, l, m, u, v), getMx(id*2+1, m+1, r, u, v));
}

int main(){
    cin >> n >> d;
    for(int i = 1; i<=n; ++i) { cin >> a[i]; }
    build(1, 1, n);

    ll res = -oo;
    for(int i = 1; (i+d-1) <=n; ++i) {
        ll mx = getMx(1, 1, n, i, i+d-1),
            mn = getMn(1, 1, n, i, i+d-1);
        
        // cout << i << " " << i+d-1 << " " << mx << " " << mn << endl;
        res = max(res, mx-mn);
    }   
    cout << res;
}