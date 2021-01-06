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
    while(T--){
        string s;
        cin >> s;
        if (s.length()%2) { cout << "NO\n"; continue; }
        unordered_map<char, int> m;
        for(char c: s) m[c]++;
        if (m['('] > s.length()/2 || m[')'] > s.length()/2 || s[0] == ')' || s[s.size()-1]=='(') {
            cout << "NO\n"; 
        }
        else {
            cout << "YES\n";
        }
    }
}