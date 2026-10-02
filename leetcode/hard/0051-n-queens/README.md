# N-Queens

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The  **n-queens**  puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return  *all distinct solutions to the  **n-queens puzzle***. You may return the answer in  **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

 

 **Example 1:** 

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

```

 **Example 2:** 

```
Input: n = 1
Output: [["Q"]]

```

 

 **Constraints:** 

- 1 <= n <= 9

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 13.48%)  
**Memory:** 14.4 MB (beats 8.83%)  
**Submitted:** 2026-10-02T12:23:05.486Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/n-queens/)