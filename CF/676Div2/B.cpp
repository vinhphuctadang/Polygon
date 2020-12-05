#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#define ii pair<int, int>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
#define X first
#define Y second
using namespace std;
int n;
string a[202];
int _x[4] = {-1, 0, 0, 1}, _y[4] = {0, -1, 1, 0};

bool valid(int x, int y) {
    return (1<=x && x <= n && 1<=y && y<=n);
}

void solve(){
    ii cells[4] = {
        ii(1, 2),
        ii(2, 1),
        ii(n, n-1),
        ii(n-1, n)
    };

    vector<ii> ans;
    char c;

    string x;
    x += a[2][1], x += a[1][2];
    string y;
    y += a[n-1][n], y += a[n][n-1];
    // cout << x << " " << y << endl;
    if (x == "01" || x == "10") {
        if (y == "00") c = '1'; 
        else if (y == "11") c = '0';
        else c = '1';
    }
    else if (x == "00") 
        c = '0';
    else 
        c = '1';

    // cout << c << endl;

    for(int i = 0; i<2; ++i) {
        auto p = cells[i];
        if (a[p.X][p.Y] != c) 
           ans.push_back(p);
    }


    c = (c == '1' ? '0' : '1');

    for(int i = 2; i<4; ++i) {
        auto p = cells[i];
        if (a[p.X][p.Y] != c) {
            ans.push_back(p);
        }
    }

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.X << " " << it.Y << endl;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i<=n; ++i) cin >> a[i];
        for(int i = 1; i<=n; ++i) a[i] = '#' + a[i];
        
        solve();
    }
}