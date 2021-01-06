// TLE
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
#define X first
#define Y second
#define ll long long
#define MOD 1000000007
#define BASE 11
#define MAXN 10000000001
using namespace std;

ll a[200005], res[200005];
ll tup;
ll tmp[1000006], m[1000006];
bool vis[1000006];
ll num[200005];
int n, q;
vector<pair<ii, int> > qs;

bool cmp(pair<ii, int> a, pair<ii, int> b) {
    if (a.X.X / tup != b.X.X / tup) 
        return a.X.X / tup < b.X.X / tup;
    if (a.X.X != b.X.X) 
        return a.X.X < b.X.X;
    return a.X.Y < b.X.Y;
}
 
ll sqr(ll x) { return x * x; }
 
int main(){
 
    scanf("%d%d", &n, &q);
    for(int i = 0; i<n; ++i) scanf("%I64d", &a[i]);

    for(int i = 0; i<q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        qs.push_back(pair<ii, int>(ii(l-1, r-1), i));
    }
 
    tup = sqrt(n);
    sort(qs.begin(), qs.end(), cmp);
 
    ii lst;
    ll tmpsum = 0;

    for(int i = 0; i<qs.size(); ++i) {

    int cnt = 0;
    // cout << qs[i].X.X+1 << " " << qs[i].X.Y+1 << endl << endl;
    if (i == 0) {            
        for(int k = qs[i].X.X; k<=qs[i].X.Y; ++k) { 
            m[a[k]]++;
            if (!vis[a[k]]) { 
                vis[a[k]] = 1;
                num[cnt++] = a[k];
            }
        }
        for(int k = 0; k < cnt; ++k) {
            int x = num[k];
            tmpsum += num[k] * m[num[k]] * m[num[k]], 
            vis[num[k]] = 0; 
        }// cout << it.X << "^2*" << it.Y << " "; }
        res[qs[i].Y] = tmpsum;
        lst = qs[i].X;
        // break;
        continue;
    }

    // cout << "query " << i+1 << ", "<< lst.X << " " << lst.Y << ", " << qs[i].X.X << " " << qs[i].X.Y << endl;
    if (qs[i].X.X<lst.X) {
        for(int k = qs[i].X.X; k < lst.X; ++k) { 
            tmp[a[k]]++; 
            if (!vis[a[k]]) { 
                vis[a[k]] = 1;
                num[cnt++] = a[k];
            }
        } // cout << a[k] << " "; } cout << endl;
    }
    else {
        for(int k = lst.X; k < qs[i].X.X; ++k) { 
            tmp[a[k]]--; 
            if (!vis[a[k]]) { 
                vis[a[k]] = 1;
                num[cnt++] = a[k];
            }
        } // cout << a[k] << " "; } cout << endl;
    }
    if (qs[i].X.Y<lst.Y) {
        for(int k = lst.Y; k>qs[i].X.Y; --k) { 
            tmp[a[k]]--; 
            if (!vis[a[k]]) { 
                vis[a[k]] = 1;
                num[cnt++] = a[k];
            }
        } //cout << a[k] << " "; } cout << endl;
    }
    else {
        for(int k = qs[i].X.Y; k>lst.Y; --k) { 
            tmp[a[k]]++; 
            if (!vis[a[k]]) { 
                vis[a[k]] = 1;
                num[cnt++] = a[k];
            }
        } 
    }


    for(int k = 0; k<cnt; ++k) {
        tmpsum += (2 * m[num[k]] * tmp[num[k]] + sqr(tmp[num[k]])) * num[k];
        m[num[k]] += tmp[num[k]], tmp[num[k]] = 0, vis[num[k]] = 0;
    }

    res[qs[i].Y] = tmpsum;
    lst = qs[i].X;
    }
 
    for(int i = 0; i < q; ++i) printf("%lld\n", res[i]);
    // }
}