public class ch1_7{

  public static void change(int[][] matrix){
    int row[] = new int[matrix.length];
    int col[] = new int[matrix[0].length];
    int i, j;

    for(i=0; i<matrix.length; i++){
      for(j=0; j<matrix[0].length; j++){
        if(matrix[i][j] == 0){
 	  row[i] = 1;
          col[j] = 1;
        }
      }
    }
  
   for(i=0; i<matrix.length; i++){
     for(j=0; j<matrix[0].length; j++){
       if((row[i] ==0)||(col[j] ==0))
          matrix[i][j]=0;
     }
   }

  }
  public static void main(String[] args){
    int matrix[][] = {{1, 1, 1}, {1, 1, 0}, {1, 1, 1}};
    change(matrix);
    
  }
}
