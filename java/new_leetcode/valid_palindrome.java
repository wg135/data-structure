import java.util.*;

public class Solution {
    public boolean isPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        char[] tmp = s.toCharArray();
        int left = 0;
        int right = tmp.length - 1;
        
        while(left <= right){
            if(!isalpha(tmp[left])){
                left++;
                continue;
            }
            
            if(!isalpha(tmp[right])){
                right--;
                continue;
            }
            
            if( Character.toLowerCase(tmp[left++]) !=  Character.toLowerCase(tmp[right--]))
                return false;
        
        }
        return true;
   } 
   
   public boolean isalpha(char tmp){
       if(tmp >= 'a' && tmp <= 'z')
         return true;
       if(tmp >= 'A' && tmp <= 'Z')
         return true;
       if(tmp >= '0' && tmp <= '9')
         return true;
         
        return false;     
   }
   
   
   
}
