bool usedinrow(vector<vector<char>> &board,int col,char num)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==num)
            return true;
    }
    return false;
}
bool usedincol(vector<vector<char>> &board,int row,int num)
{
    for(int j=0;j<9;j++)
    {
        if(board[row][j]==num)
            return true;
    }
    return false;
}
bool usedingrid(vector<vector<char>> &board,int row,int col,int num)
{
    row=row-(row%3);
    col=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i+row][j+col]==num)
                return true;
        }
    }
    return false;
}
bool issafe(vector<vector<char>> &board,int row,int col,int num)
{
    return !usedinrow(board,col,num) && !usedincol(board,row,num) && !usedingrid(board,row,col,num);
}
bool allclear(vector <vector<char>> &board,int &row,int &col )
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                row=i,col=j;
                return false;
            }
        }
    }
    return true;
}
bool sudoku(vector<vector<char>> &board)
{
    int row,col;
    if(allclear(board,row,col))
        return true;
    for(char num='1';num<='9';num++)
    {
        if(issafe(board,row,col,num))
        {
            board[row][col]=num;
            if(sudoku(board))
                return true;
             board[row][col]='.';
        }
    }
    return false;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
    
};
