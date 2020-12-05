#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#define ii pair<int, int>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

vector<ll> a[50005];
ll depth[100005], par[100005], dpRoot[50005][502], dp[50005][502];
bool vis[50005];
int n, k;

void dfs(int u, int len){
    vis[u] = 1;
    ll sum = 0;
    for(auto v: a[u]) {
        if (!vis[v]) {
            par[v] = u;
            dfs(v, len);
            sum += dpRoot[v][len-1];
        }
    }
    // cout << u << " " << len << " " << sum << endl; 
    dpRoot[u][len] = sum;
    vis[u] = 0;
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0; i<n-1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    // find dp including root first:
    for(int i = 0; i<=k; ++i) {
        
        if (i == 0) 
            for(int j = 1; j<=n; ++j) dpRoot[j][0] = 1;
        else {
            dfs(1, i);
        }
            
    }
    // clear
    for(int i = 1; i<=n; ++i) { vis[i] = 0, dp[i][0] = 1; }
    // sum up result
    queue<int> q;
    q.push(1);
    ll res = 0;
    while (q.size()){
        auto u = q.front();
        vis[u] = 1;
        // cout << u << " ";
        q.pop();
        if ( u == 1 ) {
            for(int i = 0; i<=k; ++i) { dp[u][i] = dpRoot[u][i]; }
        }
        else {
            for(int i = 1; i<=k; ++i) {
                if (i<2) { 
                    dp[u][i] = dpRoot[u][i] + dp[par[u]][i-1];
                }
                else {
                    dp[u][i] = dpRoot[u][i] + dp[par[u]][i-1] - dpRoot[u][i-2];
                }
            }
        }
        for(auto v : a[u]) if (!vis[v]) q.push(v);
    }
    for(int u = 1; u<=n; ++u) {
        // cout << u << " " << dp[u][k] << " " << endl;
        res += dp[u][k];
    } 
    cout << res / 2;
}