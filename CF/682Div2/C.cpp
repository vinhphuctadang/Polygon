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
ll T, n, m;
ll a[102][102];
ll b[102][102];
bool vis[102][102];
bool found = false;

int main(){
    cin >> T;
    while(T--) {
        cin >> n >> m;
        // cout << n << " " << m;
        for(int i = 1; i<=n; ++i) 
            for(int j = 1; j<=m; ++j) cin >> a[i][j];

        for(int i = 1; i<=n; ++i) {
            for(int j = 1; j<=m; ++j) {
                if (((i%2)^(j%2)) == 0) {
                    if (a[i][j] % 2) {
                        a[i][j] += 1;
                    }
                }
                else {
                    if (a[i][j] % 2 == 0) {
                        a[i][j] += 1;
                    }
                }
            }
        }
        for(int i = 1; i<=n; ++i) {
            for(int j = 1; j<=m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        // for(int i = 1; i<=n-1; ++i)
        //     for(int j = 1; j<=m-1; ++j) {

        //         if (a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1]) {
        //             if (a[i][j] == a[i+1][j+1]) 
        //                 a[i+1][j] = a[i][j+1] = a[i][j]+1;
        //             else 
        //                 a[i][j] += 1;
        //         }
        //     }

        // for(int i = 1; i<=n; ++i)
        //     for(int j = 1; j<=m; ++j) {
        //         if (a[i][j] == b[i-1][j] || a[i][j] == b[i][j-1]) {
        //             b[i][j] = a[i][j] + 1;
        //         }
        //         else {
        //             b[i][j] = a[i][j];
        //         }
        //     }
        // print();
        // found = false;
        // attempt(1, 1);
    }
}