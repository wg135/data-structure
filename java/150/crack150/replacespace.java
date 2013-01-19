//repace space with %20 in string
public class replacespace{

  public static void  replace(char[] array, int length){
	int space_count = 0;
	for(int i=0; i<length; i++)
	  if(array[i] == ' ')
	    space_count++;

	int new_length = length + 2 * space_count;
	for(int i = length-1; i>= 0; i--){
	  if(array[i] == ' '){
	    array[--new_length] = '0';
	    array[--new_length] = '2';
	    array[--new_length] = '%';
	  }
	  else
	    array[--new_length] = array[i];
        }

  }
  public static void main(String[] args){

	String str = "hello world hello";
	char[] array = new char[22];
	for(int i=0; i<str.length(); i++)
	  array[i] = str.charAt(i);
        replace(array, 17);
	for(char tmp : array)	  
	  System.out.printf("%c ", tmp);
  }
}
