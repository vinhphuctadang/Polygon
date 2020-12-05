#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

unordered_map<int, unordered_map<int, int>> a;
vector<pair<int, int>> e;

int x, y, n, m;
int vis[1003];
int par[1003];

int cyclic(int u){
    vis[u] = 1;
    for(auto vc : a[u]) {
        int v = vc.first, c = vc.second;
        if (vis[v] != 2 && ((u != x && v != y) || c > 0)) {
            par[v] = u;
            if (vis[v] == 1)
                return v;
            int tmp = cyclic(v); 
            if (tmp) return tmp;
        }
    }
    vis[u] = 2;
    return 0;
}

bool anyCycles(vector<pair<int,int>>& cycle){
    for(int i = 1; i<=n; ++i) vis[i] = 0;
    for(int i = 1; i<=n; ++i) 
        if (vis[i] == 0) {
            par[i] = -1;
            int v = cyclic(i);

            if (v == 0) continue;

            int lst = v;
            while(par[v] != lst) {
                cycle.push_back(pair<int,int>(par[v], v));
                // cout << par[v] << " " << v << endl;
                v = par[v];
            }
            cycle.push_back(pair<int,int>(lst, v));
            
            return true;
        }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u][v]++;
        e.push_back(pair<int, int>(u, v));
    }

    // find cycle
    vector<pair<int, int>> cycle;

    if (!anyCycles(cycle)) {
        cout << "CO";
        return 0;
    }
    
    vector<pair<int, int>> _;
    // for each in cycle
    for(auto tmp : cycle) {
        x = tmp.first, y = tmp.second;
        // cout << x << " " << y << endl;
        a[x][y] --;
        if (!anyCycles(_)) {
            cout << "CO";
            return 0;
        }
        a[x][y] ++;
    }
    cout << "KHONG";
}