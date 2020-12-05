#include <iostream>
#include <vector>
#define DD pair<double, double>
using namespace std;

DD vec(DD A, DD B) {
    return DD(B.first - A.first, B.second - A.second);
}
double product(DD A, DD B){
    return A.first * B.second - B.first * A.second;
}
bool isConvex(vector<DD> polygon){

    if (polygon.size() <= 2) {
        return true;
    }

    bool flag = false;
    DD currentVec = vec(polygon[0], polygon[1]);
    auto n = polygon.size();

    double currentProd;

    for(int i = 2; i<n; ++i) {
        auto u = i;
        auto v = (i + 1) % n;

        DD nextVec = vec(polygon[u], polygon[v]); 
        double nextProd = product(currentVec, nextVec);
        if (!flag) {
            currentProd = nextProd, currentVec = nextVec;
            continue;
        }

        if (currentProd * nextProd < 0) { // different sign
            return false; // not convex
        }
        currentProd = nextProd, currentVec = nextVec;
    }

    return true;
}

int main(){
    vector<DD> a;
    double x, y;
    while (cin >> x >> y) {
        a.push_back({x, y});
    }
    cout << (isConvex(a) ? "Convex" : "Concurve") << endl;
    return 0;
}