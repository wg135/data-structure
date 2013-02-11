import java.util.*;

public class Solution {
    public int[] plusOne(int[] digits) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] result = new int[digits.length + 1];
        int carry = 1;
        
        if(digits == null || digits.length == 0)
          return digits;
          
        for(int i= digits.length-1; i>=0; i--){
            int tmp = digits[i] + carry;
            result[i+1] = tmp % 10;
            carry = tmp / 10;
        }
        
        if(carry > 0){
            result[0] = 1;
            return result;
        }
        else{
            int[] result1 = Arrays.copyOfRange(result, 1, result.length);
            return result1;
        }
        
    }
}
