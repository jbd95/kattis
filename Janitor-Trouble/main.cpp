//Brahmagupta's formula
//https://en.wikipedia.org/wiki/Brahmagupta%27s_formula

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
    double sides[4];
    double s = 0;

    for(int i = 0; i < 4; i++)
    {
        cin >> sides[i];
        s += sides[i];
    }
    
    s /= 2;
    double res = 1;
    for(int i = 0; i < 4; i++)
        res *= (s - sides[i]);
    
    cout << setprecision(6) << fixed << sqrt(res) << endl;
}