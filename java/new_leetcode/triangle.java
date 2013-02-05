import java.util.*;

public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(triangle.size() == 0)
          return 0;
        if(triangle.size() == 1)
          return triangle.get(0).get(0);
          
        int line_cnt = triangle.size();
        
        int[][] result = new int[line_cnt][line_cnt];
        result[0][0] = triangle.get(0).get(0);
        
        for(int i=1; i<line_cnt; i++) //get left edge
          result[i][0] = result[i-1][0] + triangle.get(i).get(0);
        
        for(int i=1; i<line_cnt; i++)  //get right edge
          result[i][i] = result[i-1][i-1] + triangle.get(i).get(i);
          
        for(int i=2; i<line_cnt; i++){
            for(int j=1; j<i; j++){
                result[i][j] = Math.min(result[i-1][j-1], result[i-1][j]) + triangle.get(i).get(j);
            }
        }
        
        int min_number = Integer.MAX_VALUE;
        for(int i=0; i<line_cnt; i++){
            if(min_number > result[line_cnt-1][i])
               min_number = result[line_cnt-1][i];
        }
        
        return min_number;
    }
}
