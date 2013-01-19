//check if a string has all unique character

public class all_unique_character{


  public static boolean alluniq(String str){
	if(str.length() > 256)
	  return false;

	boolean[] check = new boolean[256];
	for(int i=0; i<str.length(); i++){
	  int value = str.charAt(i);
	  if(check[value] == true)
	    return false;
	  else
	    check[value] = true;
	}
	return true;
  }  

  public static void main(String[] args){
	String str = "abcdefgg";
	if(!alluniq(str))
	  System.out.printf("not unique\n");
  }
}
