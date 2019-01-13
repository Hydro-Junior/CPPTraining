#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/**
    普通回溯法处理数独问题
*/
class Solution {
public:
    bool row[9][10],col[9][10];
    bool block[3][3][10];
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(block,0,sizeof(block));
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                char num = board[i][j];
                if(num != '.'){
                    row[i][num-'0'] = true;
                    col[j][num-'0'] = true;
                    block[i/3][j/3][num-'0'] = true;
                }
            }
        }
        dfs(board);
    }
    bool dfs(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j]=='.'){
                    for(int num = 1; num <= 9 ; num++){
                        if(!row[i][num] && !col[j][num] && !block[i/3][j/3][num]){
                            board[i][j] = num + '0';
                            row[i][num] = col[j][num] = block[i/3][j/3][num] = true;
                            if(dfs(board)) return true;//填num可以得到正解
                            else {//得不到正解的话，回溯，尝试其他方法
                                board[i][j] = '.';
                                row[i][num] = col[j][num] = block[i/3][j/3][num] = false;
                            }
                        }
                    }
                    return false;//有未填的数，不是正解
                }
            }
        }
        return true;//所有数都填好，得到正解
    }

};
int main()
{
    vector<vector<char>> input;
    Solution s;
    char cs[9][9] = {{'.','.','9','7','4','8','.','.','.'},
                {'7','.','.','.','.','.','.','.','.'},
                {'.','2','.','1','.','9','.','.','.'},
                {'.','.','7','.','.','.','2','4','.'},
                {'.','6','4','.','1','.','5','9','.'},
                {'.','9','8','.','.','.','3','.','.'},
                {'.','.','.','8','.','3','.','2','.'},
                {'.','.','.','.','.','.','.','.','6'},
                {'.','.','.','2','7','5','9','.','.'}};
    for(int i = 0 ; i < 9; i++){
        vector<char> sub ;
        for(int j = 0 ; j < 9; j ++){
            sub.push_back(cs[i][j]);
        }
        input.push_back(sub);
    }
    s.solveSudoku(input);
    for(vector<char> sub : input){
        for(char c : sub){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}
