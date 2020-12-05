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

ll a[3];
int main(){
    cin >> a[0] >> a[1] >> a[2];
    ll res = 0, mn = 0;
    sort(a, a+3);
    if (a[2] >= (a[0]+a[1])*2)
        res = a[0]+a[1];
    else {
        // 
    }
    cout << res;
}