import java.util.*;

public class ch9_6{

  public static boolean check(int[][] ma, int value){
    int row = 0;
    int col = ma[0].length-1;

    while(row<ma.length && col>=0){
      if(ma[row][col] == value)
        return true;
      else if(ma[row][col] > value)
        --col;
      else if(ma[row][col] < value)
        ++row;
    }
    return false;
  }
  public static void main(String[] args){
    int[][] ma= {{0,1,2,3}, {1, 2, 3, 4}, {2, 3, 4, 5}};
    if(check(ma, 6))
      System.out.println("yes");
    else
      System.out.println("no");
  }
}

