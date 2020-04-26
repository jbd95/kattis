/*
    Summary:
    1) Use hash map to get a problem by its name
    2) Update problem information with each line of input
*/
#include<iostream>
#include<climits>
#include<unordered_map>
#include<sstream>

using namespace std;

struct Problem {
    bool solved = false;
    int time_solved = INT_MAX;
    int wrong_count = 0;
};

int main() {
    string line;
    unordered_map<string, Problem> m;

    while(cin.good()) {
        getline(cin, line);
        istringstream iss(line);

        int time;
        string prob, solved;

        iss >> time;

        if(time == -1) {
            int res = 0;
            int num_solved = 0;
            for(auto problem : m) {
                if(problem.second.solved) {
                    res += problem.second.time_solved;
                    res += 20 * problem.second.wrong_count;
                    num_solved++;
                }
            }
            cout << num_solved << " " << res << endl;
            return 0;
        }

        iss >> prob >> solved;

        m[prob].solved = (solved == "right") || m[prob].solved;

        if(solved == "right") {
            m[prob].time_solved = min(m[prob].time_solved, time);
        }
        else if(solved == "wrong") {
            m[prob].wrong_count++;
        }
    }
}