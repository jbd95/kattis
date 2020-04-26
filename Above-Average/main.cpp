#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int C;
    cin >> C;

    cout << setprecision(3) << fixed;

    for(int i=0;i<C;i++) {
        int N;
        cin >> N;

        double avg = 0;
        double above = 0;
        int nums[N];
        for(int j=0;j<N;j++) {
            cin >> nums[j];
            avg += nums[j];
        }
        avg /= N;

        for(int j=0;j<N;j++) {
            if(nums[j] > avg) {
                above++;
            }
        }
        cout << (above / N) * 100  << "%" << endl;
    }
}