//check if string1 is rotate of string 2

public class string_rotate{

  public static boolean rotate(String str1, String str2){
	String s = new String();
	if((str1 == null)&&(str2 == null))
	  return true;
	else
	  s = str1 + str1;
	if(issubstring(s, str2))
	  return true;
	else
	  return false;
  }

  public static boolean issubstring(String str1, String str2){
	if(str1.length() < str2.length())
	  return false;
	
	int count = 0;
        for(int i=0; i<(str1.length()-str2.length()); i++){
	  for(int j=0; j<str2.length(); j++){
		if(str1.charAt(i+j) == str2.charAt(j)){
	          count++;
	        }
	        else{
		  count = 0;
		  break;
		}
	  }
	}	
	if(count == str2.length())
	  return true;
	else
	  return false;	
  }

  public static void main(String[] args){
	String str1 = "xy";
	String str2 = "yx";

	if(rotate(str1, str2)){
	   System.out.printf("yes\n");
	}
  }
}
