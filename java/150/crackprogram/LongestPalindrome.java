//	Find Longest Palindrome in String
import java.util.*;
public class LongestPalindrome{

  public static String longest(String str){
	char[] tmp = str.toCharArray();
	int longest_end = 0;
	int longest_start = 0;

        int start = 0;
	int end;
  
	for(start=0; start< str.length(); start++){
	  for(end = start+1; end <=str.length(); end++)
		if(ispalindrome(tmp, start, end-1)){//because substring(begin, end), end is exclusive
		  if((longest_end - longest_start) < (end - start)){
			longest_end = end;
			longest_start = start;
		  }		
		}
	}

     return str.substring(longest_start, longest_end);
  }

  public static boolean ispalindrome(char[] tmp, int start, int end){
    for(int i = start; i<=(start + (end-start)/2); i++){
	if(tmp[i] == tmp[end + start - i])
	  continue;
	else
	  return false;
    }

    return true;	
  }

  public static void main(String[] args){
	String in = "5123443218";//expected longest palindrome is "1234321"
	System.out.printf("%s\n", longest(in));
  }
}
