/*
    Summary:
    1) Use dp table to get mininum steps to reach each spot on the board
    2) Use Breadth-First-Search starting at knight position
*/
#include<iostream>
#include<climits>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    char board[N][N];
    int dp[N][N];
    bool visited[N][N];
    queue<vector<int>> q;
    int x = 0, y = 0;

    vector<vector<int>> moves = {
        {2,1},{2,-1},{-2,1},{-2,-1},
        {1,2},{1,-2},{-1,2},{-1,-2}
    };

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
            dp[i][j] = INT_MAX;

            if(board[i][j] == 'K') {
                x = i;
                y = j;
            }
            visited[i][j] = false;
        }

    dp[x][y] = 0;
    q.push({x, y, 0});
    while(!q.empty()) {
        auto pos = q.front();
        q.pop();

        int x = pos[0];
        int y = pos[1];

        if(visited[x][y])
            continue;

        visited[x][y] = true;
        dp[x][y] = min(dp[x][y], pos[2]);

        for(int k=0;k<8;k++) {
            int mx = x + moves[k][0];
            int my = y + moves[k][1];

            if(mx < 0 || mx >= N || my < 0 || my >= N || board[mx][my] == '#')
                continue;

            q.push({mx, my, pos[2] + 1});
        }
    }

    
    if(dp[0][0] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[0][0] << endl;
}