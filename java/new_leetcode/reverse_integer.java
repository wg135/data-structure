public class Solution {
    public int reverse(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int result = 0;
        boolean neg = false;
        
        if(x < 0){
            x = -x;
            neg = true;
        }
        
        while(x > 0){
            result = result * 10 + x % 10;
            x = x / 10;
        }
        
        if(neg == true)
          result = -result;
          
        return result;  
        
    }
}
