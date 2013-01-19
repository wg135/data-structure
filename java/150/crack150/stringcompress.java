//compress the same characters in string
public class stringcompress{

  public static String compress(String str){
	int size = count_compress(str);
	if(size > str.length())
	  return str;
	
	StringBuffer buffer = new StringBuffer();
	char last = str.charAt(0);
	int count = 1;
	for(int i =0; i<str.length(); i++){
	  if(str.charAt(i) == last)
	    count++;	
	  else{
	    buffer.append(last);
	    buffer.append(count);
	    last = str.charAt(i);
	    count = 1;	
	  }
	}
	buffer.append(last);
	buffer.append(count);

	return buffer.toString();
	
  }

  public static int count_compress(String str){
	int size = 0;
	int count = 1;
	char tmp = str.charAt(0);

	for(int i = 1; i < str.length(); i++){
	  if(str.charAt(i) == tmp){
		count++;
	  }
	  else{
		tmp = str.charAt(i);
		size += 1 + String.valueOf(count).length();
	  	count = 1;
	  }
	}
	
 	size += 1 + String.valueOf(count).length();
	return size;
  }

  public static void main(String[] args){
	String str = "aabcccccaaa";
	System.out.printf("%s\n",compress(str));

  }
}
