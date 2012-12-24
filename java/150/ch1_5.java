public class ch1_5{

  public static char[] replace(char[] str, int length){
    int i;
    int cnt = 0;
    int newcnt = 0;    

    for(i=0; i<length; i++)
      if(str[i] == ' ')
        cnt++;
  
    newcnt = length + 2*cnt;
    str[newcnt] = '\0';
    
    for(i=length-1; i>=0; i--){
      if(str[i] == ' '){
        str[--newcnt] = '0';
        str[--newcnt] = '2';
        str[--newcnt] = '%';
      }
      else{
        str[newcnt-1] = str[i]; 
        newcnt = newcnt-1;
       }
    }
    return str;
  }
  public static void main(String[] args){
    String str = "hello hello hello";
    char[] str1 = new char[256];
    int i;
    for(i=0; i<str.length(); i++)
      str1[i] = str.charAt(i); 
    System.out.println(replace(str1, 18)); 
  }
}
