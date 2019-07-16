/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> sub(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    //1-9 to 0-8
                    int cur = board[i][j] - '0' - 1;
                    int subidx = 3 * (i / 3) + (j / 3);
                    if (row[i][cur] > 0 || col[j][cur] > 0 || sub[subidx][cur] > 0)
                        return false;
                    row[i][cur] = 1;
                    col[j][cur] = 1;
                    sub[subidx][cur] = 1;
                }
        return true;
    }
};
