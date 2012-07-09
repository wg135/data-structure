/*Given a 2D array, print it in spiral form.
*/
public class spiral{

  public static void spiralPrint(int[][] a){
    int m = a.length;
    int n = a[0].length;
    int k=0, l=0;
    int i;

    while(k<m && l<n){
      for(i=l; i<n; i++)
        System.out.printf("%d ", a[k][i]);    
      k++;

      for(i=k; i<m;i++)
        System.out.printf("%d ", a[i][n-1]);
      n--;
  
      if(k<m){
        for(i=n-1; i>=l; i--)
          System.out.printf("%d ", a[m-1][i]);
        m--;
      } 
   
      if(l<n){
        for(i=m-1; i>=k; i--)
          System.out.printf("%d ", a[i][l]);
        l++;
      }      
    }
      
  }

  public static void main(String[] args){
    int[][] a = {{1,  2,  3,  4,  5,  6},
                 {7,  8,  9,  10, 11, 12},
                 {13, 14, 15, 16, 17, 18}};
   spiralPrint(a);
  
  }
}
