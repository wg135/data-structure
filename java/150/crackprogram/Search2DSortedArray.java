//Search in 2D Sorted Array
public class Search2DSortedArray{

  public static void find_k(int[][] sorted, int k){
	int x = sorted.length-1;   //row length
	int y = 0;

       	
       while((x>=0) && (y< sorted[0].length)){
		if(sorted[x][y] == k){
			System.out.printf("get result at sorted[%d][%d]\n", x, y);
			return;
		}		
		if(sorted[x][y] < k)
			y++;
		else
			x--;
			
       }

      System.out.printf("cannot find in sorted[][]\n");	
  }

  public static void main(String[] args){
	int[][] sorted = {{1,4,5}, 
			 {2,6,7},
		         {3,8,9}};

	find_k(sorted, 5);

  }
  
  
}
