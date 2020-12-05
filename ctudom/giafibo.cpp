#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

ll F[10000001];
int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n <= 2) {
        cout << 0;
    }
    else {
        F[0] = 0;
        F[1] = 0;
        F[2] = 0;
        for(int i = 3; i<=n; ++i) {
            F[n] = (a*F[n-1]%MOD + b*F[n-2]%MOD + c) % MOD;
            F[n-3] = F[n-2], F[n-2] = F[n-1], F[n-1] = F[n];
        }
        cout << F[n];
    }
}