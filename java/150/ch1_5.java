public class ch1_5{

  public static char[] replace(char[] str){
    int len = str.length;
    int i;
    int cnt = 0;
    int newcnt = 0;    

    for(i=0; i<len; i++)
      if(str[i] == ' ')
        cnt++;
  
    newcnt = len + 2*cnt;
    char str1[] = new char[newcnt];
    
    for(i=len-1; i>=0; i--){
      if(str[i] == ' '){
        str1[--newcnt] = '0';
        str1[--newcnt] = '2';
        str1[--newcnt] = '%';
      }
      else{
        str1[newcnt-1] = str[i]; 
        newcnt = newcnt-1;
       }
    }
    return str1;
  }
  public static void main(String[] args){
    String str = "hello hello hello";
    char[] str1 = str.toCharArray();
    
    System.out.println(replace(str1)); 
  }
}
