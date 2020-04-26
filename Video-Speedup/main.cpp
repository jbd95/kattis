#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    int times[n];
    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }

    double res = 0;
    int last = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        res += (times[i] - last) * ((100.0 + (count * p)) / 100.0);
        last = times[i];
        count++;
        
    }

    res += (k - last) * ((100.0 + (count * p)) / 100.0);
    cout << setprecision(6) << fixed << res << endl;
}