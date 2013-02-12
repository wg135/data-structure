public class Solution {
    public int minPathSum(int[][] grid) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(grid == null || grid.length == 0)
          return 0;
          
        int row = grid.length;
        int col = grid[0].length;
        
        int[][] min = new int[row][col];
        
        min[0][0] = grid[0][0];
        for(int j=1; j<col; j++)
           min[0][j] = min[0][j-1] + grid[0][j];
        
        for(int i=1; i<row; i++)
           min[i][0] = min[i-1][0] + grid[i][0];
           
        for(int i=1; i<row; i++){
          for(int j=1; j<col; j++){
              min[i][j] = Math.min(min[i-1][j], min[i][j-1]) + grid[i][j];
          }
        }  
        return min[row-1][col-1];
    }
}
