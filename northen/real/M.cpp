#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define BASE 11
using namespace std;

ll a[100005], pref[100005], cost[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i<=n; ++i) pref[i] = pref[i-1] + a[i];
    for(int i = 1; i<=n; ++i) cost[i] = cost[i-1] + pref[i];
    
}