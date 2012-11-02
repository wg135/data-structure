public class ch1_3a{

  public static char[] deldup(char[] str){
    int last = 1;
    int i, j;
    int k = 0;
    
    if(str == null)
     return null;
 
    int len = str.length;
    if(len < 2)
      return str;

    for(i=1; i<len; i++){  //loop all the char that not check
      for(j=0; j<last; j++){    //from the beginning to the last checked 
        if(str[j] == str[i]){   //find the same char, break
          k++;
          break;
        }
      }
      if(j == last)     //if it is the last one, none of them same as the str[i]
       str[last++] = str[i]; //so we add str[i]
    } 
    for(i=0; i<k; i++)
      str[len-i-1] = 0;
    
    return str;
  }

  public static void main(String[] args){
    String str = "abcdeeeeeeeeeeeeeeeeeeeeeeeeef";
    char[] str1 = str.toCharArray();
    str1 = deldup(str1);
    System.out.println(str1);
  }
}
