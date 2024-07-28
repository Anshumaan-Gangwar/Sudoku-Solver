#include <iostream>
#include<vector>
using namespace std;

class solveSudoku{
    public:
    bool isValid(int x, int y, int num, vector<vector<int>> &board){
        //checking column validity
        for(int i = 0; i <= 8; i++){
            if(board[i][y] == num) return false;
            //checking row validity
            if(board[x][i] == num) return false;
            //sub sudoku
            //if(board[3*(x/3) + i/3][3*(y/3) + i%3] == num) return false;
            
        }

        int row = 0;
        int col = 0;
        // finding the first cell of sub 3*3 sudoku
        for(int i = x; i >= 0; i--){
            if(i % 3 == 0){
                row = i;
                break;
            } 
        }
        for(int j = y; j >= 0; j--){
            if(j % 3 == 0){
                col = j;
                break;
            } 
        }
        // traversing the sub sudoku
        for(int i = row; i <= row + 2; i++){
            for(int j = col; j <= col + 2; j++){
                if(board[i][j] == num) return false;
            }
        }
        
        return true;
    }

    bool helper(vector<vector<int>>& board){
        for(int i = 0; i <= 8; i++){
            for(int j = 0; j <= 8; j++){
                if(board[i][j] == 0){
                    //checking for the possible value to fill in blank space
                    for(int k = 1; k <= 9; k++){
                        if(isValid(i, j, k, board)){
                            board[i][j] = k;
                            if(helper(board) == false) board[i][j] = 0;
                            else return true;

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solve(vector<vector<int>>& board){
	    helper(board);
    }

    void printSol(vector<vector<int>> &board){
        cout << endl;
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
        cout << endl;
        }
    }
};

int main(){
    vector<vector<int>> board(9, vector<int>(9, 0));
    cout << "Give input" << endl;
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }
    solveSudoku s1;
    s1.solve(board);
    s1.printSol(board);

}