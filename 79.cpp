bool bfs(vector<vector<char>>& board, int i, int j, string& word, int s)
{
    if(s >= word.length()) return true;
    char tmp = board[i][j];
    board[i][j] = (char)0;
    
    if( (i > 0 && board[i-1][j] == word[s] && bfs(board, i-1, j, word, s+1))
    || (i < board.size() - 1 && board[i+1][j] == word[s] && bfs(board, i+1, j, word, s+1))
    || (j > 0 && board[i][j-1] == word[s] && bfs(board, i, j-1, word, s+1))
    || (j < board[i].size() - 1 && board[i][j+1] == word[s] && bfs(board, i, j+1, word, s+1)) )
        return true;
    
    board[i][j] = tmp;
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() <= 0) return true;
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == word[0] && bfs(board, i, j, word, 1))
                    return true;
            }
        }
        
        return false;
    }
};