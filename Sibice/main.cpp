#include<iostream>
#include<cmath>

using namespace std;

int sqr(int x, int y) {
    return sqrt(x*x + y*y);
}

int main() {
    int N, W, H;
    cin >> N >> W >> H;

    int box = sqr(W, H);
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        cout << (temp <= box ? "DA" : "NE") << endl;
    }
}