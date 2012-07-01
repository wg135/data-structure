public class ch8_1{

  public static int fibb(int n){
    if(n<=0)
      return 0;
    if(n == 1)
      return 1;
    else
      return fibb(n-1)+fibb(n-2);
  }

  public static int fibb_dp(int n){
    int[] lookup = new int[n+1];
    lookup[0] = 0;
    lookup[1] = 1;
    int i;
    for(i=2; i<=n; i++)
     lookup[i] = lookup[i-1]+ lookup[i-2];

    return lookup[n];
 }

  public static void main(String[] args){
    int n = 15;
    System.out.println(fibb(n));
    System.out.println(fibb_dp(n));
  }
}

