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

vector<int> toBit(ll x) {
    vector<int> res;
    do {
        res.push_back(x % 2);
        x /= 2;
    } while (x);
    return res;
}
int main(){
    
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;    
        // cout << a << ' ' << b << ' ' << endl;

        auto va = toBit(a);
        auto vb = toBit(b);
        for(int i = 0; i<max(va.size(), vb.size())-va.size(); ++i) va.push_back(0);
        for(int i = 0; i<max(va.size(), vb.size())-vb.size(); ++i) vb.push_back(0);
        ll x = 0;
        for(int i = max(va.size(), vb.size())-1; i>=0; --i) {
            if (va[i] == vb[i] && va[i] == 1) {
                x += 1 << i;
            }
        }
        
        cout << (a^x)+(b^x) << endl;
    }
}