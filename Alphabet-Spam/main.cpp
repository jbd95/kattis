#include<iostream>
#include<cctype>
#include<iomanip>

using namespace std;

int main() {
    string s;
    cin >> s;

    double whitespace = 0, lower = 0, upper = 0, symbols = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
                upper += 1;
            else
                lower += 1;
        }
        else if(s[i] == '_')
        {
            whitespace += 1;
        }
        else
        {
            symbols += 1;
        }
    }


    cout << setprecision(6) << fixed << whitespace / s.size() << endl;
    cout << lower / s.size() << endl;
    cout << upper / s.size() << endl;
    cout << symbols / s.size() << endl;
}