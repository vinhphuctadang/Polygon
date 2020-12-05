#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

vector<int> team[20];
int solver[1000005];

int n, k;
int main(){
    cin >> n >> k;
    int maxBit = (1<<k)-1;

    for(int i = 0; i<n; ++i) {
        int b = 0;
        for(int j = 0; j<k; ++j) {
            int x;
            cin >> x;
            b = b*2+x;
        }
        team[b].push_back(i);
        solver[i] = b;
    }

    // for one problem
    if (n == 1) {
        if (team[0].size()) {
            cout << "YES";
            return 0;
        }
        cout << "NO";
        return 0;
    }
    // for multiple problems, exists 2 problems (at most) satisfying conditions
    for(int i = 0; i<n; ++i) {
        for(int b = 0; b<16; ++b) {
            int expected = b & (maxBit - solver[i]);
            for(auto p : team[expected]) {
                if (p != i) {
                    cout << "YES";
                    return 0;                    
                }
            }
        }
    }
    cout << "NO";
}