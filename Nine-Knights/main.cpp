#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> moves = {
    {-2, 1}, 
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {-1, 2},
    {1, 2}
};

inline bool validatePiece(char board[5][5], int i, int j) {
    bool accepted = true;
    for(int k = 0; k < 8; k++)
    {
        bool valid = true;
        int x = i + moves[k][0];
        int y = j + moves[k][1];

        if(x < 0 || y < 0 || x > 4 || y > 4)
        {
            continue;
        }
        valid = valid && (board[x][y] == '.');
        accepted = accepted && valid;
    }
    return accepted;
}

int main() {
    char board[5][5];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    bool accepted = true;
    int knights_count = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == 'k') {
                knights_count++;
                accepted = accepted && validatePiece(board, i, j);
            }
        }
    }

    accepted = accepted && knights_count == 9;

    cout << (accepted ? "valid" : "invalid") << endl;
}