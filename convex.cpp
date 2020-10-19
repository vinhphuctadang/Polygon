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

    DD currentVec = vec(polygon[0], polygon[1]);
    DD nextVec = vec(polygon[1], polygon[2]);
    auto n = polygon.size();

    double currentProd = product(currentVec, nextVec);
    for(int i = 2; i<n; ++i) {
        auto u = i;
        auto v = (i + 1) % n;

        DD tmpVec = vec(polygon[u], polygon[v]); 
        double nextProd = product(nextVec, tmpVec);
        if (currentProd * nextProd < 0) { // different sign
            return false; // not convex
        }

        // next 
        currentProd = nextProd, currentVec = nextVec, nextVec = tmpVec;
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