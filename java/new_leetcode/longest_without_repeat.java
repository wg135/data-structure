import java.util.*;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
    int[] table = new int[256];
    Arrays.fill(table, 0);
    int sum = 0;
    int tmp = 0;
    int curr = 0;
    
    if(s == null || s.equals("") || s.equals(" "))
      return 0;
     
    for(int next = 0; next < s.length(); next++){
      table[(int)s.charAt(next)] += 1;
      if(table[(int)s.charAt(next)] == 1){
          tmp += 1;
          if(tmp > sum)
            sum = tmp;
      }
      else{
          Arrays.fill(table, 0);
          tmp = 0;
          curr += 1;
          next = curr - 1;
      }
    }
    
    return sum;
    }
}
