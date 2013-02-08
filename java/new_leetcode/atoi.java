public class Solution {
    public int atoi(String str) {
        // Start typing your Java solution below
        // DO NOT write main() function
        str = str.trim();
        long value = 0;
        boolean ispositive = true;
        boolean hasnumber = false;
        
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '+' || str.charAt(i) == '-'){
                if(i==0){
                    if(str.charAt(i) == '-')
                      ispositive = false;
                }else
                  return 0;
              continue;
            }
            
            if(str.charAt(i) < '0' || str.charAt(i) > '9')
                break;
            hasnumber = true;
            value = 10 * value + str.charAt(i) - '0';
        }
        
        if(hasnumber){
            value = ispositive == true? value : value * -1;
            
            if(value < -2147483648)
              return -2147483648;
            else if(value > 2147483647) 
              return 2147483647;
            else return (int)value;  
        }
        
        return 0;
    }
}
