#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#define ii pair<ll, ll>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define oo 1000000000000000000
#define X first
#define Y second
using namespace std;

ii a[100005];

int main(){
    ll n;
    cin >> n;
    for(int i = 0; i<n; ++i) { cin >> a[i].X; a[i].Y = i; }
    sort(a, a+n);
    ll sum = 0;
    for(int i = 0; i<n; ++i) { sum += a[i].X; }
    ll res = max((ll) -oo, sum);

    int rule = -1, block = -1, countBlock = 0, m = 0, remain = 0;

    for(int i = 0; i<n; ++i) {
        if (a[i].X < 0 || remain > 0) { 
            // add neg sign
            bool shouldLock = false;
            if (block == -1) {
                block = a[i].Y;
                countBlock ++;
            }
            else {
                if ((a[i].Y - block) % 2 == 0) {
                    // should lock
                    if (countBlock + 1 == n/2) {
                        remain++;
                        shouldLock = true;
                    }
                    else {
                        countBlock ++;
                    }
                }
            }
            if (!shouldLock) {
                sum += -2LL * a[i].X, m++; 
                if (remain) remain--;
            }
        }
        if ((n + m) % 3 == 1) {
            res = max(res, sum);
        }
    }
    cout << res;
}