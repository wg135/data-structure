public class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int row = board.length;
        //if(row != 10)
          // return false;
        int col = board[0].length;
        //if(col != 10)
          //  return false;
            
        int[] dup = new int[10];
        
        //check duplate in each row
       for(int ir=0; ir<row; ir++){
            for(int i=0; i<10; i++)
                dup[i] = 0;
            for(int i=0; i<9; i++){
                char c = board[ir][i];
                if(c == '.')
                  ++dup[0];
                 else{
                    int hash = c - '0';
                    if(dup[hash] == 1)
                        return false;
                    else
                        dup[hash]++;
                 } 
            }    
        }
        
        //check dupliate in each col
        for(int ic=0; ic<col; ic++){
            for(int i=0; i<10; i++)
                dup[i] = 0;
            for(int i=0; i<9; i++){
                char c = board[i][ic];
                if(c == '.')
                  ++dup[0];
                 else{
                   int hash = c - '0';
                   if(dup[hash] == 1)
                      return false;
                   else
                      dup[hash]++;
                 } 
            }    
        }
        
        //check duplicate in 3 * 3 grid
        for(int ir=0; ir<row; ir+=3){
            for(int ic=0; ic<col; ic+=3){
                for(int i=0; i<10; i++)
                    dup[i] = 0;
                for(int iir=0; iir<3; iir++){
                  for(int iic=0; iic<3; iic++){
                      char c = board[ir+iir][ic+iic];
                      if(c=='.')
                        ++dup[0];
                      else{
                          int hash = c - '0';
                          if(dup[hash] == 1)
                            return false;
                          else
                            dup[hash]++;
                      }
                      
                  }
                }    
            }
        }
       return true;
    }
}
