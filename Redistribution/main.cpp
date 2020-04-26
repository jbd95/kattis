#include<iostream>
#include<vector>

using namespace std;

int main() {
    double C, X, M;
    cin >> C >> X >> M;

    vector<vector<double>> stats;

    for(int i = 0; i < 6; i++)
    {
        double t1;
        double t2;
        cin >> t1 >> t2;
        stats.push_back({t1, t2});
    }

    int mph = -1;
    for(int i = 5; i >= 0; i--) {
        double res = (C / 2) - (X * (M / stats[i][0])) - (M / stats[i][1]);

        if(res >= 0.000001)
        {
            mph = stats[i][0];
            break;
        }
    }

    if(mph != -1)
    {
        cout << "YES " << mph << endl;
    }
    else
        cout << "NO" << endl;
}