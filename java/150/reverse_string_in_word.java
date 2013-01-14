//Reverse Words In Phrase Without Additional Memory 

public class reverse_string_in_word{

  public static void reverse(char[] c){
    reverse(c, 0, c.length-1);
    int word_count = 0;
    for(int i=0; i<c.length; i++){
      if(c[i] == ' '){
	reverse(c, word_count, i-1);
        word_count = i+1;
      }
      else if(i == c.length-1)//last word without ' '
	reverse(c, word_count, i);
    }
  }

  public static void reverse(char[] c, int start, int end){
    if(start > end)
	return;
    char tmp;
    for(int i=start; i<=(start + (end-start)/2); i++){
       tmp = c[i];
       c[i] = c[end + start- i];
       c[end + start -i] = tmp;
     }
  }

  public static void main(String[] args){
    String str = "Hello World Friend";
    char[] p = str.toCharArray();
    reverse(p);
    String s = new String(p);
    System.out.printf("%s\n", s);
    
  }
}
