/*
    Summary:
    1) Keep track of the maximum price up until the current price
    2) If the new price is greater than the max price, update the max price and then continue
        if you update the max price, do not update res
    3) the result is the maximum of the max price - current price at each step
*/
#include<iostream>
#include<cmath>
#include<float.h>
#include<iomanip>

using namespace std;

inline double getPrice(int k, int p, int a, int b, int c, int d) {
    return p*(sin(a*k+b) + cos(c*k+d) + 2);
}

int main() {
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;

    double maxPrice = getPrice(1, p, a, b, c, d);
    double res = 0;
    for(int i = 2; i <= n; i++) {
        double curPrice = getPrice(i, p, a, b, c, d);

        if(curPrice > maxPrice) {
            maxPrice = curPrice;
        }
        else {
            res = max(res, maxPrice - curPrice);
        }
    }
    cout << setprecision(6) << fixed << res << endl;
}