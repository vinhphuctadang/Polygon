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

ll n, m;
ii a[100005];
ll p[100005], suff[100005], res[100005];
int main(){
    cin >> n >> m;
    for(int i = 1; i<=m; ++i) { cin >> a[i].first; a[i].second = i; }
    bool can = true;
    ll sum = 0;
    // for(int i = 1; i<=m; ++i) cout << a[i].first << " ";
    for(int i = 1; i<=m; ++i) { sum += a[i].first; }
    can = (sum >= n);
    if (!can) { cout << -1; return 0; }
    for(int i = 1; i<=m; ++i) { if (i > n - a[i].first + 1) { can = false; break; } }
    if (!can) { cout << -1; return 0; }

    // sort(a+1, a+m+1);
    // reverse(a+1, a+m+1);

    suff[m+1] = 0;
    for(int i = m; i>=1; --i) {
        suff[i] = suff[i+1] + a[i].first;
    }
    // for(int i = m; i>=1; --i) { cout << suff[i] << " "; }
    // able to get
    for(int i = 1; i<=m; ++i) {
        cout << max((ll) i, n - suff[i] + 1) << " ";
    }
}