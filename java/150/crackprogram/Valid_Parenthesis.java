//Print Valid Parenthesis Combinations
import java.util.*;

public class Valid_Parenthesis{

  public static ArrayList<String> parenthesis(int n){
    ArrayList<String> result = new ArrayList<String>();
    char[] tmp = new char[2*n];
    if(n <= 0)
	return null;
    else
	parenthesis_util(n, n, result, tmp, 0);
  
    return result;
  } 
 
  public static void parenthesis_util(int left, int right, ArrayList<String> result, char[] tmp, int count){
    if(left < 0)
	return;
    if((left == 0)&&(right == 0)){
	String s = new String(tmp);
	result.add(s);
	count = 0;
    }
    else{
	if(left > 0){
          tmp[count] = '(';
	  parenthesis_util(left-1, right, result, tmp, count+1);
        }
       if(right > left){
	  tmp[count] = ')';
          parenthesis_util(left, right-1, result, tmp, count+1);
       }
    }
	
  } 

  public static void main(String[] args){
	ArrayList<String> result = new ArrayList<String>();
	result = parenthesis(3);
	for(String s : result){
		System.out.printf("%s\n", s);
        }
        
  }
}
