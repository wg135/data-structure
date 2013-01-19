//check if two strings are permutation

public class permutation_two_string{

  public static boolean check(String str1, String str2){

	if(str1.length() != str2.length())
	  return false;
	
	int[] tmp = new int[256];
	for(int i=0; i<str1.length(); i++)
	  tmp[str1.charAt(i)]++;
	for(int i=0; i<str2.length(); i++)
	  tmp[str2.charAt(i)]--;

	for(int i=0; i<256; i++){
	 if(tmp[i] != 0)
	  return false;
	}
	return true;
  }
  
  public static void main(String[] args){

	String str1 = "abcd";
	String str2 = "bcda";
 	if(check(str1, str2))
	  System.out.printf("yes\n");
  }
}

