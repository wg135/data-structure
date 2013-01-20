//set the row and col to zero when there is element is zero in that position
public class set_zero_matrix{

  public static void set_zero(int[][] a){
	if(a == null)
	  return;
	int[] row = new int[a.length];
	int[] col = new int[a[0].length];
	
	for(int i=0; i<a.length; i++){
	  for(int j=0; j<a[0].length; j++){
	    if(a[i][j] == 0){
	      row[i] = 1;
	      col[j] = 1;
	    }
	  }
	}

	for(int i=0; i<a.length; i++)
	  for(int j=0; j<a[0].length; j++){
	    if((row[i] == 1) || (col[j] == 1))
	      a[i][j] = 0;
	  }  
  }

  public static void main(String[] args){
    int[][] a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 7, 8}, {7, 2, 0, 1}};
    set_zero(a);
  
    for(int i=0; i<a.length; i++){
	for(int j=0; j<a.length; j++)
	   System.out.printf("%d ", a[i][j]);
	System.out.printf("\n");
    }			
  }
}
