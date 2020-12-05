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
#define MOD 1199999993
#define BASE 31
#define MAXN 10000000001
using namespace std;

ll hsh[1000006], reverseHsh[1000006];
ll powBase[1000006];
char tmp[1000006];

int pal(string& s){
    // compute hash 
    for(int i = 1; i<= s.length(); ++i) { hsh[i] = (hsh[i-1] * BASE + s[i-1] - 'a') % MOD; }
    reverse(s.begin(), s.end());
    for(int i = 1; i<= s.length(); ++i) { reverseHsh[i] = (reverseHsh[i-1] * BASE + s[i-1] - 'a') % MOD; }
    int res = 0;
    // scanf for pref that should have palindrom
    for(int i = s.length(); i >= 1; --i) {
        if (hsh[i] == (reverseHsh[s.length()] - reverseHsh[s.length()-i] * powBase[i] % MOD + MOD) % MOD) {
            return i;
        }
    }
    return 0;
}

int main(){
    int T;
    powBase[0] = 1;
    for(int i = 1; i<= 1000001; ++i) powBase[i] = powBase[i-1] * BASE % MOD;

    scanf("%d", &T);
    while(T--){
        scanf("%s", tmp);
        string s(tmp);
        int mxPrefPal = 0;
        for(int i = 1; i<=s.length()/2; ++i) if (s[i-1] == s[s.length()-i]) mxPrefPal++; else break;

        if (mxPrefPal == s.length()/2) { printf("%s\n", s.c_str()); continue; }
        string mid = s.substr(mxPrefPal, s.length() - 2 * mxPrefPal);
        string pref = s.substr(0, mxPrefPal), 
            suff = s.substr(s.length()-mxPrefPal, mxPrefPal);
        string tmpstr = mid;
        int lmx = pal(tmpstr), rmx = pal(tmpstr);
        // cout << lmx << " " << rmx << " ";
        if (lmx > rmx) {
            mid = mid.substr(0, lmx);
        }
        else {
            mid = mid.substr(mid.length()-rmx, rmx);
        }
        printf("%s%s%s\n", pref.c_str(), mid.c_str(), suff.c_str());
    }
}