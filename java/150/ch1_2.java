public class ch1_2{

  public static String reverse(String str){
   
    char tmp;
    int i;
    String result = "";

    if((str == null)||(str.length() == 0))
      return null;
    
    i = str.length()-1;

    while(i>=0){
      result = result + str.charAt(i);
      i--;
    }     
    
   return result; 
  }

  public static void main(String[] args){
    String str = "hello world";
    String result;
    result = reverse(str);
    System.out.print(result + "\n");
  }
}
