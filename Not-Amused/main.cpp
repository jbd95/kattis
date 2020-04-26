#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {

    int day = 1;
    unordered_map<string, vector<double>> data;
    string line;

    while(cin.good())
    {
        getline(cin, line);
        istringstream iss(line);

        string command, name;
        double time;

        cin >> command;

        if(command == "OPEN") {
            continue;
        }
        else if(command == "CLOSE") {

            cout << setprecision(0) << fixed << "Day " << day << endl;

            vector<pair<string, double>> res;
            for(auto n : data) {
                res.push_back({n.first, n.second[1] * 0.1});
            }

            auto comp = [](auto p1, auto p2) {
                return p1.first < p2.first;
            };
            sort(res.begin(), res.end(), comp);

            for(auto cur : res) {
                cout << setprecision(2) << fixed << cur.first << " $" << cur.second << endl;
            }
            cout << endl;
            data.clear();
            day++;
            continue;
        }
        
        cin >> name >> time;
        if(command == "ENTER") {
            if(data.find(name) == data.end())
            {
                data[name] = vector<double>(2, 0);
            }
            data[name][0] += time;
        }
        else if(command == "EXIT") {
            data[name][1] += time - data[name][0];
            data[name][0] = 0;
        }
    }
}