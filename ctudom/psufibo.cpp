#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <math.h>
#define ll long long
#define a2D unordered_map<ll, unordered_map<ll, ll>>
#define BASE 11
using namespace std;

ll MOD = 1;
a2D mul(a2D& a, a2D& b) {
    a2D c;
    for(int i = 0; i<2; ++i) {
        for(int j = 0; j<2; ++j) {
            c[i][j] = 0;
            for(int k = 0; k<2; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
        }
    }
    return c;
}

a2D powMat(a2D& a, ll n) {
    if (n == 1) return a;
    auto tmp = powMat(a, n/2);
    tmp = mul(tmp, tmp);
    if (n % 2) tmp = mul(tmp, a);
    return tmp;
}

int main(){
    
    a2D A;
    A[0][0] = 0, A[0][1] = A[1][0] = A[1][1] = 1;
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    MOD = (ll) pow(10, m);
    
    if (n == 0) {
        cout << a; 
    } 
    else if (n == 1) {
        cout << b;
    }
    else {
        a2D p = powMat(A, n-1);
        ll res = (p[1][0] * a % MOD + p[1][1] * b % MOD) % MOD;
        cout << res;
    }
}
