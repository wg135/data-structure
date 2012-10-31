public class ch1_1{

  public static boolean isrepeat(String s){ 
    boolean[] check = new boolean[256];
    int i;

    for(i=0; i<s.length(); i++){
      int val = s.charAt(i);
      if(check[val] == true)
        return false;
      check[val] = true;
    } 
    return true;
  }
  
  public static void main(String[] args){
    String s1 = new String("abcdefg");
    String s2 = new String("abcdefga"); 
    if(isrepeat(s1))
      System.out.printf("yes\n");
   
       
  }
}
