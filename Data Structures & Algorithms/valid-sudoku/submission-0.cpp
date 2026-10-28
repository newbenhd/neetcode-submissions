class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {  // rule 1
            unordered_set<char> set;
            for (int col = 0; col < board[row].size(); col++) {
                char item = board[row][col];
                if (item == '.') continue;
                if (set.find(item) != set.end()) return false;
                set.insert(item);
            }
        }
        for (int col = 0; col < board.size(); col++) {
            unordered_set<char> set;
            for (int row = 0; row < board.size(); row++) {
                char item = board[row][col];
                if (item == '.') continue;
                if (set.find(item) != set.end()) return false;
                set.insert(item);
            }
        }
        for (int rowStep = 0; rowStep < 9; rowStep += 3) {
            for (int colStep = 0; colStep < 9; colStep += 3) {
                unordered_set<char> set;
                for (int row = rowStep; row < rowStep + 3; row++) {
                    for (int col = colStep; col < colStep + 3; col++) {
                        char item = board[row][col];
                        if (item == '.') continue;
                        if (set.find(item) != set.end()) return false;
                        set.insert(item);
                    }
                }
            }
        }
        return true;
    }
};
