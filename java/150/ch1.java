public class ch1{

  public static boolean isunique(String str){
    
    boolean[] set = new boolean[256];
    for(int i=0; i<str.length(); i++){
      int tmp = str.charAt(i);
      if(set[tmp] == true)
        return false;
      set[tmp] = true;
    }
    return true;
  }

  public static void main(String[] args){
   
    String str1 = "abcd";
    String str2 = "aaaa";
    if(isunique(str1))
      System.out.print(str1 + "\n");
    if(isunique(str2))
      System.out.print(str2 + "\n");
  }
 
}
