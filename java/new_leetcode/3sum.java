import java.util.*;

public class Solution {
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        int i, j, k;
        int sum;
    
        
        if(num.length < 3)
          return result;
         
         Arrays.sort(num);
        
         for(i=0; i<num.length; i++){
             k = num.length - 1;
             j = i + 1;
             while(j<k){
                  sum = num[i] + num[j];
                  if(sum + num[k] < 0)
                    j++;
                  else if(sum + num[k] > 0)
                    k--;
                  else{
                    ArrayList<Integer> list = new ArrayList<Integer>();
                    list.add(num[i]);
                    list.add(num[j]);
                    list.add(num[k]);
                    if(result.contains(list) == false)
                      result.add(list); 
                    j++;
                    k--;
                  }    
                 
             }
         }
        
          return result;
        
    }
}
