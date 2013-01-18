//Reverse Words In Phrase
public class  ReversePhrase {

  public static String reverse_word(String str){
	if(str == null)
	  return null;
	if(str.length() == 0)
	  return "";
	
	char[] tmp = str.toCharArray();
	reverse(tmp, 0, tmp.length - 1);

	int word_count = 0;
	for(int i = 0; i < tmp.length; i++){
	  if(tmp[i] == ' '){
	    reverse(tmp, word_count, i-1);
	    word_count = i + 1;
	  }
 	  else if(i == tmp.length -1)
	   reverse(tmp, word_count, i);
	}
	
	String result = new String(tmp);
	return result;
  }

  public static void reverse(char[] tmp, int start, int end){
	if(start >= end)
	  return;
	char p;
	for(int i = start; i<((end - start) / 2 + start); i++){
	   p = tmp[i];
	   tmp[i] = tmp[start + end - i];
	   tmp[start + end - i] = p;
   	}
  }

  public static void main(String[] args){
	String str = "Hello World";
	System.out.printf("%s\n", reverse_word(str));
  }
}
