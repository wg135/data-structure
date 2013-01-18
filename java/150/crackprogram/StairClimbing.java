
public class StairClimbing{

  public static int stair_re(int steps){
	if(steps <= 0)
	  return 0;
	if(steps == 1)
	  return 1;
	if(steps == 2)
	  return 2;
	if(steps == 3)
	  return 4;
	
	else
	  return stair_re(steps - 3) + stair_re(steps - 2) + stair_re(steps - 1);		
  }

  public static int stair_dp(int steps){
	int[] tmp = new int[steps + 1];
        tmp[0] = 0;
	tmp[1] = 1;
	tmp[2] = 2;
	tmp[3] = 4;
	for(int i = 4; i<= steps; i++)
	  tmp[i] = tmp[i-3] + tmp[i-2] + tmp[i-1];

         return tmp[steps];
	
  }

  public static void main(String[] args){

	System.out.printf("%d\n", stair_re(5));
	System.out.printf("%d\n", stair_dp(5));
   
  }
}
