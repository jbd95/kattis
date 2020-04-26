#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<char, char> m;
    m['j'] = '*';
    m['t'] = '|';
    m['b'] = '$';
    for(int i = 0; i < n; i++) {
        stack<char> pack;
        string adv;
        cin >> adv;
        bool accept = true;

        for(int j = 0; j < adv.size(); j++)
        {
            bool found = false;

            switch(adv[j]) {
                case '$':
                case '|':
                case '*':
                    pack.push(adv[j]);
                    found = true;
                break;

                case 't':
                case 'j':
                case 'b':
                    while(!pack.empty() && !found)
                    {
                        char next = pack.top();
                        pack.pop();
                        if(next == m[adv[j]]) {
                            found = true;
                        }
                    }
                break;
                default:
                    found = true;
                break;
            }
            if(!found) {
                accept = false;
            }
        }

        accept = accept && pack.empty();
        cout << ((accept) ? "YES" : "NO") << endl;
    }
}