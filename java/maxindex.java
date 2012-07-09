/*Given an array arr[], find the maximum j – i such that arr[j] > arr[i].
*/

public class maxindex{
  
  public static int index1(int[] a){
     int i, j;
     int max = 0;
     for(i=0; i<a.length; i++){
       for(j=i+1; j<a.length; j++){
	  if((a[i]<a[j])&&(max < (j-i)))
              max = j - i;
        }
     }
     return max;
  }

  public static int index2(int[] a){
    int i, j;
    int max = -1;
    int[] tmp1 = new int[a.length];
    int[] tmp2 = new int[a.length];
   
    tmp1[0] = a[0];
    for(i=1; i<a.length; i++)
      tmp1[i] = Math.min(a[i], tmp1[i-1]); 
    
    tmp2[a.length-1] = a[a.length-1];
    for(i=a.length-2; i>=0; i--)
      tmp2[i] = Math.max(a[i], tmp2[i+1]);
    
    i=0;
    j=0;
    while(i<a.length && j<a.length){
      if(tmp1[i]<tmp2[j]){
        max = Math.max(max, j-i);
        j++;
      }
      else{
        i++;
      }
    }
    return max;
  }

  public static void main(String[] args){
   int[] a = {34, 8, 10, 3, 2, 80, 30, 33, 1};
   System.out.println(index1(a));
   System.out.println(index2(a));
  }
}
