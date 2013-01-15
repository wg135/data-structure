//	Verify Rotated Palindrome
public class VerityRotatePalindrome{

  public static boolean check_roate(String str){
    for(int i=0; i<str.length(); i++){
	String left = str.substring(0, i);
        String right = str.substring(i);

        if(ispalind(right + left))
	  return true;
    }
    return false;
  }

  public static boolean ispalind(String str){

   char[] tmp = str.toCharArray();
   for(int i=0; i<=tmp.length/2; i++){
	if(tmp[i] != tmp[tmp.length-1 - i])
		return false;
   }
   return true;
  }

  public static void main(String[] args){
	
	String str = "112";
        if(check_roate(str))
	  System.out.printf("yes\n");
  }
}
