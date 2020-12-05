#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#define ll int 
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

int a[1000006], F[1000006], vis[1000006]; // visible (not visited)
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; ++i) { scanf("%d", &a[i]), vis[a[i]] = 1; }
    for(int i = 1; i<=n; ++i) {
        if (F[a[i]] == 0) F[a[i]] = 1;
        for(int j=a[i]*2; j<=1000000; j+=a[i]) {
            F[j] = max(F[a[i]]+1, F[j]); 
        }
    }
    ll res = 0;
    for(int i = 1; i<=n; ++i) res=max(res, F[a[i]]);
    printf("%d", res);
}
/** A STUPID WRONG ALGO ***********************************************
 * 
bool a[1000006];

ll LIS(vector<ll>& a){
    ll mxLen = 0;
    ll n = a.size();

    // for(auto c: a) cout << c << " "; cout << endl;
    vector<ll> L(n+1, 0), mx(n+1, 0);
    for(int i = 0; i<n; ++i) {
        ll l = 1, r = mxLen;
        while(l <= r) {
            ll m = (l+r)/2;
            if (a[i] % mx[m] == 0) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        if (l > mxLen) {
            mxLen = l, mx[l] = a[i];
        }
    }
    return mxLen;
}
int main(){
    ll n;
    // cin >> n;
    scanf("%d", &n);
    for(int i = 1; i<=n; ++i) { 
        ll x;
        scanf("%d", &x);
        a[x] = 1;
    }

    ll res = 0;
    for(int i = 1; i<=1000000; ++i) {
        if (a[i]) {
            vector<ll> tmp;
            tmp.push_back(i);
            a[i] = 0;
            for(int j=i*2; j<=1000000; j+=i) {
                if (a[j]) { tmp.push_back(j); a[j] = 0; } 
            }
            ll tmpres = LIS(tmp);
            res = max(tmpres, res);
        }
    }
    printf("%d", res);
    return 0;
}
*/