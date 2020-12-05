// CF requires coding using PIKE, LOL
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

// double a, x, y;
int n, a[302];
unordered_map<int, vector<int>> order;
vector<ii> res;

vector<ii> bubble(int a[], int n) {
    
    vector<ii> res;
    for(int i = 0; i<n; ++i) cout << a[i] + 1 << " "; cout << endl;
    for(int i = 0; i<n; ++i) {
        for(int j = n-1; j >= i+1; --j) {
            if (a[j-1] > a[j]) {
                swap(a[j-1], a[j]);
                res.push_back(ii(j-1, j));
            }
        }
    }
    return res;
}

int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 0; i<n; ++i) { cin >> a[i]; }
    for(int i = 0; i<n; ++i) { int x; cin >> x; order[x].push_back(i); }

    

    for(int i = 0; i<n; ++i) { 
        int ord = order[a[i]][order[a[i]].size()-1];
        order[a[i]].pop_back();
        a[i] = ord;
    }

    auto res = bubble(a, n);
    cout << res.size() << endl;
    for(auto it: res) { cout << it.first+1 << " " << it.second+1 << endl; }
}