public class ch9_1{

  public static void merge(int[] a, int[] b, int lena){
   
    int k = lena + b.length-1;
    int i = lena - 1;
    int j = b.length - 1;
  
    while((i>=0)&&(j>=0)){
      if(a[i] > b[j])
        a[k--] = a[i--];
      else
        a[k--] = b[j--]; 
    }
    while(j>=0)
       a[k--] = b[j--];  
  }

  public static void main(String[] args){

    int[] a = new int[10];
    int[] b = {2, 4, 6, 8, 10};
    for(int i=0; i<5; i++)
     a[i] = 1+ 2*i;

  merge(a, b, 5);
  for(int i=0; i<10; i++)
    System.out.printf("%d ", a[i]);

  }
}
