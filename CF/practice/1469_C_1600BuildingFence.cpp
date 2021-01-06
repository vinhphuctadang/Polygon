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
ll a[100005];
int main(){
    cin >> T;
    while(T--){
        ll n, k, mx=0, mn=0;
        cin >> n >> k;
        for(int i = 0; i<n; ++i) cin >> a[i];

        bool flag = true;
        for(int i = 0; i<n; ++i) {
            if (i == 0) { 
                mx = a[0];
                mn = a[0];
            }
            else {
                mn = max(a[i], mn-k+1);
                mx = min(a[i]+k-1, mx+k-1);
                if (mn > mx) { flag = false; break; }
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}