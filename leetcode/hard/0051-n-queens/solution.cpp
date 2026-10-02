class Solution {
public:
    int size;
  vector<vector<string>> solutions;
  
  vector<string> createTowerMatrix(vector<vector<char>>&state){
      vector<string> mat;
      for(int row = 0; row < size; ++row){
          string currentRow(state[row].begin(),state[row].end());
          mat.push_back(currentRow);
      }
      return mat;
  }
  
  void backtrack(int row, unordered_set<int> & diagonals, unordered_set<int> & antiDiagonals,unordered_set<int>& cols, vector<vector<char>> & state){
      if(row == size){
          solutions.push_back(createTowerMatrix(state));
          return;
      }
      for(int col = 0; col <size; ++col){
          int currDiagonal = row -col;
          int currAntiDiagonal = row + col;
          if(cols.count(col) || diagonals.count(currDiagonal) || antiDiagonals.count(currAntiDiagonal)){
              continue;
          }
          cols.insert(col);
          diagonals.insert(currDiagonal);
          antiDiagonals.insert(currAntiDiagonal);
          state[row][col] = 'Q';
          backtrack(row+1, diagonals, antiDiagonals,cols, state);
          
          cols.erase(col);
          diagonals.erase(currDiagonal);
          antiDiagonals.erase(currAntiDiagonal);
          state[row][col] = '.';
      }
  }
    vector<vector<string>> solveNQueens(int n) {
    size = n;
    solutions.clear();
    vector<vector<char>> emptyMat(size, vector<char>(size,'.'));
    unordered_set<int> diagonals, antiDiagonals, cols;
    backtrack(0, diagonals, antiDiagonals, cols, emptyMat);
    return solutions;
    
    }
};