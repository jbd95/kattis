#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    int X = 0;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        X += pow(temp / 10, temp % 10);
    }

    cout << X << endl;
}