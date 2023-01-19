#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<int>> &board, int n, int row, int col)
    {

        int x = row;
        int y = col;

        while (y >= 0)
        {
            if (board[x][y] == 1)
                return false;

            y--;
        }

        x = row;
        y = col;

        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
                return false;

            x--, y--;
        }

        x = row;
        y = col;

        while (x < n && y >= 0)
        {
            if (board[x][y] == 1)
                return false;
            x++, y--;
        }

        return true;
    }

    void solve(vector<vector<int>> &ans, vector<vector<int>> &board, vector<int> &v, int n, int col)
    {
        if (col == n)
        {
            ans.push_back(v);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            // check if we can place or not
            if (isSafe(board, n, row, col))
            {
                board[row][col] = 1;
                v.push_back(row + 1);
                solve(ans, board, v, n, col + 1);
                v.pop_back();
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> v;
        solve(ans, board, v, n, 0);
        return ans;
    }
};
void printGrid (vector<vector<int>> ans) 
    {
        int N = ans.size();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<ans[i][j]<<" ";
            }
        } 
    }
int main(){
    Solution s;
    vector<vector<int>> ans = s.nQueen(4);
    printGrid(ans);
    return 0;
}