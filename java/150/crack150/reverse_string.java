
//reverse a string
public class reverse_string{

  public static String reverse(String str){
    if(str.length() <= 1)
	return str;
    	
    return reverse(str.substring(1)) + str.charAt(0);	
  }

  public static void main(String[] args){
    String str = "hello world";

    System.out.printf("%s\n", reverse(str));	
  }
}
