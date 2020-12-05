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

string a[102];
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i<= n; ++i) { cin >> a[i], a[i] = "#" + a[i]; }
    int res = 0;
    for(int i = 1; i<= m; ++i){
       
        vector<int> w(n+1, 0);
        for(int j = 1; j<=n; ++j) {
            int count = 0;
            for(int k = i; k <= m; ++k) {
                if (a[j][k] != '0') {
                    break;
                }
                count++;
            }
            w[j] = count;

        }
        // for(int j = 1; j<=n; ++j) cout << w[j] << " "; cout << endl;
        int lmost[102], rmost[102], tmpres = 0;
        lmost[0] = rmost[n+1] = -1;
        for(int j = 1; j<=n; ++j) {
            lmost[j] = j - 1; 
            while(lmost[j] != 0 && w[j] <= w[lmost[j]]) lmost[j] = lmost[lmost[j]];
        }

        for(int j = n; j>=1; --j) {
            rmost[j] = j+1;
            while(rmost[j] != n+1 && w[j] <= w[rmost[j]]) rmost[j] = rmost[rmost[j]];
        }
        
        for(int j = 1; j<=n; ++j) {
            if (w[j] > 0) tmpres = max(tmpres, (w[j] + rmost[j] - lmost[j] - 1) * 2);
        }
        res = max(tmpres, res);
    }
    cout << res;
}