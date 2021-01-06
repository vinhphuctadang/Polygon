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

int T;
int main(){
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<ii> ans;
        while(n > 2) {
            int x = sqrt(n);
            if (x * x < n) ++x;
            for(int i = x+1; i < n; ++i) {
                ans.push_back(ii(i, n));
            }
            ans.push_back(ii(n, x));
            ans.push_back(ii(n, x));
            n = x;
        }

        cout << ans.size() << endl;
        for(auto it: ans) {
            cout << it.first << " " << it.second << endl;
        }
    }
}
