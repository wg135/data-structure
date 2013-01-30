import java.util.*;

public class Solution {
public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Character> stack = new Stack<Character>();
        
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c == '(' || c == '{' || c == '[')
                stack.push(c);
            else{
                if(stack.size() == 0)
                    return false;
                char top = stack.peek();
                if(c == ')'){
                    if(top != '(')
                        return false;
                }
                else if(c == '}'){
                    if(top != '{')
                        return false;
                }
                else if(c == '}'){
                       if(top != '[')
                         return false;
                }
                stack.pop();
            }    
           
        }
       return stack.size() == 0; 
    }
}
