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
#define oo 1000000001
using namespace std;

int T;
int a[1003], b[1003];
int dp[102][102];
int pref_a[1003], pref_b[1003];

int main(){
    cin >> T;
    while(T--){
        int n, m;
        cin >> n;
        for(int i = 0; i<n; ++i) { cin >> a[i]; pref_a[i+1] = pref_a[i] + a[i]; }
        cin >> m;
        for(int i = 0; i<m; ++i) { cin >> b[i]; pref_b[i+1] = pref_b[i] + b[i]; }

        dp[0][0] = 0;
        int res = 0;
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j) {
                dp[i+1][j] = max(dp[i][j], pref_a[i+1] + pref_b[j]);
                dp[i][j+1] = max(dp[i][j], pref_a[i] + pref_b[j+1]);
            }
        cout << dp[n][m] << endl;
    }
}