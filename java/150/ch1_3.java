public class ch1_3{

  public static char[] del_dup(char[] str){
    int end = 1;
    int i, j;
    int k = 0;
    int len = str.length;

    if(str == null)
      return str;
    if(len < 2)
      return str;

    for(i=1; i<len; i++){
      for(j=0; j<end; j++){
 	if(str[i] == str[j]){
          k++;
          break;
        }
        
      }
      if(j == end){
        str[end] = str[i];
        ++end;
      }
    
    }
    for(i=0; i<k; i++)
      str[len-i-1] = 0;
    return str;
  }

  public static void main(String[] args){
    
    String str = "abcdeeeeeeeeeeeeeeeeeeeeeeeee";
    char[] str1 = str.toCharArray();
    str1 = del_dup(str1);
    System.out.println(str1);
  }
}
