class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool check(int grid[N][N] , int row , int col , int value){
        for(int i=0; i<N; i++){
            
            if(grid[row][i] == value || grid[i][col] == value){
                return false;
            }
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == value)
                return false;
        }
        return true;
    }
    bool solve(int grid[N][N]){
        
        for(int row=0; row<N; row++){
            for(int col=0; col<N; col++){
                
                
                if(grid[row][col] == 0){
                    for(int value=1; value<=9; value++){
                        if(check(grid , row , col , value)){
                            grid[row][col] = value;
                            // recursive call
                            bool checkNextSolution = solve(grid);
                            if(checkNextSolution)
                                return true;
                                
                            else
                                // back tracking
                                grid[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
        } 
    }
};