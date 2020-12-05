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

int a[4003];
int F[4003][4003];
unordered_map<int, int> m;
int n;

int main(){
    cin >> n;
    int cnt = 0;
    // i have to discretize first
    for(int i = 1; i<=n; ++i) { cin >> a[i]; if (m[a[i]]==0) m[a[i]] = ++cnt; }
    for(int i = 1; i<=n; ++i) a[i] = m[a[i]];

    // then do dp
    // thinking: at index i, lets call F[i][j] as maximum lenngth of subsequence till i, and preceeding of a_i is number j (j, i mentioned again, not a_j)
    int res = 0;
    for(int i = 1; i<=n; ++i) {
        for(int j = 1; j<i; ++j) {
            F[i][a[j]] = F[j][a[i]]+1;
            res = max(res, F[i][a[j]]);
        }
    }
    cout << res + 1; // as we take the first one into account
}