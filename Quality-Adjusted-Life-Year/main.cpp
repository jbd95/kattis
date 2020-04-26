#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int N;
    double qaly = 0; 

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        double q, y;
        cin >> q >> y;

        qaly += q * y;
    }

    cout << setprecision(3) << fixed << qaly << endl;
}