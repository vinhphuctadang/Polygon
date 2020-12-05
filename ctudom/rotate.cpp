#include <iostream>
#define ii pair<double, double>
#define X first
#define Y second
#define sqr(x) (x)*(x)
#include <math.h>
using namespace std;

ii rect[4];
ii A, B;
int main(){
    cin >> A.X >> A.Y >> B.X >> B.Y;
    rect[0] = ii(A.X, A.Y);
    rect[1] = ii(A.X, B.Y);
    rect[2] = ii(B.X, A.Y); 
    rect[3] = ii(B.X, B.Y);
    
    double a = abs(B.X-A.X), b = abs(B.Y-A.Y);
    ii vec = ii(B.X-A.X,B.Y-A.Y);
    double c = sqrt(sqr(vec.X) + sqr(vec.Y));
    
    double 
        h = (a*b) / c,
        c_ = (a*a) / c;

    cout.precision(5);
    cout.setf(ios_base::fixed);
    cout << A.X << ' ' << A.Y << endl;
    cout << A.X+h << ' ' << A.Y-c_ << endl;
    cout << A.X << ' ' << A.Y - c << endl;
    cout << A.X-h << ' ' << A.Y-(c-c_) << endl;
}