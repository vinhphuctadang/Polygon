#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>
#include <math.h>
#define ll long long
using namespace std;

void exec(string c) {
    cout << "Executing: " << c << endl;
    system(c.c_str());
}

string intToString(int n)
{
    stringstream temp;
    temp << n;
    string s;
    temp >> s;
    return s;
}

void mkinput(ofstream& cout){

    // int maxN = 1000000000;
    // int n = 1000000;
    // cout << n << endl;

    // vector<int> a(10000);
    // for(int i = 0; i<a.size(); ++i) a[i] = rand()%maxN;
    // for(int i = 0; i<n; ++i) cout << a[rand()%a.size()] << " ";
    // cout << endl; // flushed
    // ll maxN = 1000000000;
    // ll x = rand()%maxN + 1;
    // ll y = rand()%maxN + 1;
    // ll w = rand()%(maxN-x)+1;
    // ll h = rand()%y;
 
    // cout << x << " " << y << " " << x+w << " " << y - h << endl;
    ll n = rand()%(500-5)+6;
    ll m = min(rand()%(n*(n-1)-n) + n, 100000LL);
    int a[500][500];
    memset(a, 0, sizeof(a));
    cout << n << " " << m << endl;
    for(int _ = 0; _<m; ++_){
        int u = rand() % n + 1;
        int v;
        do {
            v = rand() % n + 1;
        } while (u == v);
        cout << u << " " << v << endl;
        a[u][v] = 1;
    } 
    // ll n = 500;
    // ll m = 100000;
    // int v = 2;
    // cout << n << " " << m << endl;
    // for(int i = 0; i<m;++i) {
    //     cout << 1 << " " << v << endl;
    //     v = (v + 1);
    //     if (v > n) v = 2;
    // }
}

int main(int n, char* args[]){

    
    // CONFIG GOES HERE
    string workedScript = "break.cpp";
    string 
        id = "break";
    int start = 10, cnt = 1;

    // AUTOMATION CODE
    string cmd = string("g++ --std=c++14 ") + workedScript + " -o tempExe";
    exec(cmd);
    for(int i = start; i<=start+cnt-1; ++i) {
        srand(time(0));
        cout << "Generating test " << i << " -------------------------" << endl;
        string 
            path =  "./"+id+"/test" +intToString(i)+"/";
        string cmd;
        cmd = "mkdir -p " + path;
        exec(cmd);

        // create input
        ofstream ofs;
        ofs.open ("tempInp", ofstream::out);
        mkinput(ofs);
        ofs.close();
        
        // create output
        cmd = "./tempExe < tempInp > " + path + id + ".out";
        exec(cmd);

        // move input to desired folder
        cmd = "mv tempInp " + path + id + ".inp";
        exec(cmd);
    }

    exec("rm tempExe");
}