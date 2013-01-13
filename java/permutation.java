import java.util.*;

public class  permutation{

  
  public static ArrayList<String> getper(String str){
    ArrayList<String> result = new ArrayList<String>();
    if(str == null)
      return result;
    if(str.length() == 0){
      result.add("");
      return result;
     }

    char tmp = str.charAt(0);
    String sub = str.substring(1);
    ArrayList<String> words = getper(sub);
    for(String word : words){
      for(int i=0; i<=word.length(); i++){
        String s = stringinsert(word, i, tmp);
        result.add(s);
      }
    }
    return result;
  }

  public static String stringinsert(String word, int i, char tmp){
    String start = word.substring(0, i);
    String end = word. substring(i);
    return start + tmp + end;
  }

  public static void main(String[] args){
    String str = "abc";   
    for(String s : getper(str))
      System.out.printf("%s\n", s); 
  }
}
