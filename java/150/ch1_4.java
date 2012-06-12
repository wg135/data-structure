public class ch1_4{

  public static boolean anagrams(String str1, String str2){
    int table[] = new int[256];
    int i;
    int len1 = str1.length();
    int len2 = str2.length();
    if(str1.length() != str2.length())
      return false;
    for(i=0; i<len1; i++)
      table[(int)str1.charAt(i)] += 1;
    for(i=0; i<len2; i++)
      table[(int)str2.charAt(i)] -= 1;
    
    for(i=0; i<256; i++){
      if(table[i] != 0)
        return false;
    }
    return true;
         
  }

  public static void main(String[] args){
   String str1 = "abcd";
   String str2 = "aa";
  
  if(anagrams(str1, str2))
    System.out.println("yes");
  else
    System.out.println("no"); 
  }
} 
