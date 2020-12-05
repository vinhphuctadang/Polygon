#include <iostream>
#define ii pair<long long, long long>
#define X first
#define Y second
#include <math.h>
using namespace std;

struct Triangle {
    ii _[3];
};

ii vec(ii A, ii B) {
    return ii(B.X-A.X, B.Y-A.Y);
}

bool onSegment(ii X, ii A, ii B){
    return 
        !(X.X < min(A.X, B.X) || X.X > max(A.X, B.X))
    &&  !(X.Y < min(A.Y, B.Y) || X.Y > max(A.Y, B.Y));
}

int direction(ii A, ii B, ii C){
    ii AB = vec(A, B), BC = vec(B, C);
    auto tmp = AB.X * BC.Y - BC.X * AB.Y;
    if (tmp < 0) {
        return -1;
    } 
    else if (tmp == 0) {
        return 0;
    }

    return 1;
}

bool segIntersect(ii A, ii B, ii C, ii D) {
    int a = direction(A, B, C), b = direction(A, B, D), c = direction(C, D, A), d = direction(C, D, B);
    // colinear case
    if (a == 0 && onSegment(C, A, B)) return true;
    if (b == 0 && onSegment(D, A, B)) return true;
    if (c == 0 && onSegment(A, C, D)) return true;
    if (d == 0 && onSegment(B, C, D)) return true;
    // normal cases
    return (direction(A, B, C) * direction(A, B, D) < 0) && (direction(C, D, A) * direction(C, D, B) < 0);
}

bool segIntersectTriangle(ii A, ii B, Triangle T) {
    for(int i = 0; i<2; ++i) 
        for(int j = i+1; j<3; ++j) {
            if (segIntersect(A, B, T._[i], T._[j])) 
                return true;
        }
    return false;
}
bool triangleIntersect(Triangle A, Triangle B) {
    for(int i = 0; i<2; ++i)
        for(int j=i+1; j<3; ++j) {
            if (segIntersectTriangle(A._[i], A._[j], B)) {
                return true;
            }
        }
    return false;
}
int main(){
    Triangle T[2];
    for(int i = 0; i<3; ++i) { cin >> T[0]._[i].X >> T[0]._[i].Y; }
    for(int i = 0; i<3; ++i) { cin >> T[1]._[i].X >> T[1]._[i].Y; }
    cout << (triangleIntersect(T[0], T[1]) ? "YES": "NO") << endl;
}