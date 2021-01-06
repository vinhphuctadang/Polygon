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

int main(){
    // 9 5 3 6 2 7 8 
    // 
    // 

    // F[ i, j ] = max(F[ i ][ j ], F [ x ] [ (j-a[i]+K) % K ])
    // Toi uu:
    // F[ r ] la do dai cac day dai nhat tu 1..i ma chia K du l
    // De thay F[a[0] % K] = 1
    // F[a[i] % K] = max(F[a[i] % K], F[ 0 ] + 1)
    // quan tam den max(F[i][0])
    // 

    
}