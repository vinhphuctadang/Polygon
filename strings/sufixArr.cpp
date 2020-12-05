#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#define ll long long
#define si pair<string, int>
#define MOD 1000000007
#define BASE 11
using namespace std;

vector<si> a;
int main(){
    string s;
    cin >> s;
    for(int i = 0; i<s.length();++i) a.push_back(si(s.substr(i, s.length()-i), i));
    sort(a.begin(), a.end());
    for(int i = 0; i<a.size(); ++i) {
        cout << a[i].second << " " << a[i].first << endl;
    }
}