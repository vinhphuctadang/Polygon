#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

ll a[100005], F[100005];

int main(){
    int T;
    cin >> T;
    while (T--){
        ll n, x;
        cin >> n >> x;
        for(int i = 0; i<n; ++i) { cin >> a[i]; }
        sort(a, a+n);
        for(int i = n-1; i>=0; --i) {
            ll member = (x / a[i] + (x % a[i] != 0));
            ll nxt = i + member;
            ll u = 0;
            if (nxt >= n) u = 0; else u = F[nxt];
            F[i] = max(u+(member<=n-i), F[i+1]);
        }
        cout << F[0] << endl;
        // reset for next test case
        for(int i = 0; i<n; ++i) F[i] = 0;
    }
}