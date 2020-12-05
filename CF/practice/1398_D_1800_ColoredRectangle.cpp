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

ll a[3][202];
ll F[202][202][202];
ll R, G, B;
int main(){
    cin >> R >> G >> B;
    for(int i = 0; i<R; ++i) cin >> a[0][i]; sort(a[0], a[0] + R);
    for(int i = 0; i<G; ++i) cin >> a[1][i]; sort(a[1], a[1] + G);
    for(int i = 0; i<B; ++i) cin >> a[2][i]; sort(a[2], a[2] + B);
    ll res = 0;
    for(int i = 0; i<=R; ++i) 
        for(int j = 0; j<=G; ++j) 
            for(int k = 0; k<=B; ++k) {
                if (j < G && k < B) F[i][j+1][k+1] = max(F[i][j+1][k+1], F[i][j][k] + a[1][j] * a[2][k]);
                if (i < R && k < B) F[i+1][j][k+1] = max(F[i+1][j][k+1], F[i][j][k] + a[0][i] * a[2][k]);
                if (i < R && j < G) F[i+1][j+1][k] = max(F[i+1][j+1][k], F[i][j][k] + a[0][i] * a[1][j]);
                res = max(res, F[i][j][k]); 
            }
    cout << res;
}
// for some wrong implementation
// vector<ll> a[3];
// ll res, R, G, B;

// ii argProdMax(vector<int>& tmp, ll& mxSize){
//     ll mx = 0;
//     ii res;
//     for(int i = 0; i<tmp.size()-1; ++i)
//         for(int j = i+1; j<tmp.size(); ++j) {
//             if (tmp[i] != -1 && tmp[j] != -1 && tmp[i] * tmp[j] > mx) {
//                 mx = tmp[i] * tmp[j];
//                 res = ii(i, j);
//             }
//         }
//     mxSize = mx;
//     return res;
// }
// int main(){

//     cin >> R >> G >> B;
//     for(int i = 0; i<R; ++i) { int x; cin >> x, a[0].push_back(x); }
//     for(int i = 0; i<G; ++i) { int x; cin >> x, a[1].push_back(x); }
//     for(int i = 0; i<B; ++i) { int x; cin >> x, a[2].push_back(x); }
//     for(int i = 0; i<3; ++i) sort(a[i].begin(), a[i].end());
//     for(int i = 0; i<3; ++i)  {
//         for(int j = 0; j<a[i].size(); ++j) cout << a[i][j] << " "; 
//         cout << endl;
//     }
//     int end = 3;
//     ll res = 0;
    
//     while (end>1) {
//         vector<int> tmp;
//         for(int i = 0; i<3; ++i) 
//             if (a[i].size()>0) {
//                 tmp.push_back(a[i][a[i].size()-1]);
//             }
//             else {
//                 tmp.push_back(-1);
//             }

//         ll mxSize = 0;
//         auto idx = argProdMax(tmp, mxSize);
//         res += mxSize;

//         cout << a[idx.first][a[idx.first].size()-1] << " " << a[idx.second][a[idx.second].size()-1]  << endl;
//         a[idx.first].pop_back();
//         a[idx.second].pop_back();

//         end = 0;
//         for(int i = 0; i<3; ++i) end += (a[i].size() > 0);
//     }
//     cout << res;
// }