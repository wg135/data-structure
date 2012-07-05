import java.util.*;

public class ch9_5{

  public static int search(String[] strings, String str, int first, int last){
    while(first <= last){
      while(first<=last &&strings[last] == "")
         --last;

      if(last < first)
        return -1;

      int mid = first + (last - first)/2;
      while(strings[mid] =="")
        ++mid;
    
      int r = strings[mid].compareTo(str);
      if(r == 0)
        return mid;
      if(r < 0)
        first = mid +1;
      else
        last = mid - 1;
    }  
    return -1;
  }

  public static int search(String[] strings, String str){
    if((strings == null)||(str ==null))
     return -1;
    if(str==""){
      for(int i=0; i<strings.length; i++){
	if(strings[i] == "")
          return i;
      }
      return -1;
    }
    return search(strings, str, 0, strings.length-1);
  }

  public static void main(String[] args){
    String[] str = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  System.out.print(search(str, "ball"));
  }


}
