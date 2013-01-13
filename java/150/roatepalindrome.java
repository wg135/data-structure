//Verify if a char string a rotated palindrome 
public class roatepalindrome{

  public static boolean ispalindrome(String str){
    if(str == null)
     return false;
    char[] array = str.toCharArray();
    for(int i=0; i<array.length/2; i++){
	if(array[i] != array[array.length-i-1])
	  return false;
    }
    return true;
  }

  public static boolean isroate(String str){
    for(int i = 0; i < str.length(); i++){
      String left = str.substring(0, i);
      String right = str.substring(i);
      String last = right + left;
      if(ispalindrome(last))
	return true;
    }
    return false;
  }

  public static void main(String[] args){
    String str = "112";
    if(isroate(str))
      System.out.printf("yes\n");
  }
}
