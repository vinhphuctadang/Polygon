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
  
bool used[30];
int k;

bool pal(string s){
    for(int i = 0; i<s.length()/2; ++i){
        if (s[i] != '?' && s[s.length()-i-1] != '?' && s[i] != s[s.length()-i-1]) {
            return false;
        }
    }
    return true;
}
 
char unused(){
    int n = k-1;
    while (n >= 0 && used[n]) n--;
    if (n < 0) return 'a';
    return n + 'a';
}
 
bool usedAll() {
    for(int i = 0; i<k; ++i) if (!used[i]) return false;
    return true;
}
 
int main(){
    
    string s;
    cin >> k >> s;
    if (!pal(s)) {
        cout << "IMPOSSIBLE";
    }
    else {
 
        for(int i = 0; i<s.length(); ++i) 
            if ('a' <= s[i] && s[i] <= 'z') used[s[i]-'a'] = 1;
        // cout << s;
        // mid
        if (s.length() % 2) {
            if (s[s.length()/2] == '?') { auto c = unused(); s[s.length()/2] = c, used[c-'a'] = 1; }
        }
 
        // left - right
        for(int i = 0; i<s.length()/2; ++i) {
            // cout << i << " ";
            if ((s[i] == '?') ^ (s[s.length()-i-1] == '?')) {
                char tmp = (s[i] == '?' ? s[s.length()-i-1] : s[i]);
                // cout << tmp << " ";
                s[i] = s[s.length()-i-1] = tmp;
                used[tmp-'a'] = 1;
            }
        }
 
        // // mid - outter
        for(int i = s.length()/2; i>=0; --i) {
            if (!(s[i] == '?' && s[s.length()-i-1] == '?')) continue;
            // cout << s[i] << " ";
            char tmp = unused();
            s[i] = s[s.length()-i-1] = tmp;
            used[tmp-'a'] = 1;
        }
 
        if (!usedAll()) { // havenot use 'a' yet
            cout << "IMPOSSIBLE";
        }
        else {
            cout << s;
        }
    }
}
