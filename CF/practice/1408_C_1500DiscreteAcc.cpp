#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

ll a[100005];
ll n, l;

double position(double t){
    double res = 0, speed = 1;
    for(int i = 0; i < n; ++i) {
        if (a[i] / speed < t) {
            res += speed * t;
            break;
        }

        t -= a[i]/speed;
        speed += a[i];
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%I64d%I64d", &n, &l);
        for(int i = 0; i<n; ++i) { scanf("%I64d", &a[i]); }

        ll u = 0, v = 1000000000;
        while (u <= v) {
            int m = (u + v) / 2;
            find(1)
        }
        for(int i = 0; i<n; ++i) {

        }
    }
}